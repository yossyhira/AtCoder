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
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"No"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7; //ll % modしても自動でmod型変換でllなるからバグらないよ

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll m;
    cin >> m;
    vector<ll> num(n);
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    const int mx = 10;

    vector<ll> pw(mx + 1);
    for (int i = 0; i <= mx; i++) {
        ll a = 1;
        for (int j = 0; j < i; j++) {
            a *= 10;
        }
        pw[i] = a % m;
    }

    vector<unordered_map<ll, ll>> mp(mx + 1);
    for (int i = 0; i < n; i++) {
        ll a_mod = num[i] % m;
        for (int j = 1; j <= mx; j++) {
            ll md = (a_mod * pw[j]) % m;
            mp[j][md]++;
        }
    }
    auto len = [&](ll x){
        int cnt = 0;
        while (0 < x) {
            cnt ++;
            x /= 10;
        }
        return cnt;
    };

    ll ans = 0;
    for (int j = 0; j < n; j++) {
        int l = len(num[j]);          
        ll j_mod = num[j] % m;
        //cout << j_mod << endl;
        ll look = m - j_mod;
        //cout << look << endl;
        if(j_mod == 0) look = 0;

        if (mp[l].count(look)) {
            ans += mp[l][look];
        }
    }
    cout << ans << endl;
}