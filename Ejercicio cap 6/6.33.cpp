#include <iostream>
  #include <cstdlib>
  #include <ctime>
  using namespace std;
  int flip (void);
  int main()

 {
  int value, cruz = 0, cara = 0;
  srand (time (NULL));
  cout <<endl<<endl<<"Lanzamiento de una moneda." << endl;
  for (int n =1; n<=100; ++n)
  {
    value = flip();
    if (0 == value)
     {
      cout <<"Cruz\n";
      ++cruz;
     }

     else
     {
      cout <<"Cara"<<endl;
      cara++;
     }
    }
  cout << endl<<"Numero de caras: " << cara << endl;
  cout << "Numero de cruces: "<<cruz<<endl;
  return 0;

  }

 int flip (void)

 {
 return rand() % 2;
 }