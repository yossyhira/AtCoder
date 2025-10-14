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
    mint::set_mod(100000); 
    auto f = [&](int n){
        int x = 0;
        while(1){
            x += (n % 10);
            n /= 10;
            if(n == 0) break;
        }
        return x;
    };
    
    const int mx = 1e5;
    vector<bool> visited(mx, false);
    int x;
    ll k;
    cin >> x >> k;
    mint ans = mint(x);
    //mx以下ならループしない可能性もあるので愚直に求める(mx = 10^5より，計算量はO(10^5)以下)
    if(k <= mx){
        for (int i = 0; i < k; i++) {
            ans += mint(f((int)ans.val()));
        } 
        cout << ans.val() << endl;
        return 0;
    }

    vector<int> num;
    int cnt = 0;
    //ループになるまで愚直に計算
    while(1){
        ans += mint(f((int)ans.val()));
        if(!visited[ans.val()]){
            visited[ans.val()] = true;
            num.pb(ans.val());
            cnt ++;
        }
        else {
            cnt ++;
            break;
        }
    }  

    int st = 0;
    //numは昇順になってない(ソートするとループの順番変わるからできない)
    //愚直に前から見ていく
    for (int i = 0; i < num.size(); i++) {
        if(num[i] == ans.val()){
            st = i;
            break;
        }
    }
    //ループのサイズ
    const int md = num.size() - st;
    //残りでstからどれだけ進むか計算
    cout << num[st + ((k - cnt) % md)] << endl;
}