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
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //自動で初期値0になってる．map＜key, 値＞
    map<int, int> M1;
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int st = 0, gl = 0;
    int ans = 0;
    while(gl < n){
        M1[a[gl]] ++;
        if(M1.size() == (k + 1)){
            chmax(ans, (gl - st));
            while(k < M1.size()){
                M1[a[st]] --;
                if(M1[a[st]] == 0) M1.erase(a[st]);
                st++;
            }
        }
        gl ++;
    }
    //最後の値更新忘れずに(今回は覚えてた)
    chmax(ans, (gl - st));
    cout << ans << endl;
}

/*
サンプルにないコーナー
10 1
3 3 3 3 3 3 3 3 3 3

3 100
1 4 5
*/