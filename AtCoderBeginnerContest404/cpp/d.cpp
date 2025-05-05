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
    vector<int> money(n);
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }
    vector<vector<int>> animal(m);
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int x;
            cin >> x;
            x --;
            animal[i].pb(x);
        }
    }
    vector<vector<int>> zoo(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < animal[i].size(); j++) {
            zoo[animal[i][j]].pb(i);
        }
    }
    ll ans = LINF;
    for (int i = 0; i < (1 << n*2); i++) {
        vector<int> look(m, 0);
        int look_sum = 0;
        ll money_sum = 0;
        for (int j = 0; j < n*2; j++) {
            if((i & (1 << j)) != 0){
                int x = j / 2;
                money_sum += ll(money[x]);
                for (int k = 0; k < zoo[x].size(); k++) {
                    if(look[zoo[x][k]] == 0 || look[zoo[x][k]] == 1) look_sum ++;
                    look[zoo[x][k]] ++;
                }
            }
        }
        if(look_sum == 2*m) chmin(ans, money_sum);
    }
    cout << ans << endl;
}