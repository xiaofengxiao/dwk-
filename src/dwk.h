#ifndef DWK_H
#define DWK_H

#include<complex>
#include"mode.h"
#include"particle_fre.h"
#include"vector.h"
#include"output.h"

using namespace std;

typedef struct DWKOPT
{
	int omega_star_off;
	int omega_off;
//	int zero_rhod;
	int adiabatic_i;
}Dwkopt;

void setdwk_parameters(Grid *const grid,Mode *const mode,Tokamak *tok,
        double *** const omega_phi_3D, double ***const omega_b_3D, double *** tau_b_3D,
         double * const J_q_1D, double *** const F_E_3D,
        double *** const omega_star,
        complex<double> ***const G_3D,double **const Chi_2D,double *** const b_lambda_3D, double *** const lambda_b_3D,
        double ***const Theta_3D,Dwkopt *pdwkopt);

void dwk_omega_array(Grid *const grid,Mode *const mode,Tokamak *tok,
        double *** const omega_phi_3D, double ***const omega_b_3D, double *** tau_b_3D,
        double * const J_q_1D, double *** const F_E_3D,double *** const omega_star,
        complex<double> ***const G_3D,double **const Chi_2D,double *** const b_lambda_3D, double *** const lambda_b_3D,
        double ***const Theta_3D,
        complex<double> * dwk_array,char const *filename,Dwkopt *pdwkopt);

complex<double> dwk_omega(Grid *const grid,Mode *const mode,Tokamak *tok,complex<double> omega,
        double *** const omega_phi_3D, double ***const omega_b_3D, double *** tau_b_3D,
         double * const J_q_1D, double *** const F_E_3D,
        double *** const omega_star,
        complex<double> ***const G_3D,double **const Chi_2D,double *** const b_lambda_3D, double *** const lambda_b_3D,
        double ***const Theta_3D,Dwkopt *pdwkopt);

complex<double> find_dwk_omega0(Grid *const grid,Mode *const mode,Tokamak *tok,
        double *** const omega_phi_3D, double ***const omega_b_3D, double *** tau_b_3D,
        double * const J_q_1D, double *** const F_E_3D,
        double *** const omega_star,
        complex<double> ***const G_3D,double **const Chi_2D,double *** const b_lambda_3D, double *** const lambda_b_3D,
        double ***const Theta_3D,complex<double> *dwk_0,Dwkopt *pdwkopt);
void help();
char* getCmdOption(char ** begin, char ** end, const std::string & option);
bool cmdOptionExists(char** begin, char** end, const std::string& option);

double dwf();
complex<double> tdwk_omega(complex<double> omega);
complex<double> tdw_omega(complex<double> omega);
extern complex<double> **** gYps_3D;

#endif
