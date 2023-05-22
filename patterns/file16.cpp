#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = 0; i <= n; i++)
    {
        // spaces
        for (int j = 0; j <= n-i-1; j++)
        {
            cout << " ";
        }

        //charater
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for (int j = 1; j <= 2*i + 1; j++)
        {
            cout<<ch<<"";

            if(breakpoint >= j) {
                ch++;
            }
            else{
                ch--;
            } 
        }

        // spaces
        for (int j = 0; j <= n-i-1; j++)
        {
            cout << " ";
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