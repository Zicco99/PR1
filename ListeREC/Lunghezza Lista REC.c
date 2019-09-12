#include <stdio.h>
#include <stdlib.h>
struct elemento {
  int info;
  struct elemento* next;
};
typedef struct elemento el;
typedef el* lista;

void add(lista *head,int v){
  lista aux=malloc(sizeof(el));
    aux->info=v;
    aux->next=*head;
    *head=aux;
}


int displayrec(lista head){
  if(head!=0){
    printf("%d\n",head->info);
    displayrec(head->next);
  }
}

int count (lista head){
  if(head!=0){
    return 1 + count(head->next);
  }
  else return 0;

}

int main(){
  lista head=NULL;
  int n=1;
  while(n>0){
    scanf("%d",&n);
    if(n>0) add(&head,n);
  }
  printf("%d\n",count(head));
}
