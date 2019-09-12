#include <stdio.h>
void tabellina(int x,int i){
if(i==11) return;
printf("%d\n",i*x);
tabellina(x,i+1);
}

int main(){
int x,i=1;
scanf("%d",&x);
tabellina(x,i);
}
