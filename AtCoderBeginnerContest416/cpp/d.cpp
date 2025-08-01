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
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n;
        ll m;
        cin >> n >> m;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<ll> modb(n);
        for (int i = 0; i < n; i++) {
            modb[i] = m - (b[i] % m);
        }
        sort(a.begin(), a.end());
        sort(modb.begin(), modb.end());
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << modb[i] << " ";
        }
        cout << endl;
        auto f = [&](ll r, int idx) {
            int pos = lower_bound(a.begin() + idx, a.end(), r) - a.begin();
            return pos;
        };
        vector<bool> oka(n, false);
        ll ans = 0;
        int now_p = 0;
        int look = -1;
        for (int i = 0; i < n; i++) {
            if(modb[i] == 0) continue;
            int p = f(modb[i], now_p);
            ans  += (modb[i] + a[p]) % m;
            oka[p] = true;
            now_p = p + 1;
            if(n <= now_p) {
                look = i+1;
                break;
            }
        }
        //cout << look << endl;
        if(look != -1){
            for (int i = 0; i < n; i++) {
                if(!oka[i]){
                    //cout << i << endl;
                    //cout << a[i] << endl;
                    ans += b[look] + a[i];
                    look ++;
                }else{
                    //cout << i << endl;
                }
            }
        }

        cout << ans << endl;

    }
}