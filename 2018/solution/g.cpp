// understand the problem and implement

#include <iostream>

using namespace std;

const double chicken = 0.8 - (7.5/85 + 8.0/85);
const double beef = 1.0 - (24.0/85 + 8.0/85);
const double lamb = 1.2 - (32.0/85 + 8.0/85);
const double nasi = 0.6;


int main(){
    int n, tc = 1;
    while(cin >> n){
        if(n == 0)
            break;

        double profit = 0;
        while(n--){
            int c, b, l, n;
            cin >> c >> b >> l >> n;

            profit += c*chicken + b*beef + l*lamb + n*nasi;
        }

        printf("Case #%d: RM%0.2lf\n", tc++, profit);

    }


    return 0;
}





