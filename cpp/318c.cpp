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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    ll d, p;
    cin >> n >> d >> p;
    vector<ll> num(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        ans += num[i];
    }
    sort(all(num));
    int cnt = 0;
    ll sum = 0;
    for (int i = (n-1); i >= 0; i--) {
        cnt ++;
        sum += num[i];
        if(cnt == d){
            if(p < sum){
                ans -= sum;
                ans += p;
            }
            cnt = 0;
            sum = 0;
        }
    }
    if(p < sum){
        ans -= sum;
        ans += p;
    }
    cout << ans << endl;
}