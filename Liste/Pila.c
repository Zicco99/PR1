#include <stdio.h>
#include <stdlib.h>
typedef struct elemento{
int info;
struct elemento * next;
}node;

node* add_rec(node* head,int valore){
// base case
  if(head==NULL){
    node* elem=malloc(sizeof(node));
    elem->info=valore;
    elem->next=NULL;
    return elem;
  }
  // orderly insertion
  else if(head->info < valore){
    node* elem=malloc(sizeof(node));
    elem->info=valore;
    elem->next=head;
    return elem;
  }
  // recursion
  else (head)->next = add_rec(head->next,valore);
  return head;
  }

void printlist(node* head){
  node* temp=head;
  while(temp!=NULL){
    printf("%d\n",temp->info);
    temp=temp->next;
  }
}
int main(){
 int n,i;
 node* head=NULL;
 n=0;
 do{
   scanf("%d",&n);
   if(n>0) head = add_rec(head,n);
 }while(n>=0);
printf("Done inserting elements\n");
printf("Value of head: %d\n", head);
printlist(head);
printf("Done completely\n");
}
