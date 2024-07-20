#include <iostream>
#include <cmath>
using namespace std;

int Reverse(int n) {
    int num=0;

    while(n != 0) {
        int last_digit = n % 10;
        num = last_digit + num*10;
        n/=10; 
    }
    return num;
}
int main()
{
    int n;
    cin>>n;

    int rev = Reverse(n);

    if(n==rev) {
        cout<<"Palindrome number\n";
    }
    else{
        cout<<"Not a palindrome number\n";
    }
}