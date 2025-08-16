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
    ll ans = 0;
    ans = (ll)n*n;
    set<P> num;
    auto f = [&](int a, int b){
        num.insert({a, b});
    };
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        f(a, b);
        if((a + 2) <= n){
           if((b + 1) <= n){
                f(a + 2, b + 1);
            }
            if(0 < (b - 1)){
                f(a + 2, b - 1);
            }
        }
        if((a + 1) <= n){
            if((b + 2) <= n){
                f(a + 1, b + 2);
            }
            if(0 < (b - 2)){
                f(a + 1, b - 2);
            }
        }
        if(0 < (a - 1)){
            if((b + 2) <= n){
                f(a - 1, b + 2);
            }
            if(0 < (b - 2)){
                f(a - 1, b - 2);
            }
        }
        if(0 < (a - 2)){
            if((b + 1) <= n){
                f(a - 2, b + 1);
            }
            if(0 < (b - 1)) f(a - 2, b - 1);
            
        }
    }
    ll sz = num.size();
     cout << ans - sz << endl;
}