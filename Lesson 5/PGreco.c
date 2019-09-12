#include <stdio.h>
#include <math.h>
float approx_pi(int x){
int i;
float res=0;
for(i=0;i<x;i++){
res=res+(pow(-1,i)*4/(2*i+1));
}
return res;
}


int main(){
int x;
scanf("%d",&x);
printf("%.6f",approx_pi(x));
return 0;
}
