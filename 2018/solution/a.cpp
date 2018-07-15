// O(MN^2) solution, can be improve to O(NM) using linked list or skip table

#include <iostream>

using namespace std;

bool selected[2000];

int main(){
    int n, m;

    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;

        for(int i = 1; i <= n; i++)
            selected[i] = false;

        int cur = 0;
        // loop n-1 time, kick 1 person each time
        for(int i = 0; i < n-1; i++){
            // skip m times and find the next person to kick
            for(int j = 0; j < m; j++){
                cur += 1;
                if(cur == n+1)
                    cur = 1;

                // need to find a non selected person, decrease loop counter
                if(selected[cur])
                    j--;
            }

            // cur is the person we want to kick
            selected[cur] = true;
        }

        // find the last person left
        for(int i = 1; i <= n; i++){
            if(!selected[i])
                cout << i << endl;
        }
    }



    return 0;
}
