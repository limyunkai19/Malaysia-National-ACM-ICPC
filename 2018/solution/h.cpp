// understanding and implementation

#include <iostream>
#include <map>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        string s;
        bool stroop = true;
        map<string, int> fre;

        char a = '.', b = '.', pre_a = '.', pre_b = '.';
        while(cin >> s && s != "00"){
            fre[s]++;

            // check consecutive
            if(a == pre_a && a == s[0])
                stroop = false;
            if(b == pre_b && b == s[1])
                stroop = false;

            pre_a = a;  pre_b = b;
            a = s[0];   b = s[1];
        }

        int congruent = fre["11"], incongruent = fre["12"];

        // check congruent vs incongruent frequency
        if(congruent * 4 != incongruent * 12)
            stroop = false;

        // check among group frequency
        string stimuli = "..";
        for(stimuli[0] = '1'; stimuli[0] <= '4'; stimuli[0]++){
            for(stimuli[1] = '1'; stimuli[1] <= '4'; stimuli[1]++){
                if(stimuli[0] == stimuli[1]){
                    if(fre[stimuli] != congruent)
                        stroop = false;
                }
                else{
                    if(fre[stimuli] != incongruent)
                        stroop = false;
                }
            }
        }

        cout << "Case #" << t << ": " << (stroop?"Stroop":"Not Stroop") << endl;
    }

    return 0;
}
