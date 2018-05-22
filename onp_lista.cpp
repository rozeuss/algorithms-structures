#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
     
using namespace std;
fstream plikwe, plikwy;

struct ts_lista{
  char key;
  struct ts_lista *next;
}ts_lista;

struct ts_lista *head=NULL, *oldhead=NULL;

struct ts_lista *push(struct ts_lista *head, char znak)
{
  struct ts_lista *elem = NULL;
  
  elem = (struct ts_lista *)malloc(sizeof(struct ts_lista));
  elem -> key = znak;
  if( head == NULL )elem -> next = NULL;
  else elem -> next = head;
  return elem;
}

struct ts_lista *pop(struct ts_lista *head)
{
  struct ts_lista *temp = NULL;
  
  temp = head -> next;
  free(head);
  return temp;
}
main()
{

  char test;
     
  plikwe.open("WE.txt", std::ios::in);
  plikwy.open("WY.txt", std::ios::out);
     
  if (!plikwe.good())
  {
    cout << "Blad otwarcia pliku z danymi!" << endl;
    fflush(stdin);
    getchar();
    return 1;
  }
  cout << "ONP - Lista jednokierunkowa" << endl;
  cout << "Pomyslnie otwarto plik z danymi." << endl;

  while(plikwe >> test)
  {
    if(test == '(')
    {
      head = push(head, test);
    }              
    else if(test == ')')
    {
      while(head -> key != '(' )
      {
        plikwy << head -> key;
        head = pop(head);
      }
      head = pop(head);                   
    }
    else if( (test == '-') || (test == '+') )                            
    {
      if (head != NULL)
      {
        while(head -> key == '+' || head -> key == '-' || head -> key == '*' || head -> key == '/' || head -> key == '%')
        {
          plikwy << head -> key;
          head = pop(head);             
        }
      }
      head = push(head, test);
    }    
    else if( (test == '*') || (test == '/') || (test == '%') )
    {
      if (head != NULL)
      {                                       
        while(head -> key == '*' || head -> key == '/' || head -> key == '%')
        {
          plikwy << head -> key;
          head = pop(head);             
        }
      }
      head = push(head, test);
    }
    else
    {
      plikwy << test;
    }          
  }     
  while(head != NULL)
  {
    plikwy << head -> key;            
    head = head -> next;
  }           
   
    plikwe.close();
    plikwy.close();

    cout << "Program wykonal konwersje pomyslnie." << endl;

    fflush(stdin);
     
    getchar();
     
    return 0;
    }
