#include <iostream>
using namespace std;

void display(int n, int c)
{
  if(c==n){
    return;
  }
  cout<<"Shubhankar"<<endl;
  c++;
  display(n,c);
}
int main()
{
   int n;
   cin>>n;
   int cnt=0;
   display(n,cnt);
}