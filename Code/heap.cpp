#include <bits/stdc++.h>
using namespace std;

//implementing min heap

#define N 20

class Heap{
private:
    int heapsize;
    int a[N];

public:

    Heap(){
        cout<<"\nHeap created\n";
        heapsize = 0;
    }

    int peek(){
    return a[heapsize];
    }

    bool insert(int value){
    if(heapsize == N){
        return false;
    }

    heapsize++;
    a[heapsize] = value;
    int cur = heapsize;
    int parent = (int)cur/2;
    int temp;

    while(a[cur]<a[parent] and cur > 1){
            temp = a[cur];
            a[cur] = a[parent];
            a[parent] = temp;



        cur = parent;
        parent = (int)cur/2;
    }
    return true;
    }

    void show(){
    for(auto i =1; i<=heapsize;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }

    void extract(){
    //removes root
    a[1] = a[heapsize];
    heapsize--;
    int parent = 1;
    int left = 2*parent;
    int right  = 2*parent +1;
    int temp;
    int flag;
    while(parent <= heapsize and a[parent] > min(a[left],a[right])){
         if(a[parent]>a[left]){
            temp = a[left];
            a[left] = a[parent];
            a[parent] = temp;
            flag = 0;


         }
         if(a[parent]>a[left]){
            temp = a[right];
            a[right] = a[parent];
            a[parent] = temp;
            flag = 1;


         }
         if(flag)
            parent = right;
         else
            parent = left;
        left = 2*parent;
        right  = 2*parent +1;
     }

    }
    ~Heap(){
        cout<<"\nHeap destroyed\n";
        free(a);
    }



};


int main(){
Heap hobj;
hobj.insert(3);
hobj.show();
hobj.insert(4);
hobj.show();
hobj.insert(5);
hobj.show();
hobj.insert(1);

hobj.insert(56);
hobj.insert(23);
hobj.insert(27);
hobj.show();
hobj.extract();
hobj.show();
cout<<hobj.peek();
return 0;
}
