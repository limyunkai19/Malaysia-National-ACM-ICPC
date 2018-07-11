/*Team Name: KitKat*/
#include <iostream>

using namespace std;

int main(){
    int t;
    string pw;
    bool ans;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> pw;
        ans = true;
        for(int i = 0; i < pw.size(); i++){
            if(pw[i] != pw[pw.size()-i-1]){
                ans = false;
                break;
            }
        }
        cout << "Case #" << tc << ": ";
        if(ans){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}
