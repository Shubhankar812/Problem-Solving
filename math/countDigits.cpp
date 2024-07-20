#include <iostream>
using namespace std;

int CountDigits(int n) {
    int cnt=0;

    while (n != 0)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;

    cout<<CountDigits(n)<<endl;
}