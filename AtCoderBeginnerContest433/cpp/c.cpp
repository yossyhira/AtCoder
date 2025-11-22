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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        num[i] = s[i] - '0';
    }
    vector<P> len;
    int l = 1;
    for (int i = 0; i < (n-1); i++) {
        if(num[i] == num[i+1]){
            l ++;
        }else{
            len.pb({num[i], l});
            l = 1;
        }
    }
    len.pb({num[n-1], l});
    int lsz = len.size(); 
    ll ans = 0;
    for (int i = 0; i < (lsz-1); i++) {
        int b_x, b_l;
        tie(b_x, b_l) = len[i];
        int a_x, a_l;
        tie(a_x, a_l) = len[i + 1];

        if((b_x + 1) != a_x) continue;

        ans += min((ll)b_l, (ll)a_l);
    }
    cout << ans << endl;
}