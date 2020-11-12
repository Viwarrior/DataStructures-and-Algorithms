#include <bits/stdc++.h>
using namespace std;
//first way is to exploit bits
// second method is by recursion
vector<int> mappy(vector<int> a, int i){
    vector<int> ans;
    for(auto j=0;j<a.size();j++){
        if(i&1){
            ans.push_back(a[j]);

        }

        i = i>>1;
    }
    return ans;
}

void withbit(vector<int> a){
    for(auto i=0;i<pow(2,a.size());i++){

        for(auto x: mappy(a,i)){
            cout<<x<<" ";
       }
        cout<<endl;
    }


}

void searchset(int k,vector<int> subset,vector< vector<int> > &ans,int n) {
    if (k == n) {
    ans.push_back(subset);
    } else {
    searchset(k+1,subset,ans,n);
    subset.push_back(k);
    searchset(k+1,subset,ans,n);
    //subset.pop_back(); // necessary if giving by reference subset var
    }
 }

int main(){
vector<int> a{4,2,5};
vector<int> subset;
vector< vector<int> > ans;

//method 1
searchset(0,subset,ans,3);
for(auto x:ans){
    for(auto y:x){
        cout<<y<<" ";
    }
    cout<<endl;
}
//method 2
withbit(a);
return 0;
}

