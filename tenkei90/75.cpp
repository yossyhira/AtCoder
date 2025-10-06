#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// √n までの素数列挙（Sieve）
vector<int> sieve(int n) {
    vector<int> f(n + 1, 0);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (f[i] != 0) continue;
        primes.push_back(i);
        f[i] = i;
        if ((ll)i * i <= n) {
            for (ll j = (ll)i * i; j <= n; j += i) {
                if (f[j] == 0) f[j] = i;
            }
        }
    }
    return primes;
}

// n の素因数の個数を返す（重複を数える）
int count_prime_factors(ll n, const vector<int>& primes) {
    int count = 0;
    for (int p : primes) {
        if ((ll)p * p > n) break;
        while (n % p == 0) {
            n /= p;
            count++;
        }
    }
    if (n > 1) count++; // 残った素因数
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    // √n までの素数を事前に作成
    ll limit = sqrtl(n) + 1;
    vector<int> primes = sieve((int)limit);

    int cnt = count_prime_factors(n, primes);
    //cout << cnt << "\n";
    ll hoge = 1, cnt_2 = 0;
    cnt --;
    while(1){
        if(cnt < hoge){
            break;
        }
        cnt_2 ++;
        hoge *= 2;
    }
    cout << cnt_2 << endl;
    return 0;
}
