#ifndef DWK_H
#define DWK_H

#include<complex>

using namespace std;

complex<double> dwk(Grid *const grid, complex<double> const omega, int n,int p,
        double *** const omega_phi_3D, double ***const omega_b_3D, double *** tau_b_3D,
        double ** const Yp2_2D, double * const J_q_1D, double *** const F_E_3D, double *** const omega_star,complex<double> *** dwk_3D );
void dwk_omega_array(Grid *const grid,Mode *const mode,
        double *** const omega_phi_3D, double ***const omega_b_3D, double *** tau_b_3D,
        complex<double> ** const Yps_2D, double * const J_q_1D, double *** const F_E_3D,double *** const omega_star,
        complex<double> **const G_2D,double **const Chi_2D,double *** const b_lambda_3D, double *** const lambda_b_3D,
        double ***const Theta_3D,
        complex<double> * dwk_array,char const *filename);
complex<double> find_dwk_omega0(Grid *const grid,Mode *const mode,Tokamak *tok,
        double *** const omega_phi_3D, double ***const omega_b_3D, double *** tau_b_3D,
        complex<double> ** const Yps_2D, double * const J_q_1D, double *** const F_E_3D,
        double *** const omega_star,
        complex<double> **const G_2D,double **const Chi_2D,double *** const b_lambda_3D, double *** const lambda_b_3D,
        double ***const Theta_3D,complex<double> *dwk_0);
void help();
char* getCmdOption(char ** begin, char ** end, const std::string & option);
bool cmdOptionExists(char** begin, char** end, const std::string& option);


#endif