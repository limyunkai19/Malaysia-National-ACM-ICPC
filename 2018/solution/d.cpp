// mst, prims algorithm, O(Elog E)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main(){
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; t++){
        int n, m;
        cin >> n >> m;

        vector<vector<ii> > graph(n);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;

            graph[u-1].push_back(ii(v-1, w));
            graph[v-1].push_back(ii(u-1, w));
        }

        int mst = 0;
        vector<bool> visited(n, false);
        priority_queue<ii, vector<ii>, greater<ii> > pq;

        pq.push(ii(0, 0));

        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second;
            pq.pop();

            if(visited[u])
                continue;

            mst += d;
            visited[u] = true;

            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i].first, w = graph[u][i].second;
                if(!visited[v]){
                    pq.push(ii(w, v));
                }
            }
        }

        cout << "Case #" << t << ": " << mst << " meters" << endl;
    }

    return 0;
}
