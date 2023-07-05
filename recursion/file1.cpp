#include <iostream>
using namespace std;
int count=0;
void fun() {
    if(count==5) {
        return;
    }
    
    cout<<count<<endl;
    count+=1;
    fun();
}
int main()
{
   fun();
}