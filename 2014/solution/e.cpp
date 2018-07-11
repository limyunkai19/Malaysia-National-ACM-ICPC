/*Team Name: KitKat*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
vector< vector<ii> > graph;
vector<int> sub;
int mst_cost, u, w;
priority_queue<ii, vector<ii>, greater<ii> > pq;
bool taken[50010];

int main(){
    int n, v, e, from, to, weight, l;
    cin >> n;
    for(int tc=1; tc<=n; tc++){
        cin >> v >> e;
        graph.assign(v, vector<ii> () );
        sub.clear();
        memset(taken, 0, sizeof taken);
        for(int i=0; i<e; i++){
            cin >> from >> to >> weight;
            graph[from-1].push_back(ii(to-1, weight));
            graph[to-1].push_back(ii(from-1, weight));
        }

        mst_cost = 0;
        cin >> l;
        while(l--){
            cin >> w;
            w--;
            taken[w] = true;
            sub.push_back(w);
        }

        if(v == 2){
            cout << "Case #" << tc << ": " << graph[0][0].second << endl;
            continue;
        }

        for(int i = 0; i < sub.size(); i++){
            e = 10000000;
            for(int j = 0; j < graph[sub[i]].size(); j++){
                if(!taken[graph[sub[i]][j].first]){
                    e = min(e, graph[sub[i]][j].second);
                }
            }
            if(e == 10000000){
                mst_cost = -1;
                break;
            }
            else{
                mst_cost += e;
            }
        }
        if(mst_cost == -1){
            cout << "Case #" << tc << ": " << -1 << endl;
            continue;
        }
        for(int i = 0; i < v; i++){
            if(!taken[i]){
                taken[i] = true;
                for(int j = 0; j < graph[i].size(); j++){
                    if(!taken[graph[i][j].first]){
                        pq.push(ii(graph[i][j].second, graph[i][j].first));
                    }
                }
                break;
            }
        }
        while(!pq.empty()){
            ii front = pq.top(); pq.pop();
            u = front.second;
            w = front.first;
            if(!taken[u]){
                mst_cost += w;
                taken[u] = 1;
                for(int j=0; j < graph[u].size(); j++){
                    ii vv = graph[u][j];
                    if(!taken[vv.first]) pq.push(ii(vv.second, vv.first));
                }
            }
        }
        for(int i = 0; i < v; i++){
            if(!taken[i]){
                mst_cost = -1;
            }
        }
        cout << "Case #" << tc << ": " << mst_cost << endl;
    }
}