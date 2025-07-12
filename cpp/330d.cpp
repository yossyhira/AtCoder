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
    int n;
    cin >> n;
    vector<string> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    vector<int> y_cnt(n);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(mp[i][j] == 'o') cnt ++;
        }
        y_cnt[i] = cnt;
    }
    vector<int> t_cnt(n);
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(mp[i][j] == 'o') cnt ++;
        }
        t_cnt[j] = cnt;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if(y_cnt[i] < 2) continue;
        for (int j = 0; j < n; j++) {
            if(t_cnt[j] < 2) continue;

            if(mp[i][j] == 'o')ans += (ll)(t_cnt[j] - 1)*(y_cnt[i] - 1);
        }
    }
    cout << ans << endl;
}