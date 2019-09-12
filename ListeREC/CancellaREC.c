#include <stdio.h>
#include <stdlib.h>
struct elemento{
  int info;
  struct elemento* next;
};
typedef struct elemento el;
typedef el* lista;

  void add(lista *head,int val){
    lista aux=malloc(sizeof(el));
    aux->info=val;
    aux->next=*head;
    *head=aux;
  }
  int printrec(lista head){
    if(head!=0){
      printf("%d -> ",head->info);
      printrec(head->next);
    }
    else{
      printf("NULL");
    }
  }
    void cancmult(lista *head,int v){
      lista temp=*head;
      lista succ;
      if(temp==NULL) return;
      else {
        if(temp->info%v==0){
        lista aux=temp;
        succ=temp->next;
        *head=succ;
        free(aux);
        cancmult(head,v);
      }
      else cancmult(&succ,v);
  }
}

  int main(){
   int n,i;
   lista head=NULL;
   scanf("%d",&i);
   n=1;
   while(n>=0){
     scanf("%d",&n);
     if(n>=0) add(&head,n);
   }
  cancmult(&head,i);
  printrec(head);

}
