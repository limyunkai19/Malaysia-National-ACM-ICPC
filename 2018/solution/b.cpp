// classic tsp dp, O(k^2 * 2^k) + O(k^2 * (n+m)log n)

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> li;

int n, m, k;
vector<vector<ii> > graph;
int item_start[20], item_end[20];
long long dist[20][20];

long long dijkstra(int start, int end){
    vector<ll> dist(n+1, 1LL<<60);
    priority_queue<li, vector<li>, greater<li> > pq;

    dist[start] = 0;
    pq.push(li(0, start));

    while(!pq.empty()){
        int u = pq.top().second;
        ll d = pq.top().first;

        pq.pop();
        if(dist[u] != d)
            continue;

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            ll w = graph[u][i].second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(li(dist[v], v));
            }
        }
    }

    if(dist[end] >= 1LL<<60)
        dist[end] = -1;

    return dist[end];
}

// dp[bitmask][cur_pos]
long long dp[1<<18][18];
long long tsp(int u, int bitmask){
    if(bitmask == (1<<k)-1)
        return dp[bitmask][u] = 0;

    if(dp[bitmask][u] != -1)
        return dp[bitmask][u];

    ll ans = 1LL<<60;
    for(int i = 0; i < k; i++){
        if( (bitmask&(1<<i)) == 0){
            // not visited, try visit
            ans = min(ans, dist[u][i]+tsp(i, bitmask|(1<<i)));
        }
    }
    return dp[bitmask][u] = ans;
}

int main(){
    cin >> n >> m >> k;

    graph.assign(n+1, vector<ii> ());

    for(int i = 0; i < m; i++){
        int u, v, l;
        cin >> u >> v >> l;
        graph[u].push_back(ii(v, l));
        graph[v].push_back(ii(u, l));
    }

    long long ans = 0;
    for(int i = 0; i < k; i++){
        cin >> item_start[i] >> item_end[i];

        // item_start -> item_end is a must
        long long d = dijkstra(item_start[i], item_end[i]);
        if(d == -1){
            cout << -1 << endl;
            return 0;
        }
        ans += d;
    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            dist[i][j] = dijkstra(item_end[i], item_start[j]);
            if(dist[i][j] == -1){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    memset(dp, -1, sizeof dp);
    long long tsp_ans = 1LL<<60;
    for(int i = 0; i < k; i++){
        dp[1<<i][i] = tsp(i, 1<<i);
        tsp_ans = min(tsp_ans, dp[1<<i][i]);
    }

    cout << ans+tsp_ans << endl;

    return 0;
}
