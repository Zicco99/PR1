#include <stdio.h>
#include <stdlib.h>
typedef struct _aereo{
char dest[3];
int carburante;
int miglia;
struct _aereo* next;
}aereo;

void display(aereo *head){
  if (head!=NULL){
    printf("Destinazione %c%c%c - Carburante %d - Miglia %d\n",head->dest[0],head->dest[1],head->dest[2],head->carburante,head->miglia);
    display(head->next);}
  else return;
}

void append(aereo** head,char* d,int m,int c){
  aereo* new=malloc(sizeof(aereo));
  new->dest[0]=d[0];
  new->dest[1]=d[1];
  new->dest[2]=d[2];
  new->miglia=m;
  new->carburante=c;
  if(*head==NULL){
    *head=new;
    return;
  }
  aereo* temp=*head;
  while(temp->next!=NULL){
  temp=temp->next;
  }
  temp->next=new;
}

aereo* filtra(aereo *head,char* cod){
 aereo* listafil=NULL;
 while(head->next!=NULL){
   if(head->dest[0]==cod[0] && head->dest[1]==cod[1] && head->dest[2]==cod[2])
   {
      append(&listafil,head->dest,head->miglia,head->carburante);
      printf("added\n");
   }
   printf("not added\n");
   head=head->next;
 }
 return listafil;
}
void addhead(aereo** head,char d[],int c,int m){
  aereo* new=malloc(sizeof(aereo));
  new->dest[0]=d[0];
  new->dest[1]=d[1];
  new->dest[2]=d[2];
  new->miglia=m;
  new->carburante=c;
  if(*head==NULL){
    new->next=NULL;
    *head=new;
  }
  else{
   new->next=*head;
   *head=new;}
}

void leggiaerei(char* cod,aereo** list){
  char curr[3];
  int carbu,miglia;
  int end=0;
  scanf("%c%c%c",&cod[0],&cod[1],&cod[2]);
  while(!end){
    scanf(" %c%c%c",&curr[0],&curr[1],&curr[2]);
    scanf("%d%d",&carbu,&miglia);
    if(curr[0]==cod[0] && curr[1]==cod[1] && curr[2]==cod[2] && carbu==-1 && miglia==-1){
      end++;}
    else addhead(&(*list),curr,carbu,miglia);
  }
}

aereo* primo(aereo* list){
  aereo* max=NULL;
  float mcmax=0;
  while(list!=NULL){
  if((float)list->miglia/(float)list->carburante > mcmax){
    mcmax=(float)list->miglia/(float)list->carburante;
    max=list;
  }
  list=list->next;
  }
  if(max!=NULL) return max;
}


int main(){
  char cod[3];
  aereo *lista=NULL;
  aereo *landing;
  leggiaerei(cod,&lista);
  printf("Codice IATA Torre di controllo: %c%c%c\n",cod[0],cod[1],cod[2]);
  printf("\n");
  if(lista!=NULL){
    printf("Elemento voli da gestire\n");
    display(lista);
    landing=filtra(lista,cod);
    printf("\n");
  }
  printf("Elenco voli da far atterrare:\n");
  display(landing);
  printf("\n");
  aereo *head=primo(landing);
  printf("Migliore %c%c%c - Carburante %d - Miglia %d\n",head->dest[0],head->dest[1],head->dest[2],head->carburante,head->miglia);

}
