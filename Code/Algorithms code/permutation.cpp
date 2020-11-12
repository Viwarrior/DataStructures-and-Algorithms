#include <bits/stdc++.h>
using namespace std;

//bring the element at i in front permute for rest and then add i.
deque<deque<int>>  permute(deque<int> v){
    deque<deque<int>> ans;
    if(v.size() == 0)
        return ans;
    if(v.size() == 1){
        ans.push_back(v);
        return ans;
    }
    deque<deque<int>> temp;
    int val;

   for(int i=0;i<v.size();i++){
    val =  v[i];
    v.erase(v.begin()+i);
    temp = permute(v);
    v.insert(v.begin()+i,val);

    for(auto x: temp){
        x.push_front(val);
        ans.push_back(x);
    }
   }
    return ans;
}



int main(){
deque<int> a{4,3,6};
deque<deque<int>> ans;
//method 1
ans = permute(a);
for(auto x:ans){
    for(auto y:x){
        cout<<y<<" ";
    }
    cout<<endl;
}

return 0;
}

