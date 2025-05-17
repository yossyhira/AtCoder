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

bool willOverflow(long long a, long long b) {
    if (a == 0 || b == 0) return false;
    if (a > 0) {
        if (b > 0) {
            return a > LLONG_MAX / b;
        } else {
            return b < LLONG_MIN / a;
        }
    } else {
        if (b > 0) {
            return a < LLONG_MIN / b;
        } else {
            return a != 0 && b < LLONG_MAX / a;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        if (willOverflow(ans, num)) {
            ans = 1;
            continue;
        }   
        ans *= num;
        int digits = 0;
        ll subans = ans;
        while (subans != 0) {
            subans /= 10;
            digits++;
        }
        
        if(digits > k){
            ans = 1;
        }
    }
    cout << ans << endl;
}