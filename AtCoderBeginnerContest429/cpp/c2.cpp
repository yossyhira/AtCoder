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
    int n;
    cin >> n;
    vector<ll> num(n);
    //自動で初期値0になってる．map＜key, 値＞
    map<ll, ll> M1;
    set<ll> st;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        M1[num[i]] ++;
        if(2 == M1[num[i]]){
            st.insert(num[i]);
        }
    }
    ll subans = 0;
    for(auto x : st){
        ll a = M1[x];
        subans += ((a*(a-1))/2);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        //cout << subans << " " << ans << endl;
        int now = M1[num[i]];
        if(2 <= now){
            subans -= ((now*(now-1))/2);
            now --;
            if(2 <= now) subans += ((now*(now-1))/2);
        }
        M1[num[i]] --;
        now = M1[num[i]];
        if(2 <= (now)){
            //cout << "koko" << i << endl;
            //自分以外の2ペア
            ans += (subans - (now*(now-1))/2);
            //自分同士もつ
            ll a = (n - (i + 1))*(n - (i+2))/2;
            ans += (a - (((n - (i + 1)) - now)*((n - (i+2)) - now)/2) - ((now*(now-1))/2));
        }else{
            ans += subans;
            //ll a = (n - (i + 1))*(n - (i+2))/2;
            ll a = (n - (i + 1))*(n - (i+2))/2;
            ans += (a - (((n - (i + 1)) - now)*((n - (i+2)) - now)/2));
        }
    }
    cout << ans << endl;
}