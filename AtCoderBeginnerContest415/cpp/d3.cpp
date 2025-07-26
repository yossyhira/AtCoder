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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int m;
    cin >> n >> m;

    vector<tuple<ll, ll, ll>> num;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        ll d = a - b;
        num.emplace_back(a, b, d);
    }
    //sort(ls.begin(), ls.end());

    sort(num.begin(), num.end(), [](const auto &a, const auto &b) {
        return get<0>(a) < get<0>(b);//第一
    });
    stable_sort(num.begin(), num.end(), [](const auto &a, const auto &b) {
        return get<2>(a) < get<2>(b);//第三
    });
    num.pb({-1, -1, -1});
    int now_idx = 0;
    ll ans = 0;
    while(1){
        ll a, b, d;
        tie(a, b, d) = num[now_idx];
        if(a == -1) break;
        if(n < a){
            now_idx++;
            continue;
        }else{
            ll x = ((n - a) / d) + 1;
            ans += x;
            n = n - (d * x);
        }
    }
    cout << ans << endl;

}