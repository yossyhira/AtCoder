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
using LP = pair<ll, int>;
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
        cin >> n;
        vector<LP> num(n);
        vector<ll> num2(n);
        int mcnt = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            int a = 1;
            if(x < 0) {
                a = 0;
                mcnt ++;
            }
            num2[i] = x;
            num[i] = {abs(x), a};
        }

        sort(num.begin(), num.end(), [](const auto& a, const auto& b) {
            return a.fi < b.fi;
        });

        bool ok = true;
       
        for (int i = 1; i < (n - 1); i++) {
            if ((num[i].fi * num[i].fi) != (num[i - 1].fi * num[i + 1].fi)) ok = false;
        }
        if(mcnt != n && mcnt != 0){
            for (int i = 0; i < (n - 1); i++) {
                if(num[i].se == num[i + 1].se) ok = false;
            }
        }

        //公比-1のケース！！！！！
        bool same = true;
        ll base = num[0].fi;
        for (int i = 0; i < n; i++) {
            if(num[i].fi != base) same = false;
        }
        if(same){
            int p = 0, m = 0;
            for (int i = 0; i < n; i++) {
                if(0 < num2[i]) p ++;
                else m ++;
            }
            if(p == m || abs(p - m) == 1) ok = true;
        }
        if(ok)yn;
    }
}