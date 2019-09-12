#include <stdio.h>
int main(){
  int a[10];
  int i,ris,trovato;
  trovato=0;
  for(i=0;i<10;i++)
  scanf("%d",&a[i]);
  for(i=1;i<9;i++){
    if(a[i+1]-a[i-1]==a[i] && trovato==0){
      printf("%d",i);
      trovato=1;
    }
  }
  if (trovato==0) puts("-1");
}
