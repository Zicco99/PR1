#include <stdio.h>
void draw(int y){
  int i;
  for(i=0;i<y;i++){
    printf("*");
  }
  printf("\n");
}
int main()
{
  int x,i;
  scanf("%d",&x);
  do{
    draw(x);
    x=x-2;
  }while(x>2);
  if (x==1) puts("*");
  if (x==2) puts("**");
}
