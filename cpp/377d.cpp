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
    int n, m;
    cin >> n >> m;
    vector<int> ml(m + 1, -1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        chmax(ml[r], l);
    }
    int l = 1;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if(ml[i] == -1){
            ans += (ll)(i - l) + 1;
        }else{
            if(l <= ml[i])l = ml[i] +1;
            ans += (ll)(i-l)+1;
        }
    }
    cout << ans << endl;
}