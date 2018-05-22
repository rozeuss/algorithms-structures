#include <stdio.h>
#include <stdlib.h>
#include <fstream>

typedef struct list{
        int key;
        struct list *next;
        struct list *prev;
        }list;
        
        
struct list *head = NULL;
struct list *tail = NULL;
        
void ADD(int a){
struct list *tmp = (list*)malloc(sizeof(list)); 
tmp->key=a;
tmp->next=NULL;
tmp->prev=NULL;
     if(head==NULL){
		head=tmp;
		head->next=tail;
		tail=tmp;
		tail->prev=head;
                       }
      else
     {
       tail->next=tmp;
       tmp->prev=tail;
       tail = tmp;
		       }  
}


void insert(){
     int x;
     struct list *tmp, *a;
     tmp=head->next; 
     while(tmp!=NULL){
              a=tmp;
              while(a!=head){
            if(a->key<a->prev->key){
              x=a->key;
              a->key=a->prev->key;                  
              a->prev->key=x;                     
                   }
                   a=a->prev;
                   }         
      tmp=tmp->next; 
       }
     }
     
  
int main(int argc, char *argv[])
{
  
  
  	 struct list *p = (list*)malloc(sizeof(list)); 
   	 int liczba;
     FILE *plik;
     plik=fopen("WE.txt", "r");
     if(plik==NULL){
          printf("Nie mozna znalesc pliku WE.txt");
          }
          else
          {
            while(fscanf(plik,"%d",&liczba) !=EOF){
            ADD(liczba);                                                                                              
		    } 
               fclose(plik);
              }
insert();

     
     p=head;
     plik=fopen("WY.txt", "w+");
     while(p!=NULL){
     fprintf(plik, "%d\n", p->key); 
     p=p->next;  
                    }
     printf("Utworzono WY.txt");
     fclose(plik);

  return 0;
}

	
	

