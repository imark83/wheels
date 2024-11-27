#include <stdio.h>
#include <stdlib.h>
#include <math.h>



double mapPhi(double phi, double phiL, double phiR) {
  double a = phiR - phiL;
  while(phi<phiL) phi+=a;
  while(phi>phiR) phi-=a;
  return phi;
}


int main(int argc, char const *argv[]) {
  int nP = 5;               // number of armonics (petals)
  int n = 1000;              // points per wheel
  double scale = 1.0;      // scale
  double alpha = M_PI/6;  // steep of stair
  double phi;               // angle for wheel
  double basePhi;           // maped angle for 4th-1st half-petal
  double r;                 // radius;
  double t;                 // parametric parameter

  int i;                    // counter for points in wheel
  int k;                    // counter for petals



  double phiR = (2.0*M_PI*sin(alpha)*sin(alpha))/nP;
  double phiL = phiR - (2.0*M_PI)/nP;
  double a = 1.0/(exp((M_PI*sin(2.0*alpha))/nP)-1);
  double b = tan(alpha);
  double petalArc = (2.0*M_PI)/nP;



  for(i=0;i<n;i++) {
    phi = (2.0*M_PI*i)/(n-1.0);
    basePhi = mapPhi(phi,0.0,petalArc) + phiL;
    if(basePhi<0)
      r=scale*exp(-b*basePhi)/(exp((M_PI*sin(2.0*alpha))/nP)-1.0);
    else
      r=scale*exp(basePhi/b)/(exp((M_PI*sin(2.0*alpha))/nP)-1.0);
    
    fprintf(stdout, "%i, %f, %f\n", i+1, r*cos(phi),r*sin(phi));
    // fprintf(stdout, "%f, %f\n", r*cos(phi),r*sin(phi));
  }

  return 0;
}