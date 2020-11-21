#include <bits/stdc++.h>
using namespace std;

class Hash{

private:
    string store[31];
    int count = 0;
    int length = 31;

public:
    Hash(){
        fill(store, store+31, "*");
        cout<<"Hash table created : \n";
    }

    int calhash1(string s){
        int h = 0;
        for(int i = 0; i<s.length(); i++){
            h  =  h*7 + (int)s[i];

        }
        h = h%length;

        return h;
    }

    int calhash2(string s){
         long long int h = 0;
        for(int i = 0; i<s.length(); i++){
            h += (int)s[i];
        }
        h = h%length;

        return h;
    }

    int search(string s){
        long long int h1 = calhash1(s);
      int h ;
      int r=-1;
      int h2 = calhash2(s);
      for(int i=0; i<length; i++){
            h = (h1 + i*h2)%length;
            if(store[h] == s){
                r = h;
                break;
            }
      }
      return r;
    }

    void insert(string s){
      if(count == length){
        cout<<"table full\n";
        return;
      }
      int h1 = calhash1(s);
      int h;
      int h2 = calhash2(s);
      for(int i=0; i<length; i++){
            h = (h1 + i*h2)%length;
            if(store[h] == "*"){
                store[h] = s;
                break;
            }
      }
      count +=1;
    }

    void show(){
        cout<<endl;
    for(int i =0; i<length;i++){
        cout<<i<<": "<<store[i]<<"\n";
    }

    }

};


int main(){
    Hash h;
    h.insert("avinash");
    h.insert("avinash");
    h.insert("avinas");
    h.insert("vinash");
    h.insert("avinashhhh");
    h.insert("av");
    h.insert("shanavi");
    h.insert("life");
    h.insert("cricket");
    h.show();
    cout<<h.search("asdf")<<endl;
    cout<<h.search("avinash")<<endl;
    cout<<h.search("avinashhhh")<<endl;
return 0;
}
