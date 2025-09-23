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
    vector<string> ans;
    auto f = [&](string s){
        int score = 0;
        bool ok = true;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '(') score ++;
            else score --;
            if(score < 0) ok = false;
        }
        if(score != 0) ok = false;
        return ok;
    };
    for (int i = 0; i < (1 << n); i++) {
        string s;
        for (int j = 0; j < n; j++) {
            if((i & (1 << j)) != 0) s.pb(')');
            else s.pb('(');
        }
        if(f(s)) ans.pb(s);
    }
    sort(all(ans));
    for(auto x: ans) cout << x << endl;
}