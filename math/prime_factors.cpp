#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void print_prime_factors(int n) {
    vector<int> lst;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            while(n%i==0) {
                lst.push_back(i);
                n/=i;
            }
        }
    }
    for(auto it : lst) {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    print_prime_factors(n);
}