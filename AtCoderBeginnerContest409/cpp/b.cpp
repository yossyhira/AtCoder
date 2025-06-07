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
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    auto f = [&](int r) {
        int pos = lower_bound(num.begin(), num.end(), r) - num.begin();
        return pos;
    };
    int ans = -1;
    const int mxnum = 1e9;
    for (int i = 0; i <= 100; i++) {
        int p = f(i);
        int cnt = n - p;
        if(i <= cnt){
            ans = i;
        }
    }
    cout << ans << endl;

}