#include <bits/stdc++.h>
using namespace std;


class Graphlist{
vector< pair<int,int>> base[10];

public:
    void add(int source, int dest, int w=1){
    base[source].push_back({dest,w});
    }



    void bfs(int node){
        cout<<endl;
    int visited[10] = {0};
    int distance[10] = {INT_MAX};
    deque<int> q;
    q.push_front(node);
    distance[node] = 0;
    visited[node] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        cout<<u<<" ";
        for(auto x: base[u]){
                if(visited[x.first]) continue;
            q.push_back(x.first);
            visited[x.first] = 1; // important
            distance[x.first] = distance[u] + 1;
            }
        }
        cout<<endl;
    //for(int i=0; i<10; i++)
     //   cout<<"distance "<<i<<":"<< distance[i]<<" ";

    }





    void depthsearch(int node, int (&visited)[10]){
    if(visited[node]) return;
    cout<<node<<" ";
    visited[node] = 1;
    for(auto u: base[node]){
        depthsearch(u.first, visited);
         visited[u.first] = 1;
        }

    }



    void dfs(int node){
        int visited[10] = {0};
        cout<<visited[2];
        depthsearch(node, visited);
    }


};

class Graphedgelist{
vector<tuple<int,int,int>> base;

 public:
     void add(int a, int b, int w=1){
        base.push_back(make_tuple(a,b,w));
     }


     void bellmanford(int node){
         int distance[10];
         fill(distance, distance+10,500); // big no 500 to repr inf
         distance[node] = 0;

        int x,y,w;
        for(int i=0;i<9;i++){
            for(auto a: base){
                tie(x,y,w) = a;
                distance[y] = min(distance[y], distance[x]+w);

            }
        }
        cout<<endl;
        for(int i=0; i<10; i++)
            cout<<distance[i]<<" ";



     }



};

int main(){
Graphlist g;
g.add(0,1);
g.add(0,7);
g.add(0,5);
g.add(1,2);
g.add(1,4);
g.add(4,3);
g.add(2,3);
g.dfs(0);
g.bfs(0);

Graphedgelist p;
p.add(0,1,2);
p.add(0,7,5);
p.add(0,5,6);
p.add(1,2,1);
p.add(1,4,3);
p.add(4,3,7);
p.add(2,3,2);

p.bellmanford(1);
return 0;
}
