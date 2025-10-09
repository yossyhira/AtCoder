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
using mint = modint1000000007;   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k_l;
    cin >> n >> k_l;
    mint k = k_l; 
    //コーナーケース
    if(n == 1){
        cout << k.val() << endl;
        return 0;
    }else if(n == 2){
        if(k.val() == 1){
            cout << 0 << endl;
            return 0;
        }else{
            cout << (k * (k-1)).val() << endl;
            return 0;
        }
    }else if(3 <= n){
        if(k.val() < 3){
            cout << 0 << endl;
            return 0;
        }
    }
    //通常
    mint ans = 1;
    // 制約から k < modより
    ans *= k;
    ans *= (k-1);
    //k -= 2;
    ans *= (k-2).pow(n-2);
    cout << ans.val() << endl;
}