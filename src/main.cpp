#include<fstream>
#include<iostream>
#include<math.h>
#include<ctime>
#include<complex>

#include"vector.h"
#include"AllocArray.h"
#include"tokamak.h"
#include"readinput.h"
#include"dist.h"
#include"mode.h"
#include"particle_fre.h"
#include"dwk.h"

using namespace std;
int main(int arg,char * argx[])
{	
	clock_t c_start=clock();
	if(cmdOptionExists(argx, argx+arg, "-h"))//print help information only
	{
		help();
		return 0;
	}
	char default_ifilename[]="dwk.cfg";
	char default_ofilename[]="omega_dwk.out";
	char *ifilename =getCmdOption(argx,argx+arg,"-i");
	char *ofilename =getCmdOption(argx,argx+arg,"-o");

	if(ifilename==0)
		ifilename=default_ifilename;
        if(ofilename==0)
                ofilename=default_ofilename;
	
	Tokamak tok;
	Grid 	grid;
	Slowing slowing;
	Mode mode;
//read input parameters
	read_tokamak(ifilename,&tok,&grid,&slowing,&mode);	
	CGrid pgrid(&grid,&slowing);
 	cout.precision (12);
	pgrid.showgrid();	
//alloc memory
	double *q_1D,*J_q_1D;
	Alloc1D(q_1D,grid.nx);
	Alloc1D(J_q_1D,grid.nx);
	double **Chi_2D, **K_2D,**kappa_2D;	
	complex<double> ***G_3D;
	Alloc3D(G_3D,grid.nx,grid.nE,grid.ntheta);

	Alloc2D(Chi_2D,grid.nx,grid.nL);
	Alloc2D(K_2D,grid.nx,grid.nL);
	Alloc2D(kappa_2D,grid.nx,grid.nL);
	double *** omega_b_3D,***omega_phi_3D,*** tau_b_3D;
	Alloc3D(omega_b_3D,grid.nx,grid.nL,grid.nE);
	Alloc3D(omega_phi_3D,grid.nx,grid.nL,grid.nE);
	Alloc3D(tau_b_3D,grid.nx,grid.nL,grid.nE);
	double ***F_3D,***FE_3D,***FR_3D, ***omega_star_3D;
	Alloc3D(F_3D,grid.nx,grid.nL,grid.nE);
	Alloc3D(FE_3D,grid.nx,grid.nL,grid.nE);
	Alloc3D(FR_3D,grid.nx,grid.nL,grid.nE);
	Alloc3D(omega_star_3D,grid.nx,grid.nL,grid.nE);
	double *** lambda_b_3D, ***b_lambda_3D, ***Theta_3D;
	Alloc3D(lambda_b_3D,grid.nx,grid.nL,grid.ntheta);
	Alloc3D(b_lambda_3D,grid.nx,grid.nL,grid.ntheta);
	Alloc3D(Theta_3D,grid.nx,grid.nL,grid.ntheta);
	complex<double> ***dwk_3D;
	Alloc3D(dwk_3D,grid.nx,grid.nL,grid.nE);
//end alloc memory

//begin calculate non-omega parts------------------------
	qprofile(&grid,&tok,q_1D);
	find_rs(&grid,q_1D, &tok);
	calculate_normalization(&tok, &slowing);
	showtokamak(&tok,&slowing);
	F0_3D(&slowing,&grid,&tok,slowing.rho_h,mode.m,F_3D,FE_3D,FR_3D,omega_star_3D);	
	Lambda_b_L_3D(&grid,&tok,lambda_b_3D,b_lambda_3D);
	Theta(b_lambda_3D,&grid,Theta_3D);
	G_R_theta(&grid,&tok,&slowing,&mode,q_1D,G_3D); 
	Chi(&grid,&tok,slowing.sigma,Chi_2D,kappa_2D,K_2D);	
	omega_b(&grid, &tok,kappa_2D, K_2D, q_1D,omega_b_3D);
	omega_phi(&grid,q_1D,omega_b_3D,omega_phi_3D);

	tau_b(&grid,omega_b_3D,tau_b_3D);
	J_q(&grid,q_1D,J_q_1D);
//end calculate non-omega parts--------------------------	

	complex<double> *dwk_array;
	Alloc1D(dwk_array,mode.omega_n);
	
	if(cmdOptionExists(argx,argx+arg,"-s"))
        {
		cout<<"*********************************"<<endl;
		cout<<"scan dwk(omega)"<<endl;
                dwk_omega_array(&grid, &mode, omega_phi_3D, omega_b_3D, tau_b_3D,
                        J_q_1D, FE_3D, omega_star_3D,
                        G_3D,Chi_2D,b_lambda_3D,lambda_b_3D,Theta_3D,
                        dwk_array,ofilename);
		cout<<"outputfile: "<<ofilename<<endl;
		cout<<"end scan"<<endl;
		cout<<"*********************************"<<endl;
        }

	cout<<"*********************************"<<endl;
	cout<<"this is a test run "<<endl;
	complex<double> omega_0,dwk_0;
	omega_0= find_dwk_omega0(&grid,&mode,&tok,omega_phi_3D,omega_b_3D,tau_b_3D,
			J_q_1D,FE_3D,omega_star_3D,
			G_3D,Chi_2D,b_lambda_3D,lambda_b_3D,Theta_3D,&dwk_0);
	tok.beta_h = real(omega_0)/(imag(dwk_0)*tok.C);
	cout<<"beta_h is:"<<tok.beta_h<<endl;
	complex<double> err=0;
	complex<double> ti =1.0i;
	err =ti*omega_0 -tok.C*tok.beta_h*dwk_0;
	cout<<scientific;
	cout<<"error=i*omega_0 -C*beta_h *dwk(omega_0)= "<<err<<endl;
	cout<<fixed;
	cout<<"*********************************"<<endl;
	
	for(int gi=0;gi<mode.max_iterg;gi++)
	{
		cout<<"*********************************"<<endl;
		cout<<"find the solution"<<endl;
		omega_0= find_dwk_omega0(&grid,&mode,&tok,omega_phi_3D,omega_b_3D,tau_b_3D,
                        J_q_1D,FE_3D,omega_star_3D,
                        G_3D,Chi_2D,b_lambda_3D,lambda_b_3D,Theta_3D,&dwk_0);
        	tok.beta_h = real(omega_0)/(imag(dwk_0)*tok.C);
        	cout<<"beta_h is:"<<tok.beta_h<<endl;
		err =ti*omega_0 -tok.C*tok.beta_h*dwk_0;
		cout<<scientific;
        	cout<<"error=i*omega_0 -C*beta_h *dwk(omega_0)= "<<err<<endl;
		cout<<fixed;
        	cout<<"*********************************"<<endl;
		if(abs(err)<mode.omega_err*tok.C*tok.beta_h)
			break;
	}
	cout<<"      omega_0"<<"\t\t\t\t"<<"dwk"<<"\t\t\t beta_h"<<endl;
	cout<<real(omega_0)<<"+"<<imag(omega_0)<<"i \t"<<real(dwk_0)<<"+"<<imag(dwk_0)<<"i\t"<<tok.beta_h<<endl;	
	cout <<"in omega_A unit"<<endl;
	cout <<"     omega_0:"<<omega_0*tok.omega_i0/tok.omega_A<<endl;
	cout <<"in kHz unit" <<endl;
	cout <<"     omega_0:"<<omega_0*tok.omega_i0/2.0/M_PI/1000.0 <<endl;
	cout<<"*************************************************************"<<endl;

	Free1D(dwk_array);	
	Free1D(J_q_1D);		Free1D(q_1D);
        Free2D(Chi_2D); 	Free3D(G_3D);
        Free2D(kappa_2D);	Free2D(K_2D);
	Free3D(dwk_3D); 	Free3D(tau_b_3D);
	Free3D(omega_phi_3D);	Free3D(omega_b_3D);
	Free3D(Theta_3D);
	Free3D(b_lambda_3D);	Free3D(lambda_b_3D);
	Free3D(F_3D);		Free3D(FR_3D);	
	Free3D(FE_3D);		Free3D(omega_star_3D);
	cout<<"time:\t"<<float(clock() - c_start)/CLOCKS_PER_SEC<<endl;
}


