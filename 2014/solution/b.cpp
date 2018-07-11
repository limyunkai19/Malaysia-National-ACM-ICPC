/*Team Name: KitKat*/
#include <iostream>

using namespace std;

long long nck[100][100];

int main(){
    for(int i = 0; i < 60; i++){
        nck[i][i] = nck[i][0] = 1;
    }
    for(int i = 1; i < 60; i++){
        for(int j = 1; j < 60; j++){
            nck[i][j] = nck[i-1][j-1]+nck[i-1][j];
        }
    }
    int t, n, k;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n >> k;
        cout << "Case #" << tc << ": ";
        cout << nck[n][k] << endl;
    }

    return 0;
}