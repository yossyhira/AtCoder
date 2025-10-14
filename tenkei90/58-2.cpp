#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
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
const int mod = 1e9 + 7;
using mint = modint; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mint::set_mod(10); 
    auto f = [&](int n){
        int x = 0;
        while(1){
            x += (n % 10);
            n /= 10;
            if(n == 0) break;
        }
        return x;
    };
    int x;
    ll k;
    cin >> x >> k;
    mint ans = mint(x);
    vector<int> num;
    for (int i = 0; i < k; i++) {
        ans += mint(f((int)ans.val()));
        num.pb(ans.val());
    } 
    for (int i = 1; i < num.size(); i++) {
        cout <<i << "回目"<< num[i-1] << endl;
        cout << num[i] - num[i-1] << endl;
    }
}