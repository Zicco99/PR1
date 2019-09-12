#include <stdio.h>
#include <math.h>
void swap(int* c,int* b,int* a){
int temp;
if(*a>*b && *a>*c){
 if(*b<*c){
  temp=*c;
  *c=*b;
  *b=temp;
 }
}
else{
 temp=*a;
 if(*b>*c){
   *a=*b;
   if(*c>temp){
    *b=*c;
    *c=temp;
    }
    else *b=temp;
    }
 else{
  *a=*c;
  if(*b>temp){
   *c=temp;
   }
  else{
   *c=*b;
   *b=temp;
   }
  
  }}
}

int main(){
int a,b,c;
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
swap(&a,&b,&c);
printf("%d\n",a);
printf("%d\n",b);
printf("%d",c);
return 0;
}
