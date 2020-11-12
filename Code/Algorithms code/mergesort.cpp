#include <iostream>
using namespace std;

#define N 10

void printa(int a[], int n){
for(int i = 0 ;i<n;i++)
    {
       cout<<a[i]<<" ";
    }
    cout<<"\n\n";
}

void merge(int a[],int x1,int y1,int b[],int x2, int y2){
    
    int arr1[30],arr2[30];

    for(int i =0;i<=y1-x1;i++)
    arr1[i] = a[x1+i];

    
    for(int i =0;i<=y2-x2;i++)
    arr1[i] = b[x2+i];

    
    int k = x1;
    int i = 0, j = 0;
    while(i<=y1-x1 && j<=y2-x2){
        if(arr1[i]>arr2[j])
        {
            a[k++] = arr1[j++];
            
        }
        else
             a[k++] = arr2[i++];

    }


    while(i<=y1-x1){
         a[k++] = arr2[i++];
    }

    while(j<=y2-x2){
        a[k++] = arr1[j++];
    }
    
    
}

void mergesort(int x[], int a, int b){
    if(a>=b){
        return;
    }
    int k = (int) (a+b)/2;
    
    mergesort(x,a,k);
    printa(x,N);
    mergesort(x,k+1,b);
    printa(x,N);
    merge(x,a,k,x,k+1,b);
    printa(x,N);
}



int main()
{
    int a[N];
    cout<<"enter array: \n";
    for(int i = 0 ;i<N;i++)
     cin>>a[i];
    // int x[3] = {1,,8};
    // int y[3] = {3,6};
    // merge(x,0,2,y,0,1);
    // printa(x,5);

   mergesort(a,0,9);
    printa(a,N);
return 0;
}