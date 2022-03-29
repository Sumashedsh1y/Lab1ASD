#include <iostream>
#include "generator.h"
#include <fstream>
using namespace std;


// метод печатает что угодно, у чего есть возможность запускать цикл for (auto x: )
//template <class T>
//void Print(T someList) {
//   for (auto &x: someList) cout<<" "<<x;
//   cout<<endl;
//}

int main() {
   cout<<"10!="<<Factorial(10)<<endl;
   cout << endl;
   Generator g(36);
   g.GenerateAll();
   g.GetCount();
   cout << endl;
   Generator q(36);
   q.GenerateRec();
   q.GetCount();
   //std::vector<int> result = g.GetResult(5); // 5-я последователность
   
   //for (int x: result) cout<<" "<<x;  cout<<endl;

   //g.Print(result);

   return 0;
}