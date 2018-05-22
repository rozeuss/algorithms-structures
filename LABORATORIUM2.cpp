#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

typedef struct list{
        int key;
        list*   next;
        }list;

void wstaw(list* head, int n)
{
      list* p = head;
      int i=0;
        for(i = 3; i <= n ; i++)
                {
                list *element = (struct list *)malloc(sizeof(struct list));
                p->next=element;
                p=element;
                p->key=i;
                p->next=NULL;
                }
}

void show(list* head)
{
     list* p = head;
    	 while(p!=NULL)
    	 {
   		printf("%d\n",p->key);
    	 p=p->next;
    	 }
}




void sito(list* head)
{
list* wsk=head;
list* pomoc=wsk->next;
list* prev=wsk;
list* temp=NULL;
int x;
int key;

		while(wsk!=NULL)
		{	
			key=wsk->key;
			prev=wsk;
			pomoc=prev->next;
			while(prev->next!=NULL&&pomoc->next!=NULL)
			{
			x=pomoc->key;
			 		if(x%key==0)
			 {
			               prev->next=pomoc->next;
			               free(pomoc);
			 }
			
			 prev=prev->next;
			 pomoc=prev->next;
			}
			
			if(prev->next!=NULL&&pomoc->next==NULL)
			{
			x=pomoc->key;
			if(x%key==0)
			{
			prev->next=NULL;
			free(pomoc);
			}
			}
			wsk=wsk->next;      
			}
}   
     
     

void save(FILE *plik, list* head)
{
     plik = fopen("SE.txt", "wt");
     list *p=head;
     while( p!=NULL )
	 {
   		fprintf(plik, "%d\n", p->key);
   		p=p->next;
     }  
  	fclose(plik);
}
     


int main()
{   int n;
    FILE *plik;
    list* head = (struct list*)malloc(sizeof(struct list));
    head->key=2;
    head->next=NULL;
    printf("Podaj zakres (od 2 do n).\nn: ");
    scanf("%d",&n);
    wstaw(head,n);
    show(head);
    printf("Po uzyciu sita Eratostenesa:\n");
    sito(head);
    show(head);
    save(plik, head);


    system("PAUSE");
    return 0;
}
