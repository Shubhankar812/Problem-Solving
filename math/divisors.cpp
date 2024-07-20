#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void print_divisors(int n) {
    
    for(int i=1;i<n;i++) {
        if(n%i==0 && i != 1) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
bool isPrime(int m) {
    if(m==1) {
        return false;
    }
    for(int i=2;i<=sqrt(m);i++) {
        if(m%i==0) {
            return false;
        }
    }
    return true;
}
void print_prime_divisors(int n) {
    for(int i=1;i<n;i++) {
        if(n%i==0 && isPrime(i)) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;

    print_prime_divisors(n);
}