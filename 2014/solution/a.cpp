/*Team Name: KitKat*/
#include <iostream>

using namespace std;

int main(){
    int t;
    string pw;
    bool letter, space;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> pw;
        cout << "Case #" << tc << ": ";
        letter = space = false;
        if(pw.size() >= 8 && pw.size() <= 15){
            for(int i = 0; i < pw.size(); i++){
                if(isalpha(pw[i])){
                    letter = true;
                }
                else{
                    space = true;
                }
            }
            if(letter && space){
                cout << "Acceptable" << endl;
            }
            else{
                cout << "Not acceptable" << endl;
            }
        }
        else{
            cout << "Not acceptable" << endl;
        }
    }
}
