// O(n) dp

#include <iostream>

using namespace std;

int dp[100];

int main(){
    dp[1] = dp[2] = 0;
    dp[3] = 1; dp[4] = dp[5] = 2;
    for(int i = 6; i < 80; i++){
        dp[i] = dp[i-2]+dp[i-3];
    }


    int n, tc = 1;
    while(cin >> n){
        if(n == 0)
            break;
        cout << "Case #" << tc++ << ": " << dp[n]+dp[n-1] << endl;
    }

    return 0;
}
