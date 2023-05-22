#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (char j = 'A'; j < 'A' + i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin >> n;

    print(n);
}