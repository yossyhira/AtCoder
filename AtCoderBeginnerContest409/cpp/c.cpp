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
#define no cout<<"No"<<endl
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, k;
    cin >> n >> l;
    if(l%3 != 0){
        cout << 0 << endl;
        return 0;
    }
    k = l/3;
    vector<int> dot(l, 0);
    dot[0] = 1;
    int bef = 0;
    for (int i = 0; i < (n -1); i++) {
        int d;
        cin >> d;
        int pos = (bef + d) % l;
        dot[pos] ++;
        bef = pos;
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += ((ll)dot[i] * dot[i + k] * dot[i + k + k]);
    }
    cout << ans << endl;
}