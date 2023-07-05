// Functional Recursion

#include <iostream>
using namespace std;

int result(int n)
{
    int sum = 0;

    if (n == 0)
    {
        return 0;
    }
    return n + result(n - 1);
}
int main()
{
    cout << result(5) << endl;
}