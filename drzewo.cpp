#include <iostream>
#include <cstdlib>
#include <fstream>



using namespace std;


struct BSTtree
{
       int key;
       struct BSTtree *left, *right, *parent;
};

void dodaj_bst(struct BSTtree **root, int wartosc)
{
                 struct BSTtree *wst=(struct BSTtree*)malloc(sizeof(struct BSTtree));
                 struct BSTtree *akt=*root;
                 int wyjscie=0;
                 wst->right=NULL;
                 wst->left=NULL;
                 wst->parent=NULL;
                 wst->key=wartosc;
                 if(akt==NULL)
                 {
                               *root=wst;
                 }
                 else
                 {   while(wyjscie==0)
                 {
                     if(akt->key<=wartosc)
                     {                   if( akt->right)
                                         {                   
                                                          akt=akt->right;
                                         }
                                         else
                                         {
                                         wyjscie=1;
                                         }
                                        
                     }
                     else
                     {
                     
                     if(akt->key>wartosc)
                     {
                                         if(akt->left)
                                         {
                                                            akt=akt->left;
                                         }
                                         else
                                         {
                                       wyjscie=2;
                                       }
                     }
                     }
                     }
                     if(wyjscie==2)
                     {
                                  akt->left=wst;
                                  wst->parent=akt;
                     }
                     if(wyjscie==1)
                     {
                                  akt->right=wst;
                                  wst->parent=akt;
                     }
                 }
}
        
        
void wyswietl(struct BSTtree *root)
{
     struct BSTtree *akt=root;
     if(root){
     if(akt)
     {
             cout<<"O:"<<akt->key<<"\t";
             if(akt->left)
             {
                          cout<<"L:"<<akt->left->key<<"\t";
             }
             else
             {
                 cout<<"L:brak"<<"\t";
             }
             if(akt->right)
             {
                           cout<<"P:"<<akt->right->key<<"\t";
             }
             else
             {
             cout<<"P:brak"<<"\t";
             }
             cout<<endl;
             wyswietl(akt->left);
             wyswietl(akt->right);
     }
	 }
}

void preorder(struct BSTtree *root)
{
     struct BSTtree *akt=root;
    
     if(root){
     
     if(akt)
     {
             cout<<akt->key;
       
             cout<<endl;
             preorder(akt->left);
             preorder(akt->right);
     }
   
	 }
	   
}

void inorder(struct BSTtree *root)
{
     struct BSTtree *akt=root;
    
     if(root){
     
     if(akt)
     {
     	     inorder(akt->left);
     	     cout<<akt->key;
     	     cout<<endl;
     	     inorder(akt->right);
            
          
     }
   
	 }
	   
}


void postorder(struct BSTtree *root)
{
     struct BSTtree *akt=root;
    
     if(root){
     
     if(akt)
     {
     	     postorder(akt->left);
     	     postorder(akt->right);
     	     cout<<akt->key;
     	     cout<<endl;
     	     
          
     }
   
	 }
	   
}


void usun_wezel(struct BSTtree **root, int key){
    if(*root!= NULL){
        if((*root)->key > key) usun_wezel(&(*root)->left,key);
        else{
            if ((*root)->key < key) usun_wezel(&(*root)->right, key);
            else{
                struct BSTtree *z=*root;
                if(z->left==NULL){
                                  if(z->right) z->right->parent=(*root)->parent;
                                  *root=z->right;
                                    free(z);
                                    z=NULL;
                }else{
                    if (z->right==NULL){
                                        z->left->parent=(*root)->parent;
                                        *root=z->left;
                                          free(z);
                                          z=NULL;
                    }else{
                        struct BSTtree *p=z->left, *r=z;
                        while(p->right!=NULL) {
                            r=p;
                            p=p->right;
                        }

                        int temp = p->key;
                        p->key=z->key;
                        z->key=temp;
                        
                if(r->key!=z->key){
                            r->right=p->left;
                           if(r->right!=NULL) r->right->parent=p->parent;
                        }
                        else{
                            r->left=p->left;
                            if(r->left!=NULL)r->left->parent=p->parent;
                        }
                        free(p);
                        p=NULL;
                    }
                }
            }
        }
    }
}

void usun_BST(struct BSTtree *root) 
{
    struct BSTtree *akt=root; 
    if(akt) 
    { 
    usun_BST(akt->left); 
    usun_BST(akt->right);
    akt =root; 
    delete akt; 
    root = NULL; 

    }

}

void opcje()
{
    cout<<"0. Wyjscie z programu"<<endl<<"1. Wczytanie drzewa BST z pliku"<<endl<<"2. Reczne uzupelnienie drzewa BST"<<endl<<"3. Reczne usuniecie wezla"<<endl;
    cout<<"4. Usuniecie drzewa BST"<<endl<<"5. Wypisanie drzewa BST"<<endl<<"6. PRE-ORDER"<<endl<<"7. IN-ORDER"<<endl<<"8. POST-ORDER"<<endl<<"9. Ponowne wyswietlenie MENU"<<endl;
}


int main()
{

struct BSTtree *rootBST=NULL;


    int opcja=0,wyjscie=1;
    int liczba=0;
    int temp=0;
    string str;
    
	opcje();
	cout<<endl;
 //   while(wyjscie)
 	do
    {
    cout<<"Opcja nr: ";
    cin>>opcja;
    switch(opcja)
    {
    	    	 case 0:
    	    	 		cout<<endl;
                        cout<<"Koniec programu.\n";
                        break; 
                 case 2:
                        {      
                        cout<<endl;
						cout<<"Ile liczb chcesz dodac do drzewa?"<<endl;
                        cin>>liczba;
                        int i=0;
                        cout<<"Podaj liczby ktore maja byc dodane do drzewa"<<endl;
                        for(i=0;i<liczba;i++)
                        {                   
                                            cin>>temp;
                                            dodaj_bst(&rootBST, temp);
                        }
                        cout<<"Liczba dodanych elementow: "<<liczba<<endl<<endl;
                        break;
                        }                     
                      
                 case 1:
                      {
                      						  cout<<endl;
                                              fstream FILE;
                                              FILE.open("WE1.txt", fstream::in);
                                              if(FILE.good())
                                              {
                                                                cout<<"Otwarto plik WE1.txt"<<endl;    
                                              }
                                              else
                                              {
                                                  				cout<<"Nie mozna znalezc pliku WE1.txt"<<endl;
                                              }
                                              while(getline(FILE,str))
                                              {
                                                                     temp=atoi(str.c_str());
                                                                     dodaj_bst(&rootBST,temp);
                                              }                               
                                              FILE.clear();
                                              FILE.seekg(0,ios::beg);
                                              FILE.close();
                                              cout<<"Drzewo BST uzupelniono danymi z pliku"<<endl<<endl;
                                              break;
                        }
             
                 case 5:
                      {
                       cout<<endl;
                       wyswietl(rootBST);
                       cout<<endl;
                       break;
                       }
                 case 4:
                      { 
                      cout<<endl;
                    		usun_BST(rootBST);
                                                           
                            rootBST=NULL;
                            cout<<"Usunieto cale drzewo"<<endl<<endl;
                            break;
                      }
                
                case 9:{
                	cout<<endl;
					opcje();
					cout<<endl;
               		break;
				}
                case 6:{
                	cout<<endl;
                	preorder(rootBST);
                	cout<<endl;
                	break;
                }    
                  case 7:{
                	cout<<endl;
                	inorder(rootBST);
                	cout<<endl;
                	break;
                }    
                  case 8:{
                	cout<<endl;
                	postorder(rootBST);
                	cout<<endl;
                	break;
                }    
                 case 3:{
                 	cout<<endl;
                 	cout<<"Ktory wezel usunac?"<<endl;
                    cin>>liczba;
                	usun_wezel(&rootBST, liczba);
                	cout<<"Usunieto wezel o wartosci "<< liczba<<endl<<endl;
                	liczba=0;
                	break;
                }    
                      
                      
                      
                	default:
                 	cout<<endl;
                    cout<<"Wprowadziles nieprawidlowa liczbe"<<endl;
    }		  
    
                      
   }while(opcja!=0);

 	
}


