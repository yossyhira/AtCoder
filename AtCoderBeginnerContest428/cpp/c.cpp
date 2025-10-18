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
    int q;
    cin >> q;
    string s;
    int cnt = 0;
    bool ng = false;
    int del_idx;
    for (int qi = 0; qi < q; qi++) {
        int que;
        cin >> que;
        int x;
        if(que == 1){
            char c;
            cin >> c;
            s.pb(c);
            if(c == '('){
                x = 1;
            }
            if(c == ')') {
                x = -1;
            }
            cnt += x;
            if(!ng && cnt < 0) {
                ng = true;
                del_idx = (int)s.size() - 1;
            }
        }else{
            int sz = s.size();
            if(s[sz-1] == '(') x = -1;
            if(s[sz-1] == ')') x = 1;
            cnt += x;
            s.pop_back();
            if(ng && ((del_idx) == s.size())) ng = false;
        }
        if(!ng && cnt == 0)yn;
    }
}