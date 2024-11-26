#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char const *argv[]) {
  double basePhi, phi, r;
  int nP = (argc>1)? atoi(argv[1]) : 4;
  double scale = (argc>3)? atof(argv[2]) : 40.0;
  int i, k;


  double y=0.0;

  int j=0;
  fprintf(stdout, "%i, 0.0, 0.0\n",++j);
  for(i=0; i<nP;i++) {
  	fprintf(stdout, "%i, %f, %f\n",++j, scale, y+scale);
  	y+=2*scale;
  	fprintf(stdout, "%i, %f, %f\n",++j, 0.0, y);
  }
  	fprintf(stdout, "%i, %f, %f\n",++j, -scale*0.5, y);
  	fprintf(stdout, "%i, %f, %f\n",++j, -scale*0.5, 0.0);
  	fprintf(stdout, "%i, %f, %f\n",++j, 0.0, 0.0);


  return 0;
}