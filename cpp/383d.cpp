#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
//#define eb emplace_back
//#define em emplace
//#define pob pop_back
//using ld = long double;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

using namespace std;

bool Divisors(int N) {
    ll cnt = 0;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            cnt ++;
            if (i != N / i) {
                cnt ++;
            }
        }
        if(9 < cnt) return false;
    }
    if(cnt != 9) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    ll ans = 0;
    for (int i = 1; i * i <= N; i++) {
        if(Divisors(i * i)) ans ++;
    }
    cout << ans << endl;
    return 0;
}