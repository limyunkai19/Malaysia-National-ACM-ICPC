#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MOD 1000003

int x[100100], n, lefts, ans;

void backtrack(){
    if(lefts == 0){
        ans++;
        return;
    }

    for(int i = 0; i < n; i++){
        if(x[i] > 0){
            if(x[i] == 1){
                x[i]--;
                lefts--;
                backtrack();
                lefts++;
                x[i]++;
            }
            else{
                x[i]--;
                backtrack();
                backtrack();
                x[i]++;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> x[i];
        lefts = n;
        ans = 0;

        backtrack();

        cout << "Case #" << tc << ": " << ans%MOD << endl;
    }
}
