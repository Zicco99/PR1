#include <stdio.h>
#include <math.h>
int modulodiff(float a,float b,float *c,float *d){
*c=a-b;
*d=b-a;
}

int main(){
float a,b,c,d;
scanf("%f",&a);
scanf("%f",&b);
modulodiff(a,b,&c,&d);
printf("%.2f\n",c);
printf("%.2f\n",d);
return 0;
}
