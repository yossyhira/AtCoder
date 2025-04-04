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
    ll n;
    cin >> n;
    map<ll, ll> M1;
    auto f = [&](auto f, ll num) -> ll{
        if(num == 0){
            return 1;
        }
        if (M1.count(num)) {
            ll ans = M1[num];
            return ans;
        }
        ll ans = f(f, num / 2) + f(f, num / 3);
        M1[num] = ans;
        return ans;
    };

    ll ans = f(f, n);
    cout << ans << endl;
    return 0;
}