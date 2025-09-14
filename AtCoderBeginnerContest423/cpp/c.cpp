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
    int n, r;
    cin >> n >> r;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    int one = 0, cnt = 0;
    int kari_one = 0, kari_cnt = 0;
    ll ans = 0;
    for (int i = (r-1); i >= 0; i--) {
        if(l[i] == 0){
            one += kari_one;
            cnt += (kari_cnt + 1);
            kari_one = 0;
            kari_cnt = 0;
        }else{
            kari_cnt ++;
            kari_one ++;
        }
    }
    ans += ((ll)one + (ll)cnt);
    one = 0; cnt = 0;
    kari_one = 0; kari_cnt = 0;
    
    for (int i = r; i < n; i++) {
        if(l[i] == 0){
            one += kari_one;
            cnt += (kari_cnt + 1);
            kari_one = 0;
            kari_cnt = 0;
        }else{
            kari_cnt ++;
            kari_one ++;
        }
    }
    ans += ((ll)one + (ll)cnt);
    cout << ans << endl;
}
