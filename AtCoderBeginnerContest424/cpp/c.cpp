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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<set<int>> num(n+1);
    vector<P> skil(n);
    vector<int> fist;
    for (int i = 0; i < n; i++) {
        cin >> skil[i].fi >> skil[i].se;
        num[skil[i].fi].insert(i+1);
        num[skil[i].se].insert(i+1);
        if(skil[i].fi == 0 && skil[i].se == 0){
            fist.pb(i+1);
        }
    }
    ll ans = 0;
    auto f = [&](auto f, int x){
        int a, b;
        tie(a, b) = skil[x-1];
        if(a != 0 && b != 0){
            num[a].erase(x);
            num[b].erase(x);
        }
        if(num[x].size() == 0) return;
        while(1){
            if(num[x].size() == 0) break;
            ans ++;
            int v = *num[x].begin();
            f(f, v);
        }
    };
    for (int i = 0; i < fist.size(); i++) {
        f(f, fist[i]);
        ans++;
    }
    cout << ans << endl;
}