#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char val;
    bool eow;
    map<char,TrieNode*> r;
    TrieNode(){
    for(int i=0;i<128;i++)
        eow = false;
    }
};

class Trie{
    TrieNode root;
   public:

    Trie(){
    cout<<"Trie created\n\n";
    root.eow = true;
    root.val = '/';

    }

    ~Trie(){
    cout<<"\n\nTrie destroyed";
    }

    void sinsert(string s){
        TrieNode* cur;
        cur = &root;

        for(int i=0;i<s.length();i++){
            if(cur->r.count(s[i])==0){
            TrieNode* t = new TrieNode;
            t->val = s[i];
            cur->r[s[i]] = t;
            }
            cur = cur->r[s[i]];
        }

        cur->eow = true;

    }

    bool ssearch(string s){
        TrieNode* cur;
        cur = &root;
        bool ans = false;
        for(int i=0;i<s.length();i++){
            if(cur->r.count(s[i])==0){
             return ans;
            }
            cur = cur->r[s[i]];
        }
        if(cur->eow == true){
            ans = true;
        }

        return ans;
    }

    bool sdelete(string s){
        bool f = ssearch(s);
        if(f == false)
            return false;
        TrieNode* cur;
        TrieNode* mem;
        char memc;
        cur = &root;
        for(int i=0;i<s.length();i++){
            if(cur->r.size()>2 or cur->eow =true){
                mem = cur;
                memc = s[i];
            }
            cur = cur->r[s[i]];
        }

        mem->r[memc] = nullptr;
        return true;
    }

    void test(){
    cout<<root.r['a']->r['v']->r['i']->r['n']->val;
    }


};



int main(){
 Trie tr;
 tr.sinsert("avina");
  tr.sinsert("avsh");
cout<<tr.ssearch("avina");
//tr.test();
return 0;
}
