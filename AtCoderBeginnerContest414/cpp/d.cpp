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
    int n, m;
    cin >> n >> m;

    vector<ll> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    vector<tuple<ll, int, int>> dist;
    //入力
    for (int i = 0; i < (n-1); i++) {
        ll dst = num[i+1] - num[i];
        dist.push_back({dst, i, i+1});
    }
    sort(dist.begin(), dist.end(), [](const auto &a, const auto &b) {
        return get<0>(a) < get<0>(b);//第一
    });
    vector<bool> num2(n+1, true);
   
    for (int i = (dist.size() - 1); i >= (dist.size() - m + 1); i--) {
        int x, y, z;
        tie(x, y, z) = dist[i];
        num2[z] = false;
    }
    /*int st = dist.size() - 1;
    int gt =  dist.size() - m + 1;
    for (int i = st; i >= gt; i--) {
        int x, y, z;
        tie(x, y, z) = dist[i];
        num2[z] = false;
    }*/
    num2[n] = false;

    int l = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if(!num2[i + 1]){
            ans += num[i] - num[l];
            l = i + 1;
        }
    }
    cout << ans << endl;
}