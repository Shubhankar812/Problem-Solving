#include <iostream>
#include <cmath>
using namespace std;

int gcd1(int n,int m) {
    int res=0;
    int mn = min(n,m);

    for(int i=1;i<=mn;i++) {
        if(n%i==0 && m%i==0) {
            res = i;
        }
    }
    return res;
}
int gcd2(int n,int m) {
    while(n>0 && m>0)
    {
        if(n>m) {
            n %= m;
        }
        else{
            m %= n;
        }
    }
    return n;
    
}

int recursiveGCD(int n,int m) {

    if(m==0) {
        return n;
    }
    return recursiveGCD(m,n%m);     // assuming n > m
}
int main()
{
    int n,m;
    cin>>n>>m;

    cout<<recursiveGCD(n,m)<<"\n";
    
}