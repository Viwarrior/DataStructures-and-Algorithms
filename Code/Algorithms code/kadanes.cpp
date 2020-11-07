#include <iostream>
using namespace std;
#define f for


int main(){
    int s = 0; 
    int best = 0;
    int a[10];
    cout<<"enter array: \n";
    f(int i = 0 ;i<10;i++)
     cin>>a[i];

     f(int i = 0 ;i<10;i++)
      {
          s = max(a[i],s+a[i]);
          best = max(s,best);
        
      }
      cout<<"\nmax subarray: \n"<<best;
    return 0;
}