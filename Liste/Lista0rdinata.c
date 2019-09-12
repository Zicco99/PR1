#include <stdio.h>
#include <stdlib.h>
struct elemento{
int info;
struct elemento * next;
};
typedef struct elemento el;
typedef el* lista;

void display(lista head){
  lista temp=head;
  while(temp!=NULL){
    printf("%d\n",temp->info);
    temp=temp->next;
  }
}

int findx(lista head,int x){
  lista temp=head;
  while(temp!=NULL){
    if(temp->info==x){
      return 1;
    }
    temp=temp->next;
  }
  return 0;
}
void append(lista *head,int v){
  if(findx(*head,v)==0){
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
}

void addo(lista *head,int v){
  lista prev,temp;
  lista aux=malloc(sizeof(el));
  aux->info=v;
  aux->next=NULL;
  if(*head==NULL){
    *head=aux;
  }
  else{
    prev=NULL;
    temp=*head;
    while(temp!=NULL && temp->info<=v){
      prev=temp;
      temp=temp->next;
    }
    if(temp==NULL){
      prev->next=aux;
    }
    else{
      if(prev!=NULL){
        aux->next=prev->next;
        prev->next=aux;
      }
      else{
        aux->next=*head;
        *head=aux;
      }
    }
  }
}

void intersezione(lista l1,lista l2,lista *res){
lista temp=l1;
int x;
while(temp!=NULL){
  x=temp->info;
  if(findx(l2,x)){
    append(res,x);
  }
  temp=temp->next;
}

}

int main(){
  int n,y
;
  lista lista1=NULL;
  lista lista2=NULL;
  lista res=NULL;
  n=1;
  while(n>0){
    scanf("%d",&n);
    if(n>0) addo(&lista1,n);
  }
  n=1;
  while(n>0){
    scanf("%d",&n);
    if(n>0) addo(&lista2,n);
  }
  intersezione(lista1,lista2,&res);
  display(res);
}
