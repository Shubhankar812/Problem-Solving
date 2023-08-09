#include <bits/stdc++.h>
using namespace std;

bool check1(int n)
{

    // Brute force approach ; TC = O(n)
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool check2(int n)
{

    // Optimal approach ; TC = O(sqrt(n))
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Smallest number except 1 , that is divisible by any number is always a prime number
void factorization_1(int n, vector<int> &factors)
{
    // Brute force approach ; TC = O(n) 
    for(int i=2;i<=n;i++) {
        while(n%i==0) {
            factors.push_back(i);
            n/=i;
        }
    }
}
void factorization_2(int n, vector<int> &factors)
{
    // Optimal approach ; TC = O(sqrt(n)) 
    for(int i=2;i*i<=n;i++) {
        while(n%i==0) {
            factors.push_back(i);
            n/=i;
        }
    }
    if(n>1) {
        factors.push_back(n);
    }
    
}

int main()
{
    int n;
    cin >> n;

    // bool res = check2(n);
    // if (res)
    // {
    //     cout << "Prime number"
    //          << "\n";
    // }
    // else
    // {
    //     cout << "Not a Prime number"
    //          << "\n";
    // }
    vector<int> facts;
    factorization_2(n,facts);

    for(auto it : facts) {
        cout<<it<<" ";
    }
    cout<<endl;
}