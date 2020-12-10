#include <bits/stdc++.h>
using namespace std;










  bool sortbythird(const tuple<int, int, int>& a,
               const tuple<int, int, int>& b)
{
    return (get<2>(a) < get<2>(b));
}


class Graphlist{
vector< pair<int,int>> base[10];

public:
    void add(int source, int dest, int w=1){
    base[source].push_back({dest,w});
    }



    void bfs(int node){
        cout<<"BFS"<<endl;
    int visited[10] = {0};
    int distance[10] = {0};
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
        cout<<"DFS "<<endl;
        int visited[10] = {0};

        depthsearch(node, visited);
        cout<<endl;
    }

    void dijkstra(int node){
        cout<<endl;
        int distance[10];
        fill(distance, distance+10,500);
        distance[node] =0;
        int visited[10] = {0};
        deque <pair<int, int>> p;
        make_heap(p.begin(),p.end());
        p.push_back({0,node});
        push_heap(p.begin(),p.end());

        while(!p.empty()){
            pair<int,int> u = p.front();
            p.pop_front();
            pop_heap(p.begin(),p.end());
            if(visited[u.second]) continue;
            visited[u.second] = 1;
            for(auto x: base[u.second]){
                distance[x.first] = min(distance[x.first], distance[u.second]+x.second);
                p.push_back({-1*distance[x.first],x.first});
                push_heap(p.begin(),p.end());
            }

        }
        cout<<"Dijkstra minimum distance from "<<node<<endl;
        for(int i=0; i<10; i++){
                if(distance[i]!= 0 and distance[i]!= 500)
           cout<<"Node "<<i<<" with distance "<<distance[i]<<endl;

        }
    }

    void prims(int node){
        cout<<endl;
        int distance[10];
        fill(distance, distance+10,500);
        distance[node] =0;
        int visited[10] = {0};
        deque <pair<int, int>> p;
        make_heap(p.begin(),p.end());
        p.push_back({0,node});
        push_heap(p.begin(),p.end());

        while(!p.empty()){
            pair<int,int> u = p.front();
            p.pop_front();
            pop_heap(p.begin(),p.end());
            if(visited[u.second]) continue;
            visited[u.second] = 1;
            for(auto x: base[u.second]){
                distance[x.first] = min(distance[x.first], x.second); //only diff from dijkstra
                p.push_back({-1*distance[x.first],x.first});
                push_heap(p.begin(),p.end());
            }

        }
        cout<<"spanning tree using prims: "<<endl;
        for(int i=0; i<10; i++){
            if(distance[i]!= 0 and distance[i]!= 500)
            cout<<"originating from "<<i<<" with weight "<<distance[i]<<endl;
        }

    }

};










class Graphedgelist{
vector<tuple<int,int,int>> base;

 public:
     void add(int a, int b, int w=1){
        base.push_back(make_tuple(a,b,w));
     }


     void bellmanford(int node){
         cout<<"Bellman Ford: "<<endl;
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

    int find_r(int x,int (&link)[10]){
        while(link[x]!= x) x =link[x];

        return x;
    }

    bool same(int a, int b, int (&link)[10]){
        if(find_r(a, link) == find_r(b, link))
            return true;
        return false;
    }

    void unite(int a, int b, int (&link)[10]){
    a = find_r(a,link);
    b = find_r(b, link);
    link[a] = b;
    }



     void krushkals(){
    cout<<endl<<"Krushkals algorithm "<<endl;
    int link[10];
    for(int i=0; i<10; i++){
        link[i] = i;
    }
    sort(base.begin(),base.end(),sortbythird);
    int a,b,c;
    for(int i =0; i<base.size();i++){
        tie(a,b,c)= base[i];

        if(!same(a,b, link)){ unite(a,b, link); cout<<a<<"->"<<b<<endl; }
         //cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    }

    for(int i =0; i<10; i++)
        cout<<"next of "<<i<<" is "<<link[i]<<endl;
     }



};










class Graphmatrix{
    int base[10][10];

public:
    Graphmatrix(){
    for(int i=0;i<10; i++)
    for(int j=0; j<10; j++)
        base[i][j] = 500;
    }

    void show(){
    for(int i=0;i<10; i++) {
    for(int j=0; j<10; j++){
        cout<<base[i][j]<<" ";
        }
        cout<<endl;
    }
    }

    void add(int a, int b, int w){
     base[a][b] = w;
    }

    void floydwarshall(){
        cout<<"Floyd Warshall"<<endl;
    int distance[10][10];
    memcpy (distance, base, 10*10*sizeof(int));
     for(int i=0;i<10;i++)
        distance[i][i] = 0;


     for(int k=0;k<10;k++)
        for(int i=0;i<10; i++)
     for(int j=0; j<10; j++){
        distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
     }
         for(int i=0;i<10; i++){
     for(int j=0; j<10; j++){
        cout<<distance[i][j]<<" ";
     }
     cout<<endl;
    }
    }


};


int main(){
/*
0 - 1 - 2
|\5 |   |
7   4 - 3
 */
Graphlist g;
g.add(0,1,2);
g.add(0,7,5);
g.add(0,5,6);
g.add(1,2,1);
g.add(1,4,3);
g.add(4,3,7);
g.add(2,3,2);

g.dfs(0);
g.bfs(0);
g.dijkstra(0);
g.prims(0);


Graphedgelist p;
p.add(0,1,2);
p.add(0,7,5);
p.add(0,5,6);
p.add(1,2,1);
p.add(1,4,3);
p.add(4,3,7);
p.add(2,3,2);
p.krushkals();

p.bellmanford(0);
cout<<endl;
Graphmatrix  m;
m.add(0,1,2);
m.add(0,7,5);
m.add(0,5,6);
m.add(1,2,1);
m.add(1,4,3);
m.add(4,3,7);
m.add(2,3,2);
m.show();
m.floydwarshall();
return 0;
}
