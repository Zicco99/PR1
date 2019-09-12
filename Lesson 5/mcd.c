#include <stdio.h>
#include <math.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
int mcd(int x,int y){
int i;
for(i=min(x,y);i>0;i--){
   if(x%i==0 && y%i==0) return i;
   }
}
int mcm(int x,int y){
int z=max(x,y);
int mult;
int i=1;
while(1){
 mult=z*i;
 if(mult%x==0 && mult%y==0)
 {
 return mult;
 }
 i++;
}
return 0;
};


int main(){
int x;
int y;
scanf("%d",&x);
scanf("%d",&y);
printf("%d\n",mcd(x,y));
printf("%d",mcm(x,y));
return 0;
}
