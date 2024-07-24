#include <iostream>
using namespace std;

void print1(int n) {

    if(n==0) {
        return;
    }
    print1(n-1);
    cout<<n<<endl;
}
void print2(int n,int itr) {

    if(n+1==itr) {
        return;
    }
     cout<<itr<<endl;
    print2(n,itr+1);
    
}
int main()
{
    int n;
    cin>>n;

    print1(n);
}