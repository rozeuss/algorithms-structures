#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
     
using namespace std;
fstream plikwe, plikwy;
     
const int n = 50; //wielkosc stosu

void pop(int n, char stos[])
{
  int i = 0;
  while (stos[i] != ' ')
  {
    if(i != n-1)
    {
      stos[i] = stos[i+1];
      i++;
    }
    else stos[i] = ' ';
  }
}
     
void push(char znak, int n, char stos[])
{
  int i = 0;
  if(stos[0] == ' ')
  {
    stos[0] = znak;
  }
  else
  {
    while(stos[i] != ' ')
    {
      i++;
    }
    while(i >= 0)
    {
      stos[i+1] = stos[i];
      i--;
    }
    stos[0] = znak;
  }
}    
     
main()
{
  char stos[n];
  char test;
  int i = 0;

  plikwe.open("WE.txt", std::ios::in);
  plikwy.open("WY.txt", std::ios::out);
     
  if (!plikwe.good())
  {
    cout << "Blad otwarcia pliku z danymi!" << endl;
    fflush(stdin);
    getchar();
    return 1;
  }
  cout << "ONP - Tablica" << endl;
  cout << "Pomyslnie otwarto plik z danymi." << endl;

  for(int i = 0; i < n ; i++)
  {
    stos[i] = ' ';   //  to nasz znak pusty traktowany jako nic;
  }

  while( plikwe >> test)
  {
    if(test == '(')
    {
      push(test,n,stos);
    }
    else if(test == ')')
    {
      while( (stos[0]) != '(' )
      {
        plikwy << stos[0];
        pop(n,stos);
      }
      pop(n,stos);     
    }   
    else if(test == '+' || test == '-')
    {
      while(stos[0] == '+' || stos[0] == '-' || stos[0] == '*' || stos[0] == '/' || stos[0] == '%')
      {
        plikwy << stos[0];
        pop(n,stos);        
      }
      push(test,n,stos);
    }
    else if(test == '*' || test == '/' || test == '%' )
    {
      while(stos[0] == '*' || stos[0] == '/' || stos[0] == '%')
      {
        plikwy << stos[0];
        pop(n,stos);             
      }
      push(test,n,stos);
    }
    else
    {
      plikwy << test;
    }
  }
  while(stos[i] != ' ')
  {
    plikwy << stos[i];            
    i++;
  }       

  plikwe.close();
  plikwy.close();

  cout << "Program wykonal konwersje pomyslnie." << endl;

  fflush(stdin);
     
     
  return 0;
}
