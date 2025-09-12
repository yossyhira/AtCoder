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
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        string s;
        cin >> s;
        ll a, b, c;
        cin >> a >> b >> c;
        ll mn = min({a, b, c});
        if(mn == a || mn == c){
            cout << mn << endl;
        }else{
            a -= mn;
            c -= mn;
            ll mod = 0;
            if(a < c){
                mod = c - a;
                if(a <= mod){
                    cout << mn + a << endl;
                    continue;
                }
                c -= (mod + mod);
                a -= mod;
            }else if(c < a){
                mod = a - c;
                if(c <= mod){
                    cout << mn + c << endl;
                    continue;
                }
                a -= (mod + mod);
                c -= mod;
            }
            ll ans = (a / 3) * 2;
            if((a % 3) == 2) ans ++;
            cout << mn + ans + mod<< endl;
        }
    }
}