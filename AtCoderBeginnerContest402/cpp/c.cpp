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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> num(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            num[i].pb(x);
        }
    }
    //cout << "ok" << endl;
    map<int, int> M1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        M1[x] = i;
    }
    //cout << "OK" << endl;
    vector<int> ok(n, 0);
    for (int i = 0; i < m; i++) {
        int mx = -1;
        for (int j = 0; j < num[i].size(); j++) {
            chmax(mx, M1[num[i][j]]);
        }
        ok[mx] ++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ok[i];
        cout << ans << endl;
    }
    return 0;

}