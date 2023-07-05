// Printing n to 1 using backtracking
#include <iostream>
using namespace std;

void work(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl;
    work(n-1);
}
int main()
{
    int num=5;
    work(num);
}