#include <stdio.h>
#include <stdlib.h>
struct elemento{
  int info;
  struct elemento* next;
};
typedef struct elemento el;
typedef el* lista;
typedef enum{false,true} boolean;

boolean check(lista head){
  lista succ=head->next;
  if(succ->info<=head->info){
    return false;
  }
  else{
    if(succ->next==NULL){
      return true;
    }
    else
    check(succ);
  }



}
void append(lista *head,int v){
  lista temp;
  lista aux=malloc(sizeof(el));
  aux->info=v;
  aux->next=NULL;
  if(*head==NULL){
    *head=aux;
  }
  else{
    temp=*head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=aux;
  }
}

  int main(){
   boolean ris;
   int n,i;
   lista head=NULL;
   n=1;
   while(n>=0){
     scanf("%d",&n);
     if(n>=0) append(&head,n);
   }
   ris=check(head);
   if(ris==true) printf("True");
   else printf("False");

}
