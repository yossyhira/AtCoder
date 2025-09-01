#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
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
    ll x_s, y_s;
    ll x_t, y_t;
    cin >> x_s >> y_s >> x_t >> y_t;
    ll n, m, l;
    cin >> n >> m >> l;
    vector<pair<char, ll>> s;
    vector<pair<char, ll>> t;
    for (int i = 0; i < m; i++) {
        char c;
        ll x;
        cin >> c >> x;
        s.eb(c, x);
    }
    for (int i = 0; i < l; i++) {
        char c;
        ll x;
        cin >> c >> x;
        t.eb(c, x);
    }
    
    auto f = [&](char c, ll cnt, ll x, ll y){
        if(c == 'U'){
            x --;
        }
        else if(c == 'D'){
            x ++;
        }
        else if(c == 'R'){
            y ++;
        }
        else if(c == 'L'){
            y --;
        }
        pair<ll, ll> a = {x, y};
        return a;
    };
    ll befx_t = x_t; 
    ll befy_t = y_t; 
    for (int i = 0; i < l; i++) {
        char m_t;
        ll cnt_t;
        tie(m_t, cnt_t) = t[i];
        f(m_t, cnt_t);
        while(1){
            if(cnt <= ) break;
            char c_s;
            ll x_s;
            tie(c_s, x_s) = t[i];


        }
    }
}