#include <iostream>
using namespace std;

void print(int n)
{
    // int cnt = 0;
    for (int i=0;i<n; i++)
    {
        char ch = 'A'+i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        // cnt += 1;
        cout << "\n";
    }
}
int main()
{
    int n;
    cin >> n;

    print(n);
}