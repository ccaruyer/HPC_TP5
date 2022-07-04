#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000000000
#define r 1
#define PI 3.141592653589793238462643

int isCircle(double x,double y){
    double p = (double) pow(x,2) + pow(y,2);
    //printf("%lf\n",p);
    if(p < pow(r,2)){
        return 1;
    }
    return 0;
}

double generateRandomNumber(){
    return (double)rand() / ( RAND_MAX / 2) - 1;
}

void main() {
    int I = 0;
    double P;
    for(int n=0; n<N;n++) {
        double x = (double)generateRandomNumber();
        double y = (double)generateRandomNumber();

        if(isCircle(x,y) == 1){
            I = I+1;
            //printf("(%lf,%lf) est dans le cercle\n",x,y);
        }/*else{
            printf("(%lf,%lf) est hors du cercle\n",x,y);
        }*/
        P = (double) I/N;
        double p_text = (double) (P - PI);
        if( p_text >= 0.000001){
            break;
        }
    }
    printf("Il y a %d point(s) dans le cercle sur %d points\n",I,N);

    printf("P = %lf\n",P);
}
