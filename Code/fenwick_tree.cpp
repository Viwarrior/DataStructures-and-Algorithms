#include <bits/stdc++.h>
using namespace std;

class FenwickTree{
    int tree[30];
    int n;
public:
    FenwickTree(int a[], int l){
    n = l;
    preprocess(a);
    cout<<"Tree created and indexed.\n";

    }

    void preprocess(int a[]) {
        int s;
        int pk;
        for(int k=1;k<=n;k++){
            s = 0;
            pk = k&(-1*k); // bit result

            for(int i=k-pk+1;i<=k;i++)
                s += a[i];

            tree[k] = s;
            cout<<s<<" ";
        }
    }

    int sum(int k){
        int s = 0;
        while(k>=1){
        s += tree[k];
        k -= k&(-1*k);
        }
    return s;
    }

    int rangeSum(int a, int b){
        cout<<endl;
    return sum(b) - sum(a-1); // to make a inclusive a-1
    }

    void updateX(int x, int k){
        //updates a value at k by x in logn time
        while(k<=n){

        tree[k] -= x;
        k += k&(-1*k); //will only affect sums at these ks
        }

    return;
    }
};

int main(){
    int a[6] = {0,1,3,5,7,2}; //1-indexed 0 ignored
FenwickTree f(a,5);
cout<<f.sum(3);
cout<<f.rangeSum(2,5); //[a,b]
f.updateX(5,2); // subtract 5 from value at 2
cout<<f.rangeSum(1,4);
return 0;
}
