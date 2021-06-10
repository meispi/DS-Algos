#include<iostream>
#include<vector>
#include<climits>
// #include<
using namespace std;
void printsol(vector<int> ans, int n){
    cout << "Vertex \tDistance from Source\n";
    for(int i = 0;i < n;i++)
        cout << i << " \t" << ans[i] << "\n";
}

int minDist(vector<int> dist, vector<bool> spt, int n){
    int minval = INT_MAX, minindex;
    for(int i = 0;i < n;i++){
        if(dist[i] < minval && !spt[i]){
            minval = dist[i];
            minindex = i;
        }
    }
    return minindex;
}

vector<int> dijkstra(vector<vector<int>> graph, int src, int n){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<bool> spt(n,false);
    int u;
    for(int i = 0;i < n;i++){
        u = minDist(dist,spt,n);
        spt[u] = true;

        for(int j = 0;j < n;j++){
            if(graph[u][j] && !spt[j] && dist[u] != INT_MAX && dist[j] > dist[u]+graph[u][j])
                dist[j] = dist[u]+graph[u][j];
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> graph = {
                                 {0,4,0,0,0,0,0,8,0},
                                 {4,0,8,0,0,0,0,11,0},
                                 {0,8,0,7,0,4,0,0,2},
                                 {0,0,7,0,9,14,0,0,0},
                                 {0,0,0,9,0,10,0,0,0},
                                 {0,0,4,14,10,0,2,0,0},
                                 {0,0,0,0,0,2,0,1,0},
                                 {8,11,0,0,0,0,1,0,7},
                                 {0,0,2,0,0,0,0,7,0}
                                };
    int n = graph.size();
    vector<int> ans = dijkstra(graph,0,n);
    printsol(ans, n);
}