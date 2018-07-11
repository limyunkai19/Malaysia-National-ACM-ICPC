/*Team name: KitKat*/

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

queue<int> q;

int main(){
    int t, n, m, curmin, served, maxwait, totalwait, mechtime;
    double ave;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        curmin = served = 0;
        for(int i = 0; i < n; i++){
            cin >> m;
            curmin += m;
            if(curmin <= 240){
                q.push(curmin);
                served++;
            }
        }
        maxwait = totalwait = 0;
        if(!q.empty()){
            mechtime = q.front (); q.pop();
        }
        while(!q.empty()){
            m = q.front(); q.pop();
            mechtime += 13;
            if(m < mechtime){
                totalwait += mechtime - m;
                maxwait = max(maxwait, mechtime-m);
            }
            else{
                mechtime = m;
            }
        }
        if(served == 0){
            ave = 0.0;
        }
        else{
            ave = ((double)(totalwait))/((double)(served));
        }

        printf("Case #%d: %d %d %.2lf\n", tc, served, maxwait, ave);
    }
}