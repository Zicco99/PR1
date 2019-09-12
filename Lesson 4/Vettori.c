#include <stdio.h>
void stampa(int *v,int dim){
int i;
printf("[");
for(i=0;i<dim-1;i++){
printf("%d,",v[i]);
}
printf("%d]\n",v[i]);
}


int main(){
int i,j,x;
int a[5];
int b[5];
int c[5];
for(i=0;i<10;i++){
if(i<5){
scanf("%d",&x);
a[i]=x;
c[i]=x;
}
else{
scanf("%d",&x);
j=i%5;
b[j]=x;
c[j]=c[j]+x;
}
}
stampa(a,5);
stampa(b,5);
stampa(c,5);
return 0;
}
