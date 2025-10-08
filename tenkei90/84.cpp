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
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = (ll)n*(n-1)/2;
    queue<int> o;
    queue<int> x;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'o') o.push(i);
        else if(s[i] == 'x') x.push(i);
    }
    for (int i = 0; i < n; i++) {
        if(s[i] == 'o'){
            o.pop();
            if(!x.empty()){
                int x_idx = x.front();
                ans -= ((x_idx - i) - 1);
            }else{
                ans -= ((n - i) - 1);
            }
        }else{
            x.pop();
            if(!o.empty()){
                int o_idx = o.front();
                ans -= ((o_idx - i) - 1);
            }else{
                ans -= ((n - i) - 1);
            }
        }
    }
    cout << ans << endl;
}