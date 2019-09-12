#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 30
void readbinary(char arr[], int *len,int *reps){
int val,i=0;
do{
scanf("%d",&val);
if(val==0 || val==1){
arr[i]=val;
i++;
}
else{
*reps=val;
i++;
}
}while((val==0 || val==1) && i<=ARR_LEN);
*len=i-1;
}


int sum1rec(char arr[],int len){
if(len==-1){
 return 0;
}
if(arr[len-1]==1){
return 1+sum1rec(arr,len-1);
}
else return sum1rec(arr,len-1);
}


int existSubseq(char arr[], int len,int reps){
int count=0,i=0;
for(i=0;i<len;i++){
if(arr[i]==1){
 count++;
 if(count==reps && arr[i+1]==0) return 1;
 }
else count=0;
}
return 0;
}







int main(){
 char arr[ARR_LEN];
 int len,reps,i;
 
 //Read and print the array: 
 readbinary(arr,&len,&reps);
 printf("Array:\n");
 for(i=0;i<len;i++){
 printf("%d ",arr[i]);
 }
 printf("\n");

 printf("Totale occorrenze di 1: %d\n", sum1rec(arr,len));
 
 if(existSubseq(arr,len,reps))
  printf("Condizione per %d uno contigui: VERA\n",reps);
 else
  printf("Condizione per %d uno contigui: FALSA\n",reps);
 return 0;
}
