#include <stdio.h>
#include <stdlib.h>
typedef struct s{
  int matricola;
  struct s* next;
} studente;

void display(studente *head){
  typedef studente* lista;
  lista temp=head;
  while(temp!=NULL){
    printf("%d\n",temp->matricola);
    temp=temp->next;
  }
}

void addo(studente **root,int v){
  typedef studente* lista;
  lista prev,temp;
  lista aux=malloc(sizeof(studente));
  aux->matricola=v;
  aux->next=NULL;
  if(*root==NULL){
    *root=aux;
  }
  else{
    prev=NULL;
    temp=*root;
    while(temp!=NULL && temp->matricola<=v){
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
        aux->next=*root;
        *root=aux;
      }
    }
  }
}

void leggimatricole(studente **head){
 typedef studente* lista;
 lista corsoA,corsoB;
 corsoA=NULL;
 corsoB=NULL;
 int n;
 do{
   scanf("%d",&n);
   if (n>0){
     if(n%2==0){
       addo(&corsoA,n);
     }
     else addo(&corsoB,n);
     }
 }while(n>0);
 lista temp=corsoA;
 while(temp->next!=NULL){
   temp=temp->next;
 }
 temp->next=corsoB;
 *head=corsoA;
}

int findx(studente *head,int v){
  typedef studente* lista;
  while(head!=NULL){
    if(head->matricola==v) return 1;
    head=head->next;
  }
  return 0;
}

studente* unione(studente *lista1,studente* lista2)
{
  typedef studente* lista;
  lista pari,dispari,ris,temp;
  pari=NULL;
  dispari=NULL;
  int mat;
  while(lista1!=NULL){
    mat=lista1->matricola;
    if(mat%2==0) {addo(&pari,mat);}
    else addo(&dispari,mat);
    lista1=lista1->next;
  }
  while(lista2!=NULL){
    mat=lista2->matricola;
    if(mat%2==0){
      if(findx(pari,mat)==0){
        addo(&pari,mat);
      }
    }
    else{
      if(findx(dispari,mat)==0){
        addo(&dispari,mat);
      }
    }
    lista2=lista2->next;
  }
  temp=pari;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=dispari;
  return pari;
}

int count(studente *head){
  typedef studente* lista;
  if(head!=0){
    if(head->matricola%2==0) return 1 + count(head->next);
    else return 0 + count(head->next);
  }
  else return 0;
}

int main(){
  typedef studente* lista;
  lista primoesame,secondoesame,tutti;
  primoesame=NULL;
  secondoesame=NULL;
  tutti=NULL;

  leggimatricole(&primoesame);
  leggimatricole(&secondoesame);
  tutti=unione(primoesame,secondoesame);
  printf("Lista finale:\n");
  display(tutti);

  printf("Un totale di %d studenti del corso A hanno superato almeno un esame.\n",count(tutti));

}
