#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char const *argv[]) {
  int nSteps = 4;
  double scale = 1.0;
  double alpha = M_PI/6.0;
  double b = tan(alpha);
  int i, k;


  double y=0.0;

  int j=1;
  fprintf(stdout, "%i, 0.0, 0.0\n",j++);
  for(i=0; i<nSteps;i++) {
    y+=b*scale;
  	fprintf(stdout, "%i, %f, %f\n",j++, scale, y);
  	y+=scale/b;
  	fprintf(stdout, "%i, %f, %f\n",j++, 0.0, y);
  }
  	fprintf(stdout, "%i, %f, %f\n",j++, -scale*0.5, y);
  	fprintf(stdout, "%i, %f, %f\n",j++, -scale*0.5, 0.0);
  	fprintf(stdout, "%i, %f, %f\n",j++, 0.0, 0.0);


  return 0;
}