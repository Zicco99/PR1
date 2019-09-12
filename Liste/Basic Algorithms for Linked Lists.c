#include <stdio.h>
#include <stdlib.h>
typedef struct node_{
  int data;
  struct node_* next;
}node;

void add(node** head,int value){
  node* aux=malloc(sizeof(node));
  aux->data=value;
  aux->next=*head;
  *head=aux;
}


void append(node** head,int value){
  node* aux=malloc(sizeof(node));
  aux->next=NULL;
  aux->data=value;
  if(*head==NULL){
    *head=aux;
    return;
  }
  node* temp=*head;
  while(temp->next!=NULL){
  temp=temp->next;
  }
  temp->next=aux;
}

void add_order(node** head,int value){
  node* aux=malloc(sizeof(node));
  node* prev=NULL;
  node* curr=*head;
  aux->data=value;
  while(curr!=NULL && curr->data<value){
  prev=curr;
  curr=curr->next;
  }
  if(prev==NULL){
    aux->next=*head;
    *head=aux;
  }
  else{
    prev->next=aux;
    aux->next=curr;
  }
}

void filter(node** head){
  if(*head==NULL) return;
  if((*head)->data%2==0){
    node* temp=*head;
    *head=(*head)->next;
    free(temp);
    filter(&(*head));
  }
  else filter(&((*head)->next));

}

void printlist(node* head){
  if(head==NULL){
    printf("Fine Stampa\n");
    return;
  }
  printf("%d\n",head->data);
  printlist(head->next);
}

int main(){
  int n,i,v;
  node* lista1=NULL;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&v);
    add(&lista1,v);
  }
  printf("Inizio Stampa\n");
  printlist(lista1);
  filter(&lista1);
  printf("Inizio Stampa\n");
  printlist(lista1);
}
