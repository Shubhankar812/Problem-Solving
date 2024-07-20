#include <iostream>
#include <cmath>
using namespace std;

int Reverse_and_Cubed(int n) {
    int num=0;

    while(n != 0) {
        int last_digit = n % 10;
        num += pow(last_digit,3);
        n/=10; 
    }
    return num;
}
int main()
{
    int n;
    cin>>n;

    int m = Reverse_and_Cubed(n);

    if(n==m) {
        cout<<"It is a Palindrome number\n";
    }
    else{
        cout<<"It is not a Palindrome number\n";
    }
   
}