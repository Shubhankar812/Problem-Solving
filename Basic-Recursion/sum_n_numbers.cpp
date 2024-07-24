#include <iostream>
using namespace std;

int ans = 0;
int sum1(int n) {
    
    if(n==0) {
        return 0;
    }
    ans+=n;
    return sum1(n-1);
}
int sum2(int n) {
    if(n==0) {
        return 0;
    }
    return n+sum2(n-1);
}
int main()
{
    int n;
    cin>>n;
    
    // int res = sum1(n);
    int result = sum2(n);
    cout<<result<<"\n";
}