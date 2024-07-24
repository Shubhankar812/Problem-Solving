#include <iostream>
using namespace std;

void print_n_times_1(string name,int n) {
    
    if(n==0) {
        return;
    }
    cout<<name<<"\n";
    print_n_times_1(name,n-1);
}

void print_n_times_2(string name,int n,int itr) {

    if(itr==n+1) {
        return;
    }
    print_n_times_2(name,n,itr+1);
    cout<<name<<" "<<endl;
}
int main()
{
    string name = "Shubhankar";
    int n;
    cin>>n;
  //  print_n_times_1(name,n);

    print_n_times_2(name,n,1);
}