/*Team Name: KitKat*/
#include <iostream>

using namespace std;

int x[20], y[20], mintaken, ra, rb;

int gcd (int a, int b){
    return (b==0?a:gcd (b, a%b));
}

bool test(int a, int b, int c, int d){
    if(a == 0 || b == 0 || c == 0 || d == 0){
        return false;
    }
    int i = gcd(a, b);
    int j = gcd(c, d);
    a /= i; b /= i;
    c /= j; d /= j;

    return (a==c && b==d);
}

void take(int n, int idx, int a, int b, int taken){
    if(idx == n){
        if(test (a, b, ra, rb)){
            mintaken = min(taken, mintaken);
        }
        return;
    }
    take(n, idx+1, a+x[idx], b+y[idx], taken+1);
    take(n, idx+1, a, b, taken);
}

int main(){
    int t, n, a, b, lastidx, bin;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        cin >> ra >> rb;
        mintaken = 100000000;
        take(n, 0, 0, 0, 0);

        cout << "Case #" << tc << ": " << (mintaken==100000000?-1:mintaken) << endl;
    }
    return 0;
}