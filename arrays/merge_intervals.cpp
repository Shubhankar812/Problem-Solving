#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        int n = intervals.size();

        if (n <= 1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];

        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
    void Print()
    {
        cout << "Hello !";
    }
};

int main()
{
    Solution s;
    // s.Print();

    vector<vector<int>> res = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> answer = s.merge(res);

    for(int i=0;i<answer.size();i++) {
        for(int j=0;j<answer[0].size();j++) {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
}