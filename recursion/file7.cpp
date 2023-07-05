// Parameterised Recursion

#include <iostream>
using namespace std;


void result(int sum,int i)
{
    if(i < 1)
    {
        cout<<sum<<endl;
        return;
    }
     result(sum+i,i-1);
    // return sum;
}
int main()
{
    result(0,5);
    
}