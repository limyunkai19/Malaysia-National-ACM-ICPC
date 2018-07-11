#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MOD 1000003

long long dp_fact[MOD+100];

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

long long fast_factorial(long long n){
    long long n1 = n/MOD, n2 = n%MOD;

    long long ans1 = fast_exp(dp_fact[MOD-1], n1);
    long long ans2 = dp_fact[n2]*dp_fact[n1];

    return (ans1 * (ans2%MOD))%MOD;
}

long long count_MOD(long long x){
    long long ans = 0;
    while(x > 0){
        ans += x/MOD;
        x /= MOD;
    }
    return ans;
}

long long x[100100], n;

int main(){
    dp_fact[0] = 1;
    for(int i = 1; i <= MOD; i++){
        dp_fact[i] = (dp_fact[i-1]*i)%MOD;
    }

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        long long sum = 0, pow2 = 1, total_mod = 0;
        for(int i = 0; i < n; i++){
            cin >> x[i];
            sum += x[i];
            pow2 *= fast_exp(2, x[i]-1);
            pow2 %= MOD;
            total_mod += count_MOD(x[i]);
        }

        if(count_MOD(sum) > total_mod){
            cout << "Case #" << tc << ": " << 0 << endl;
            continue;
        }
        long long ans = 0;
        ans = fast_factorial(sum);
        for(int i = 0; i < n; i++){
            ans *= inverse(fast_factorial(x[i]), MOD);
            ans %= MOD;
        }

        cout << "Case #" << tc << ": " << (ans*pow2)%MOD << endl;
    }
}
