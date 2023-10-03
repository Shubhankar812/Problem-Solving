#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int> &arr,int n) {
        stack<int> s;
        vector<int> ans(n);
        
        s.push(-1);
        for(int i=n-1;i>=0;i--) {
            int current = arr[i];
            // s.push(current);
            
            while(s.top() != -1 && arr[s.top()] >= current) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> &arr,int n) {
        stack<int> s;
        vector<int> ans(n);
        
        s.push(-1);
        for(int i=0;i<n;i++) {
            int current = arr[i];
            // s.push(current);
            
            while(s.top() != -1 && arr[s.top()] >= current) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>Next(n);
        Next = nextSmaller(heights,n);

        vector<int> Prev(n);
        Prev = prevSmaller(heights,n);

        int area = INT_MIN;

        for(int i=0;i<n;i++) {
            int l = heights[i];

             if(Next[i]==-1) {
                Next[i]=n;
            }
            int b = Next[i]-Prev[i]-1;

           
            int temp = l*b;
            area = max(temp,area);
        }

        return area;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {3,1,2,4};
    int ans = s.largestRectangleArea(heights);

    cout<<ans<<"\n";
}