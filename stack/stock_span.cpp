//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stock's price for all n days.
    void NGL(int p[],vector<int> &res,int n) {      // NGL --- Nearest Greater to Left
        stack<pair<int,int>> s;
        
        for(int i=0;i<n;i++) {
            if(s.size() == 0) {
                res.push_back(-1);
            }
            else if(s.size() > 0 && s.top().first > p[i]) {
                res.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first <= p[i]) {
                while(s.size()>0 && s.top().first <= p[i]) {
                    s.pop();
                }
                if(s.size()==0){
                    res.push_back(-1);
                }
                else{
                    res.push_back(s.top().second);
                }
            }
            s.push({p[i],i});
        }
    }
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       NGL(price,ans,n);
       
       
       for(int i=0;i<ans.size();i++) {
           ans[i] = i-ans[i];
       }
       
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends