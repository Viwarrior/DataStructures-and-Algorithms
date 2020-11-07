#include <iostream>
using namespace std;

#define N 5
int *merge(int a[],int x1,int y1,int b[],int x2, int y2){
    int t;
    while(x1!=y1 && x2!=y2){
        if(a[x1]>b[x2])
        {
            t= a[x1];
            a[x1] = b[x2];
            b[x2] =t;
            x1++;
        }
        else
            x2++;
    }
    
}

void mergesort(int x[], int a, int b){
    if(a==b){
        return;
    }
    int k = (int) (a+b)/2;
    int array1[20], array2[20];
    mergesort(x,a,k);
    mergesort(x,k+1,b);
    merge(x,a,k,x,k+1,b);
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
   mergesort(a,0,9);
    printa(a);
return 0;
}