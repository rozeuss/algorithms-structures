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

// AVL

struct AVLtree
{
       struct AVLtree *right,*left,*parent;
       int key,bf;
};

void postorderAVL(struct AVLtree *root)
{
     struct AVLtree *akt=root;
    
     if(root){
     
     if(akt)
     {
     	     postorderAVL(akt->left);
     	     postorderAVL(akt->right);
     	     cout<<akt->key;
     	     cout<<endl;
     	     
          
     }
   
	 }
	   
}

void inorderAVL(struct AVLtree *root)
{
     struct AVLtree *akt=root;
    
     if(root){
     
     if(akt)
     {
     	     inorderAVL(akt->left);
     	     cout<<akt->key;
     	     cout<<endl;
     	     inorderAVL(akt->right);
            
          
     }
   
	 }
	   
}

void preorderAVL(struct AVLtree *root)
{
     struct AVLtree *akt=root;
    
     if(root){
     
     if(akt)
     {
             cout<<akt->key;
       
             cout<<endl;
             preorderAVL(akt->left);
             preorderAVL(akt->right);
     }
   
	 }
	   
}

AVLtree* RR(struct AVLtree **rootAVL, struct AVLtree *akt)
{
    struct AVLtree *l = akt->right, *k = akt->parent;

    akt->right = l->left;
    if(akt->right) 
    {
    akt->right->parent = akt;
    }
    l->left = akt;
    l->parent = k;
    akt->parent = l;
    
    if(k)
    {
       if(k->left == akt)
       {
                   k->left = l;
       } 
	   else
       {
            k->right = l;
       }
    }
     else
     { 
     *rootAVL = l;
     }
     if(l->bf == -1)
     {
        l->bf = 0;
        akt->bf =0;
        
     }
     else
     {
         l->bf = 1;
        akt->bf = -1; 
		
     }
     return l;
     
}

AVLtree* LL(struct AVLtree **rootAVL, struct AVLtree *akt)
{
     struct AVLtree *l = akt->left, *k = akt->parent;

     akt->left = l->right;
     if(akt->left)
     {
                   akt->left->parent = akt;
     }
     l->right = akt;
     l->parent = k;
     akt->parent = l;
     
     if(k)
     {
        if(k->left == akt)
        {
                    k->left = l; 
        }
		else
        {
             k->right = l;
        }
     }
      else
      {
           *rootAVL = l;
      }

     if(l->bf == 1)
     {
        akt->bf = l->bf = 0;
     }
     else
     {
        akt->bf = 1; 
		l->bf = -1;
     }
     return l;

}

AVLtree* RL(struct AVLtree **rootAVL, struct AVLtree *akt)
{
     struct AVLtree *l = akt->right,*k = akt->parent, *j = l->left;

     l->left = j->right;
     if(l->left)
     {
                 l->left->parent = l;
     }
     akt->right = j->left;
     if(akt->right)
     {
                    akt->right->parent = akt;
     }
     j->left = akt;
     j->right = l;
     akt->parent = l->parent = j;
     j->parent = k;
     
     if(k)
     {
         if(k->left == akt) 
         {
                    k->left = j; 
         }
		 else 
         {
              k->right = j;
         }
     }
     else *rootAVL = j;

     if(j->bf == -1) akt->bf = 1;
     else akt->bf = 0;
     if(j->bf == 1) l->bf = -1;
     else l->bf = 0;
     j->bf = 0;
     return j;
     
}

AVLtree* LR(struct AVLtree **rootAVL, struct AVLtree *akt)
{
     struct AVLtree *l = akt->left, *j = l->right, *k = akt->parent;

     l->right = j->left;
     if(l->right) l->right->parent = l;
     akt->left = j->right;
     if(akt->left) akt->left->parent = akt;
     j->right = akt;
     j->left = l;
     akt->parent = l->parent = j;
     j->parent = k;
     
     if(k)
     {
        if(k->left == akt) k->left = j; 
		else k->right = j;
     }
     else *rootAVL = j;

     if(j->bf==1) akt->bf = -1;
     else akt->bf = 0;
     if(j->bf==-1) l->bf = 1;
     else l->bf = 0;
     j->bf = 0;
     return j;

}

AVLtree* addAVLtree(struct AVLtree **rootAVL, int wartosc)
{
     struct AVLtree *akt = *rootAVL, *pom, *pom2;
     struct AVLtree *wst=new AVLtree;
     wst->left=NULL;
     wst->right=NULL;
     wst->parent=NULL;
     wst->key=wartosc;
     wst->bf=0;
     pom=wst;
     
     while(akt)
     {
        if(akt->key == wst->key)
        {
           delete wst;
           return *rootAVL;
           
        }
        
         pom = akt;
         if(wst->key < akt->key) akt = akt->left;
         else akt = akt->right;
     }
      if(*rootAVL==NULL)
      {
         *rootAVL = wst;
         return *rootAVL;
         
      }

      if(wst->key < pom->key) {pom->left = wst; wst->parent=pom;}
	  else {pom->right = wst; wst->parent=pom;}
	  
      if(pom->bf!=0)
      {
         pom->bf = 0;
         return *rootAVL;
         
      }
      
      if(pom->left==wst)
      { 
      pom->bf = 1;
      }
      else
      {
       pom->bf = -1;
      }
      
      pom2 = pom->parent;
      
      while(pom2!=NULL)
      {
         if(pom2->bf != 0)
         {
          break;
         }
         if(pom2->left==pom)
         {
          pom2->bf = 1;
         }
         else 
         {
              pom2->bf = -1;
         }
         
         pom = pom2; 
		 pom2 = pom2->parent;
      }

      if(pom2==NULL)
      {
                     return *rootAVL;
                     
      }

      if(pom2->bf == 1)
      {
        if(pom2->right == pom)
        {
           pom2->bf = 0;
           return *rootAVL;
           
        }
        
        if(pom->bf == -1)
        {
         LR(*&rootAVL,pom2); 
        }
		else
		{
         LL(*&rootAVL,pom2);
         }
        return *rootAVL;
      } 
      else
      {
         if(pom2->left == pom)
         {
             pom2->bf = 0;
             return *rootAVL;
             
         }
         if(pom->bf==1){
                         RL(*&rootAVL,pom2);
                         } 
		 else
         {
              RR(*&rootAVL,pom2);
         }
         return *rootAVL;
      }
      return *rootAVL;
}                                                                               
           
           



void wyswietlAVLtree(struct AVLtree **rootAVL)
{
     struct AVLtree *akt=*rootAVL;
     if(*rootAVL)
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
             wyswietlAVLtree(&akt->left);
             wyswietlAVLtree(&akt->right);
     }
}
void usun_AVLtree(struct AVLtree *rootAVL) 
{
    struct AVLtree *akt=rootAVL; 
    if(rootAVL) 
    { 
    usun_AVLtree(akt->left); 
    usun_AVLtree(akt->right);
    akt =rootAVL; 
    delete akt; 
    rootAVL = NULL; 
    }
}           

AVLtree* delKey(struct AVLtree **rootAVL, int key){
 
   if(*rootAVL!= NULL){
             if((*rootAVL)->key > key) return delKey(&(*rootAVL)->left,key);
             else{
                  if ((*rootAVL)->key < key) return delKey(&(*rootAVL)->right, key);
                  else{
                         struct AVLtree *z=*rootAVL, *p=z, *r=z,*y;
                         if(z->left==NULL){
                                 if(z->right) z->right->parent=(*rootAVL)->parent;
                                 *rootAVL=z->right;
                                 y=z->parent;
                                 free(z);
                                 z=NULL;
                                 return y;
                          }else{
                                 if (z->right==NULL){
                                          z->left->parent=(*rootAVL)->parent;
                                          *rootAVL=z->left;
                                          y=z->parent;
                                         free(z);
                                         z=NULL;
                                         return y;
                                  }else{
                                         p=z->left;
                                         r=z;
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
                                         y=p->parent;
                                         free(p);
                                         p=NULL;
                                         return y;
                                 }
                          }
                  }
           }
      }
}

void opcje()
{
    cout<<"0. Wyjscie z programu"<<endl<<"1. Wczytanie drzewa BST z pliku"<<endl<<"2. Reczne uzupelnienie drzewa BST"<<endl<<"3. Reczne usuniecie wezla"<<endl;
    cout<<"4. Usuniecie drzewa BST"<<endl<<"5. Wypisanie drzewa BST"<<endl<<"6. PRE-ORDER"<<endl<<"7. IN-ORDER"<<endl<<"8. POST-ORDER"<<endl<<"9. Ponowne wyswietlenie MENU"<<endl;
    cout<<"10. PRE-ORDER AVL"<<endl<<"11. IN-ORDER AVL"<<endl<<"12. POST-ORDER AVL"<<endl<<"13. Wczytanie drzewa AVL z pliku"<<endl<<"14. Usuniecie drzewa AVL"<<endl<<"15. Wypisanie drzewa AVL"<<endl;
    cout<<"16. Reczne uzupelnienie drzewa AVL"<<endl<<"17. Reczne usuniecie wezla AVL"<<endl;
}


int main()
{

struct BSTtree *rootBST=NULL;
struct AVLtree *rootAVL=NULL;

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
                      
                case 10:{
                	cout<<endl;
                	preorderAVL(rootAVL);
                	cout<<endl;
                
                	break;
                }
                case 11:{
                	cout<<endl;
                	inorderAVL(rootAVL);
                	cout<<endl;
                	break;
                }    
                  case 12:{
                	cout<<endl;
                	postorderAVL(rootAVL);
                	cout<<endl;
                	break;
                }     
                         case 13:
                      {
                      						  cout<<endl;
                                              fstream FILE;
                                              FILE.open("WE.txt", fstream::in);
                                              if(FILE.good())
                                              {
                                                                cout<<"Otwarto plik WE.txt"<<endl;    
                                              }
                                              else
                                              {
                                                  				cout<<"Nie mozna znalezc pliku WE.txt"<<endl;
                                              }
                                              while(getline(FILE,str))
                                              {
                                                                     temp=atoi(str.c_str());
                                                                     addAVLtree(&rootAVL,temp);
                                              }                               
                                              FILE.clear();
                                              FILE.seekg(0,ios::beg);
                                              FILE.close();
                                              cout<<"Drzewo AVL uzupelniono danymi z pliku"<<endl<<endl;
                                              break;
                        }
                    case 14:
                                      {
                                          usun_AVLtree(rootAVL);
                                          rootAVL=NULL;
                                          cout<<"Usunieto cale drzewo"<<endl;
                                          break;
                                      }
                                      
                    case 15: 
                             {
                                                                      wyswietlAVLtree(&rootAVL);
                                                                      break;
                             }    
                      
                       case 16:
                      {
                      	cout<<endl;
                        cout<<"Ile liczb chcesz dodac do drzewa?"<<endl;
                        cin>>liczba;
                        int i=0;
                        cout<<"Podaj liczby ktore maja byc dodane do drzewa"<<endl;
                        for(i=0;i<liczba;i++)
                        {                   
                                            cin>>temp;
                                            addAVLtree(&rootAVL, temp);
                        }
                        cout<<"Liczba dodanych elementow: "<<liczba<<endl<<endl;
                        break;
                      }
                      case 17:{
                      	    cout<<endl;
                 	cout<<"Ktory wezel usunac?"<<endl;
                    cin>>liczba;
                    delKey(&rootAVL, liczba);
              
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


