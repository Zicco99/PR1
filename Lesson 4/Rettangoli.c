#include <stdio.h>
int main(){
int x,h,i,j;
scanf("%d",&h);
scanf("%d",&x);
if(x==1 && h==1){ printf("*"); return 0; }
for(i=0;i<x;i++) { printf("*"); }
printf("\n");
for(j=0;j<h-2;j++){
   printf("*");
   if(x>1){
   for(i=0;i<x-2;i++){
   printf(" ");
   }
   printf("*\n");
   }
   else{
   printf("\n");
   }
   }
if(h>1){
for(i=0;i<x;i++) printf("*");
printf("\n");
}
return 0;
}
