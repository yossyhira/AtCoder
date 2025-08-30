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
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    sort(all(r));
    auto f = [&](int R) {
        // r が ll の場合に注意！！！
        int pos = upper_bound(r.begin(), r.end(), R) - r.begin();
        //int pos = lower_bound(num.begin(), num.end(), r) - num.begin();
        return pos;
    };
    ll ans = ((ll)n*(n-1))/2;
    for (int i = 0; i < n; i++) {
        int p = f(l[i]-1);
        ans -= (ll)p;
    }
    cout << ans << endl;
}