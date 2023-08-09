#include <bits/stdc++.h>
#define m 1e9 + 7

using namespace std;

void solve1(int n)
{
    // Brute force approach ; TC = O(n)
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void solve2(int n)
{
    // optimized approach ; TC = O(sqrt(n))
    for(int i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            cout<<i<<" "<<(n/i);
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin >> n;

    solve2(n);
}