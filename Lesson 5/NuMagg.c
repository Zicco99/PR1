#include <stdio.h>
#include <math.h>
int count_larger(int x,int* a,int dim){
int i,count=0;
for(i=0;i<5;i++){
if(a[i]>x) count++;
}
return count;
}

int main(){
int x,i;
int a[5];
scanf("%d",&x);
for(i=0;i<5;i++) scanf("%d",&a[i]);
printf("%d",count_larger(x,a,5));
return 0;
}
