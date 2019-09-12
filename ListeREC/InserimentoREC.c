#include <stdio.h>
#include <stdlib.h>
struct elemento{
  int info;
  struct elemento* next;
};
typedef struct elemento el;
typedef el* lista;
  void addmeno(lista *head){
    lista temp=*head;
    if (temp==NULL) return;
    else
    {
      if((temp->info)%2==0){
      lista aux=malloc(sizeof(el));
      aux->info=-1;
      aux->next=*head;
      *head=aux;
    }
  }
  addmeno(&(temp->next));
}

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
  int main(){
   int n,i;
   lista head=NULL;
   n=1;
   while(n>=0){
     scanf("%d",&n);
     if(n>=0) add(&head,n);
   }
  addmeno(&head);
  printrec(head);

}
