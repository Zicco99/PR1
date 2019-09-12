#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
int val;
struct _node* next;
}node;


int arr(float v){
  if(v-(int)v>0.5) return ((int)v)+1;
  else return (int)v;
}

void append(node** head){
  float v;
  node* temp=*head;
  node* new=malloc(sizeof(node));
  scanf("%f",&v);
  new->val=arr(v);
  new->next=NULL;
  if(*head==NULL){
    *head=new;
    return;
  }
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=new;
}

int member(node* list,int x){
  if(list==NULL) return 0;
  if(list->val=x) return 1;
   else member(list->next,x);
}

void filter(node** head){
  if((*head)->next!=NULL){
    if(abs((*head)->val-(*head)->next->val)>3){
      node* temp=*head;
      *head=(*head)->next;
      free(temp);
      filter(&(*head));
    }
    else filter(&((*head)->next));
  }else return;
}

void printlist(node* head){
  if(head==NULL) return;
  printf("%d\n",head->val);
  printlist(head->next);
}

int main(){
  node* list=NULL;
  node* list2=NULL;
  int i,x;
  for(i=0;i<5;i++){
    append(&list);
  }
  printlist(list);
  printf("LOL\n");
  filter(&list);
  printlist(list);
  scanf("%d",&x);
  printf("SOSSSOS %d\n",member(list,x));




}
