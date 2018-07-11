#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MOD 1000003

// a x + b y = gcd(a, b)
// ax = 1
// ax = 1 mod b

long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

long long inverse(long long a, long long m){
    long long ans, t;
    extgcd(a, m, ans, t);
    return (ans+MOD)%MOD;
}

long long factorial(long long n){
    long long ans = 1;
    for(long long i = 2; i <= n; i++){
        ans = (ans*i)%MOD;
    }
    return ans;
}

long long fast_exp(long long x, long long e){
    if(e == 0)
        return 1;

    if(e%2 == 0){
        long long k = fast_exp(x, e/2);
        return (k*k)%MOD;
    }
    else{
        return (fast_exp(x, e-1)*x)%MOD;
    }
}

long long x[100100], n;

int main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        long long sum = 0, pow2 = 1;
        for(int i = 0; i < n; i++){
            cin >> x[i];
            sum += x[i];
            pow2 *= fast_exp(2, x[i]-1);
            pow2 %= MOD;
        }

        long long ans = 0;
        ans = factorial(sum);
        for(int i = 0; i < n; i++){
            ans *= inverse(factorial(x[i]), MOD);
            ans %= MOD;
        }

        cout << "Case #" << tc << ": " << (ans*pow2)%MOD << endl;
    }
}
