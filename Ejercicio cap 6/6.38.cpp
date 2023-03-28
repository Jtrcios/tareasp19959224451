#include <conio.h>
#include <iostream>

using namespace std;
void torres_foca(int,int,int,int);

main(){ 
int a; 
cout<<"Torres de Hanoi\n\n"<<endl; 
cout<<"Ingresa el numero de discos : \t";
cin>>a; 
torres_foca(a,1,3,2); 
getch();
}

void torres_foca(int foca,int uno,int tres,int dos){
if(foca==1){  
cout<<"Disco : "<<foca<<" del poste  "<<uno<<" al poste "<<tres<<endl;
getch();  
 } 

else{   
torres_foca(foca-1,uno,dos,tres); 
cout<<"Disco : "<<foca<<" del poste  "<<uno<<" al poste "<<tres<<endl;  
getch(); 
torres_foca(foca-1,dos,tres,uno); 
}
}