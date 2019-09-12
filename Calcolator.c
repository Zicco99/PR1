#include <stdio.h>
int main (){
  float a,b;
  int c,d;
  char op;
  scanf("%f",&a);
  scanf("%f",&b);
  scanf(" %c",&op);
  switch(op){
    case '+':
    printf("%.1f",a+b);
    break;
    case '-':
    printf("%.1f",a-b);
    break;
    case '/':
    printf("%.1f",a/b);
    break;
    case '%':
    c=(int)a;
    d=(int)b;
    a=(float)(c%d);
    printf("%.1f",a);
    break;
}

}
