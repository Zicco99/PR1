#include <stdio.h>
#include <math.h>
float sum_pow(float x,int n){
int i;
float sum;
for(i=0;i<=n;i++){
sum=sum+(float)pow(x,i);
}
return sum;
}


int main(){
float x;
int n;
int i=0;
scanf("%d",&n);
scanf("%f",&x);
printf("%.2f",sum_pow(x,n));
return 0;
}
