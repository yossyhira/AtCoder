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
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> h(N);
    multiset<ll> b;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < M; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    sort(all(h));
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        auto itr2 = b.lower_bound(h[i]);
        if (itr2 != b.end()){
            b.erase(itr2);
            cnt ++;
        }
        if(K == cnt){
            yes;
            return 0;
        }
    }
    no;
    return 0;
}