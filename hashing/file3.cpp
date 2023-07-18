#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> mp;

    mp["Prince"] = 108;
    mp["King"] = 100;
    mp["PM"] = 110;
    mp["Queen"] = 102;
    mp["Princess"] = 106;

    // for(auto it : mp){
    //     cout<<it.first<<"--->"<<it.second<<endl;
    // }
    // cout<<endl;

    // string key = "PM";
    // if(mp.find(key) != mp.end()) {
    //     auto tmp = mp.find(key);
    //     cout<<"Key : "<<tmp->first<<endl;
    //     cout<<"Value : "<<tmp->second<<endl;
    // }
    // else{
    //     cout<<"Key not found..."<<endl;
    // }

    mp.insert({"EAM",112});

    mp.erase("Princess");

    for(auto it : mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<"Size : "<<mp.size()<<endl;
}
