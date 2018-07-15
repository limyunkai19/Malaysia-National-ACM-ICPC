#include <iostream>

using namespace std;

int factory, layer, ball[600];
int dist[600][600], recycle[600][600], produce[600][600];
long long dp_recycle[600][600], dp_produce[600][600]; // dp[layer][ball at which factory]

int main(){
    cin >> factory >> layer;

    for(int i = 0; i < factory; i++){
        for(int j = 0; j < factory; j++)
            cin >> dist[i][j];

        for(int j = 0; j < layer; j++)
            cin >> produce[i][j];

        for(int j = 0; j < layer; j++)
            cin >> recycle[i][j];
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ball[i];
        ball[i]--;
    }

    // base case
    for(int i = 0; i < factory; i++){
        // produce
        if(produce[i][ball[0]] != -1)
            dp_produce[0][i] = produce[i][ball[0]];
        else
            dp_produce[0][i] = 1LL<<50;

        // recycle
        if(recycle[i][ball[n-1]] != -1)
            dp_recycle[0][i] = recycle[i][ball[n-1]];
        else
            dp_recycle[0][i] = 1LL<<50;
    }

    // recurrence relation
    for(int i = 1; i < n; i++){
        for(int f = 0; f < factory; f++){
            // produce
            dp_produce[i][f] = 1LL<<50;
            if(produce[f][ball[i]] != -1)
                for(int pre_f = 0; pre_f < factory; pre_f++)
                    dp_produce[i][f] = min(dp_produce[i][f],
                                dist[pre_f][f]+produce[f][ball[i]]+dp_produce[i-1][pre_f]);

            // recycle
            dp_recycle[i][f] = 1LL<<50;
            if(recycle[f][ball[n-i-1]] != -1)
                for(int pre_f = 0; pre_f < factory; pre_f++)
                    dp_recycle[i][f] = min(dp_recycle[i][f],
                                dist[pre_f][f]+recycle[f][ball[n-i-1]]+dp_recycle[i-1][pre_f]);
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
