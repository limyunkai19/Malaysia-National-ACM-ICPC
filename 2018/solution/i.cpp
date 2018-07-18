// O(NF^2) = O(n^3) dp where n <= 500

#include <iostream>

using namespace std;

int factory, layer, layers[600];
long long dist[600][600], recycle[600][600], produce[600][600];
long long dp_recycle[600][600], dp_produce[600][600]; // dp[layer][ball at which factory]

int main(){
    cin >> factory >> layer;

    for(int i = 0; i < factory; i++){
        for(int j = 0; j < factory; j++)
            cin >> dist[i][j];

        for(int j = 0; j < layer; j++){
            cin >> produce[i][j];
            if(produce[i][j] == -1)
                produce[i][j] = 1LL<<50;
        }

        for(int j = 0; j < layer; j++){
            cin >> recycle[i][j];
            if(recycle[i][j] == -1)
                recycle[i][j] = 1LL<<50;
        }

    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> layers[i];
        layers[i]--;
    }

    // base case
    for(int i = 0; i < factory; i++){
        // produce
        dp_produce[0][i] = produce[i][layers[0]];

        // recycle
        dp_recycle[0][i] = recycle[i][layers[n-1]];
    }

    // recurrence relation
    for(int l = 1; l < n; l++){
        for(int f = 0; f < factory; f++){
            // produce
            dp_produce[l][f] = 1LL<<50;
            for(int i = 0; i < factory; i++)
                dp_produce[l][f] = min(dp_produce[l][f],
                        dist[i][f]+produce[f][layers[l]]+dp_produce[l-1][i]);

            // recycle
            dp_recycle[l][f] = 1LL<<50;
            for(int i = 0; i < factory; i++)
                dp_recycle[l][f] = min(dp_recycle[l][f],
                        dist[i][f]+recycle[f][layers[n-l-1]]+dp_recycle[l-1][i]);
        }
    }

    long long produce_cost = 1LL<<50, recycle_cost = 1LL<<50;
    for(int i = 0; i < factory; i++){
        produce_cost = min(produce_cost, dp_produce[n-1][i]);
        recycle_cost = min(recycle_cost, dp_recycle[n-1][i]);
    }

    cout << produce_cost+recycle_cost << endl;

    return 0;
}
