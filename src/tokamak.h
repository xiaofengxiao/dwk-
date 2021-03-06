#ifndef TOKAMAK_H
#define TOKAMAK_H

int const nqc =8;
int const nrc =9;
typedef struct TOKAMAK
{
	double a,R0;	//minor and major radius (m). 			input
	double eps;	//a/R0	  
	double C; 	//the normalization coefficient for dispersion relation
	double dwk_001;   // dwk_0 (SI unit) with beta_h = 1.0% .
	double qc[nqc];   //q profile, polynomial coefficient;      	input
	double s;	//magnetic shear at resonance surface.
	double q_s;	//q at resonance surface 
	double r_s;	//resounce surface (a)
	double Bt;	//toroidal magnetic field at axis without plasma, in units of tesla  input
	double PB;	//magnetic field pressure in SI unit.
	double Bps;	//poloidal magnetic field at resonance surface.
	double n0;	//thermal plasma density at axis.		input
	double mi;	//ion mass in units of protom mass.		input
	double m_ep;	//fast ion mass, in units of protom mass.	input
	double rho_m;   //mass density   (kg/m^3)
	double E_i0;	// fast ion injection energy, in units of KeV	input
	double v_A,omega_A; 
	double tau_At; // tau_{A,theta}
	double v_i0,omega_i0;
	double beta_h; 
	double beta_hb;
	int 	nbeta;
	double omega_c; //gyro fre
	
	
}Tokamak;

typedef struct GRID
{
	int nx,nL,nE,ntheta;
	double ra,rb,dr;
	double La,Lb,dL;
	double Ea,Eb,dE;
	double dtheta;
	double *xarray,*Larray,*Earray,*tarray;
	
}Grid;

typedef struct SLOWING
{
	int rflag;
	double  rd,r0;
	double  rc[nrc];
	double  L0,Ld;
        double 	E0,Ed,Ec;
	double rho_h;
	double rho_d;
	int sigma;
}
Slowing;



class CGrid
{
public:
	CGrid();
	CGrid(Grid *pgrid,Slowing *slowing);
	~CGrid();
	Grid * m_pgrid;
	void showgrid();
private:
	double *xarray,*Larray,*Earray,*tarray;
	
};


void showtokamak(Tokamak *ptok,Slowing *pslowing);

void qprofile(Grid *const grid,Tokamak *ptok, double *q_1D);

double bf(const Tokamak *tok,const double theta, const double r);
void J_q(Grid *const grid,double *const q_1D, double *J_q);

void find_rs(Grid * const grid,double *const q_1D, Tokamak *ptok);


#endif


