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
const int mod = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> ans;
    ans.pb(0);
    for (int i = 0; i < k; i++) {
        ans.pb(ans[i] + 1);
    }

    for (int i = k; i <= n ; i++) {
        ll num = (ans[i] + ((ans[i] - ans[i - k]) % mod));
        ans.pb(num);
    }

    cout << ((ans[n+1] - ans[n+1 - 1]))<< endl;

}