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
const int INF = 2001001001;
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
    vector<int> num(n+2);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    num[n] = -INF;
    num[n+1] = INF;
    sort(all(num));

    auto f = [&](int r) {
        // r が ll の場合に注意！！！
        int pos = upper_bound(num.begin(), num.end(), r) - num.begin();
        //int pos = lower_bound(num.begin(), num.end(), r) - num.begin();
        return pos;
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int idx = f(x);
        int ans = min(abs(num[idx] - x), abs(num[idx-1]-x));
        cout << ans << endl;
    }
}