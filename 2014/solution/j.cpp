/*Team Name: KitKat*/
#include <iostream>

using namespace std;

string base_n(int n, int b){
    if(n == 0){
        return "0";
    }
    string ans;
    while(n > 0){
        ans += ((n%b)+'0');
        n /= b;
    }
    return string(ans.rbegin(), ans.rend());
}

int main(){
    int t, b, n;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> b >> n;
        cout << "Case #" << tc << ":";
        for(int i = 0; i < n; i++){
            cout << ' ' << base_n(i, b);
        }
        cout << endl;
    }
}