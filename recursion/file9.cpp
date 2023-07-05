#include <bits/stdc++.h>

using namespace std;

vector<int> A = {1,3,5,7,9};


void Reverse(int start,int end)
{
    if(start>=end){
        return;
    }
    swap(A[start],A[end]);
    Reverse(start+1,end-1);
}
int main()
{
   
   int start=0,end=A.size()-1;

   
   Reverse(start,end);

   for(auto it : A) 
   {
    cout<<it<<endl;
   }
}