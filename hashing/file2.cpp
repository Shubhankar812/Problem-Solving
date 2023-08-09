#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Size : " << s.size() << endl;

    // s.clear();

    // cout<<"Size : "<<s.size()<<endl;

    int key = 30;

    if (s.find(key) == s.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
    int deleted_key;
    cin >> deleted_key;

    s.erase(deleted_key);
    for (auto it : s)
    {
        cout << it << " ";
    }

    cout << endl;

    int element;
    cin >> element;
    if (s.count(element))
    {
        cout << "Key found..."
             << "\n";
    }
    else
    {
        cout << "Key not found..."
             << "\n";
    }
}