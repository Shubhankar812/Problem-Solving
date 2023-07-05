// Printing 1 to n using backtracking

#include <iostream>
using namespace std;

void work(int n)
{
    if(n==0) {
        return;
    }
   work(n-1);
   cout<<n<<endl;
}
int main()
{
    int num = 5;

    work(5);
}