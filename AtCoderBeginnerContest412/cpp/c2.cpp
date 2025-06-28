//マルチテストケースで途中で止めたいときは，return 0ではなくcontinue;
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
        cin >> n;
        vector<int> num;
        //vector<int> base(n);
        int st, gl;
        for (int i = 0; i < n; i++) {
            if(i == 0) cin >> st;
            else if(i == (n-1)) cin >> gl;
            else{
                int x;
                cin >> x;
                num.pb(x);
            }
        }

        sort(num.begin(), num.end());
        auto f = [&](int r) {
            int pos = upper_bound(num.begin(), num.end(), r) - num.begin();
            return pos;
        };
        int ans = 0;
        int fnum = st;
        bool flag = false;
        int befp = -1;
        if(gl <= (st*2)){
            cout << 2 << endl;
            continue;
        }
        while(1){
            int x = fnum*2;
            if(gl <= x){
                flag = true;
                break;
            }
            int p = f(x);
            if(p == 0) break;
            if(p == befp) break;
            befp = p;
            fnum = num[befp-1];
            ans ++;
        }
        
        if(flag)cout << ans + 2 << endl;
        else cout << -1 << endl;
    }
}