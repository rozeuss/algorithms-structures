#include <cstdlib>
#include <iostream>

using namespace std;


float IteFib(float x)
{
      float j=2, liczba=1, pomoc=0, tmp=0;
      if (x<2) return x;
      
      else {
           
           for (j=2; j<=x; j++)
           
                 {    
                 tmp = liczba;
                 liczba += pomoc;
                 pomoc = tmp;
                 }       
           }  
      return liczba;   
}




float RekFib(float x)
{
	float suma=0;
	if ((x<2) && (x>=0))
	suma=x;
	else 
	    suma=RekFib(x-1) + RekFib(x-2);
	return suma;
}


int main(int argc, char *argv[])
{
    float a, i=0, suma=0;
    cout << "Program obliczajacy n-ty wyraz ciagu Fibonacciego: \n";
    cout << "Podaj wyraz ciagu: " << endl;
    cin >> a;
    cout << endl;
    suma=RekFib(a);
    cout << "REKURENCYJNIE Twoj "<<a<<" wyraz wynosi "<<suma <<endl;
    suma=IteFib(a);
    cout << "ITERACYJNIE Twoj "<<a<<" wyraz wynosi "<<suma;
    

    
    getchar();getchar();
    return EXIT_SUCCESS;
}
