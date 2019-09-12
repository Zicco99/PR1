#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node{
  int soldi;
  char* matricola;
  struct _node* next;
}node;

void rec_print(node* head,int x){
  if(head==NULL) return;

  printf("// La matricola %s ha %d Euro e puo' comprare %d Grammi //\n",head->matricola,head->soldi,(int)(head->soldi/x));
  if((int)(head->soldi/x)==0)
  printf("Povero %s , niente cannetta , se volete donare https://it.pornhub.com/\n ",head->matricola);
  rec_print(head->next,x);
}

node* addo_rec(node* curr,int mo,char* ma){
  if(curr==NULL){
    node* new=malloc(sizeof(node));
    new->matricola=ma;
    new->soldi=mo;
    new->next=NULL;
    return new;
  }
  else if(strcmp(curr->matricola,ma)){
    node* new=malloc(sizeof(node));
    new->matricola=ma;
    new->soldi=mo;
    new->next=curr;
    return new;
  }

  else curr->next=addo_rec(curr->next,mo,ma);
  return curr;
}

void add_rec(node** head,node* new){
  node* temp=*head;
  new->next=NULL;
  if (*head==NULL) *head=new;
  else{
      while (temp->next != NULL){
              temp=temp->next;}
      temp->next=new;
  }
}


void filter(node** head,int x,node** list2){
  if((*head)!=NULL){
    if((*head)->soldi < x){
      node* temp=*head;
      *head=(*head)->next;
      add_rec(list2,temp);
      filter(&(*head),x,list2);
    }
    else filter(&((*head)->next),x,list2);



  }else return;
}


int main(){
  int mon,x;
  char* nome;
  node *lis1=NULL;
  node *filtered=NULL;
  do{
    nome=malloc(18*sizeof(char));
    scanf("%s",nome);
    scanf("%d",&mon);
    if(mon>0){
      lis1=addo_rec(lis1,mon,nome);
    }
  }while(mon>0);
  printf("// Quant'e' al grammo? //\n");
  scanf("%d",&x);
  filter(&lis1,x,&filtered);
  printf("\n// Clienti: //\n");
  rec_print(lis1,x);
  if(filtered!=NULL){
  printf("\n// Questi sono gli studenti che non hanno abbastanza soldi per l'erba //\n");
  rec_print(filtered,x);
  }
  else printf("\n// Tutti compreranno l'erba <3 //\n");

}
