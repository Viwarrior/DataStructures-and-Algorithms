#include <iostream>
using namespace std;
#include <limits.h>

#define N 10
int max(int x[]){
    int g = INT_MIN;
    for(int i=0;i<N;i++)
    {
        if(x[i]>g)
        g = x[i];
    }
    return g;
}

void countsort(int x[]){
        int g = max(x);
        int freq[20] = {0};
        for(int i =0;i<N;i++){
            freq[x[i]] += 1;
            // cout<<freq[i]<<" d";
        }

        for(int i =1;i<g+1;i++){
            freq[i] += freq[i-1];
            // cout<<freq[i]<<" ";
        }
    int output[N];

    for(int i =0;i<N;i++){
        output[freq[x[i]]-1]= x[i];
        freq[x[i]]--;
    }
        for(int i =0;i<N;i++){
            cout<<output[i]<<" ";
        }
        
    }


void printa(int a[]){
    for(int i = 0 ;i<N;i++)
    {
       cout<<a[i]<<" ";
    }
    cout<<"\n\n";
}

int main()
{
    int a[N];
    cout<<"enter array: \n";
    for(int i = 0 ;i<N;i++)
     cin>>a[i];
   countsort(a);
    //printa(a);
return 0;
}