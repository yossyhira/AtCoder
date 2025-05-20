#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
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
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    vector<char> op(n-1);
    for (int i = 0; i < (n-1); i++) {
        if(num[i] < num[i+1]) op[i] = '<';
        else op[i] = '>';
    }

    vector<pair<char, int>> len;
    int cnt = 0;
    for (int i = 0; i < (n-1); i++) {
        if(op[i] != op[i+1]){
            len.pb({op[i], cnt+1});
            cnt = 0;
        }else cnt ++;
    }
    
    ll ans = 0;
    bool __is_first_big = true;
    int bef_num = -1;
    for (auto p : len) {
        if(p.fi == '<'){
            if(__is_first_big){ 
                bef_num = p.se;
                __is_first_big = false;
                continue;
            }
            ans += (ll)bef_num*p.se;
            bef_num = p.se;
        }
    }
    cout << ans << endl;
}