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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    vector<ll> sm(n+1, 0);
    for (int i = 0; i < n; i++) {
        sm[i + 1] = sm[i] + (ll)num[i];    
    }

    auto f = [&](int r) {
        int pos = lower_bound(num.begin(), num.end(), r) - num.begin();
        return pos;
    };
    for (int i = 0; i < m; i++) {
        ll ans = 0;
        int x;
        cin >> x;
        if(x == 1){
            cout << 1 << endl;
            continue;
        }
        if(num[n-1] < x){
            cout << -1 << endl;
            continue;
        }

        int p = f(x);
        ans += (sm[p] + (ll)(x - 1)*(n - p) + 1);
        cout << ans << endl;
        
    }
}