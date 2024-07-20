#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
bool isPrime(int n) {
    if(n==1) {
        return false;
    }
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
void print_primes_till_num(int n) {
    for(int i=2;i<=n;i++) {
       if(isPrime(i)) {
        cout<<i<<" ";
       }
    }
    cout<<endl;
}
*/

void sieve_algo(int n) {
    vector<bool> isPrime(n+1,true);

    for(int i=2;i*i<=n;i++) {
        if(isPrime[i]==true) {
            for(int j=i*i;j<=n;j+=i) {
                isPrime[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++) {
        if(isPrime[i]==true) {
            cout<<i<<" ";
        }
    }
    cout<<endl;

}
int main()
{
    int n;
    cin>>n;

    //print_primes_till_num(n);
    sieve_algo(n);

}