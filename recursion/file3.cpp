#include <iostream>
using namespace std;

void Print(int i, int n)
{
   if(i==n){
    return;
   }
  
   cout<<i<<endl;
    Print(i+1,n);
}
int main()
{
    int num = 5;
    Print(0,num);
}