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
    string s, t;
    cin >> s >> t;
    auto f = [&](int w, int c){
        int mx = s.size() / w;
        int md = s.size() % w;
        string ans;
        for (int i = 0; i < mx; i++) {
            ans.pb(s[(i*w)+c]);
        }
        if((c+1) <= md) ans.pb(s[(mx*w)+c]);
        if(ans == t) return true;
        else return false;
    };
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if(f(i, j)){
                yes;
                return 0;
            }
        }
    }
    no;
    return 0;
}