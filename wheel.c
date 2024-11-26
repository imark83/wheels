#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char const *argv[]) {
  double basePhi, phi, r;
  int nP = (argc>1)? atoi(argv[1]) : 5;
  int n = (argc>2)? atoi(argv[2]) : 100;
  double scale = (argc>3)? atof(argv[3]) : 40.0;
  int i, k;


  int j=0;
  for (k=0;k<nP;k++) {
    for (i=0;i<n;i++) {
      basePhi=(M_PI*i)/(1.0*nP*(n-1));
      phi=basePhi + (2*k*M_PI)/nP;
      // printf("%f\n", phi);
      r=scale*exp(basePhi)/(1-exp(M_PI/nP));
      fprintf(stdout, "%i, %f, %f, 0.0\n", ++j, r*cos(phi),r*sin(phi));
    }

    for (i=n-1;i>=0;i--) {
      basePhi=(M_PI*i)/(1.0*nP*(n-1));
      phi=(2.0*M_PI)/nP-basePhi + (2*k*M_PI)/nP;
      // printf("%f\n", phi);
      r=scale*exp(basePhi)/(1-exp(M_PI/nP));
      fprintf(stdout, "%i, %f, %f, 0.0\n", ++j, r*cos(phi),r*sin(phi));
    }
  }

  return 0;
}