#include <iostream>
using namespace std;

void print1(int n) {

    if(n==0) {
        return;
    }
     cout<<n<<endl;
    print1(n-1);
   
}
void print2(int n,int itr) {

    if(n+1==itr) {
        return;
    }
   
    print2(n,itr+1);
      cout<<itr<<endl;
   
}
int main()
{
    int n;
    cin>>n;

    print2(n,1);
}