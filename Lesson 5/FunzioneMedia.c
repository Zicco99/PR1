#include <stdio.h>
int main(){
float media;
int x,ult,i;
int sommapos=0,sommaneg=0,npos=0,nneg=0;
for(i=0;i<9;i++){
scanf("%d",&x);
if(x>0){
sommapos+=x;
npos++;
}
else if(x<0){
sommaneg+=x;
nneg++;
}
}
scanf("%d",&ult);
if(ult>0) media=(sommapos+ult)/(npos+1);
else media=(float)(sommaneg+ult)/(nneg+1);
printf("%.2f\n",media);



return 0;
}
