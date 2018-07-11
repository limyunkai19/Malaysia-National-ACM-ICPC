/*Team Name: KitKat*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

vector<ii> timeslot;
vector<ii> ans;

int main(){
    int t, maxtime, s, e, num, cure;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> maxtime;
        if(tc > 1) cout << endl;
        cout << "Case #" << tc << ": ";
        timeslot.clear();
        ans.clear();
        while(cin >> s >> e){
            if(s == 0 && e == 0){
                break;
            }
            if(e <= maxtime){
                timeslot.push_back(ii(e, s));
            }
        }
        if(timeslot.size() == 0){
            cout << "0" << endl;
            continue;
        }
        sort(timeslot.begin(), timeslot.end());
        num = 0;
        cure = 0;
        for(int i = 0; i < timeslot.size(); i++){
            if(timeslot[i].second >= cure){
                cure = timeslot[i].first;
                ans.push_back(ii(timeslot[i].second, timeslot[i].first));
            }
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }
}