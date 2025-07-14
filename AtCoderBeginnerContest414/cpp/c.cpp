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

bool palindro(int a, ll n){
    string txt = "";
    while(1){
        if(n == 0) break;
        ll now_n = n / a;
        int mod = n % a;
        //cout << mod << endl;
        char c = mod + '0';
        txt.pb(c);
        n = now_n;
    }
    string rev_txt = txt;
    reverse(txt.begin(), txt.end());
    
    if(txt == rev_txt)return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    ll n;
    cin >> n;
    ll ans = 0;
    /*for (int i = 1; i < 10; i++) {
        if(n < i) break;
        if(palindro(a, i)) ans += i;
    }*/
    const int mx = 1e6 - 1.0;
    //cout << mx << endl;
    for (int i = 1; i <= mx; i++) {
        string txt = to_string(i);
        {
            //奇数
            string long_txt = txt;
            //if(n < i) break;
            for (int i = (txt.size() - 2); i >= 0; i--) {
                long_txt.pb(txt[i]);
            }
            ll num = 0;
            //long long もできる    
            istringstream(long_txt) >> num;
            if(num <= n){
                if(palindro(a, num)) ans += num;
            }
        }
        //偶数
        {
            string long_txt = txt;
            for (int i = (txt.size() - 1); i >= 0; i--) {
                long_txt.pb(txt[i]);
            }
            ll num = 0;
            //long long もできる    
            istringstream(long_txt) >> num;
            if(num <= n){
                if(palindro(a, num)) ans += num;
            }
        }
    }
    cout << ans << endl;
}