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
    long double t, l, x, y;
    cin >> t >> l >> x >> y;
    const long double pi = 3.141592653589793;
    const long double deg = 180.0;
    auto f = [&](long double e){
        long double cy, cz;
        cy = -(l / 2) * sin(e/t * 2*pi);
        cz = -(l / 2) * cos(e/t * 2*pi) + (l / 2);
        long double d = sqrt((x * x) + (abs(y - cy) * abs(y - cy)));
        long double at = cz/d;
        long double rad = atan(at);
        long double ans = rad *(deg / pi);
        return ans;
    };
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long double e;
        cin >> e;
        printf("%.12Lf\n", f(e)) ;
    }

}