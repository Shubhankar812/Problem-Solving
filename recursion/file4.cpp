#include <iostream>
using namespace std;

void Print(int i,int n){
    
    if(i==n){
        return;
    }
    
    Print(i+1,n);

    cout<<i<<endl;
}
int main()
{
   int num=5;
   Print(0,num);

   return 0;
}