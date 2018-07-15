// naive O(n^3) implementation of matric multiplication

#include <iostream>

using namespace std;

int a[30][30], b[30][30];
int r1, c1, r2, c2;

int c(int i , int j){
    int ans = 0;
    for(int k = 0; k < c1; k++){
        ans += a[i][k] * b[k][j];
    }
    return ans;
}

int main(){
    int tc = 1;
    while(cin >> r1 >> c1 >> r2 >> c2){
        if(r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
            break;

        cout << "Case #" << tc++ << ":" << endl;
        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                cin >> a[i][j];
        for(int i = 0; i < r2; i++)
            for(int j = 0; j < c2; j++)
                cin >> b[i][j];

        if(r2 != c1){
            cout << "undefined" << endl;
            continue;
        }

        for(int i = 0; i < r1; i++){
            cout << "| ";
            for(int j = 0; j < c2; j++){
                cout << c(i, j) << ' ';
            }
            cout << "|\n";
        }
    }

    return 0;
}
