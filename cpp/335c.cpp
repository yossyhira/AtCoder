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
    int n, q;
    cin >> n >> q;
    vector<LP> pos;
    for (int i = n; i > 0; i--) {
        pos.pb({ll(i), 0});
    }
    for (int i = 0; i < q; i++) {
        int mode;
        cin >> mode;
        if(mode == 1){
            char c;
            cin >> c;
            ll x, y;
            tie(x, y) = pos[pos.size() - 1];
            if(c == 'U'){
                pos.pb({x, y+1});
            }else if(c == 'D'){
                pos.pb({x, y-1});
            }else if(c == 'R'){
                pos.pb({x+1, y});
            }else if(c == 'L'){
                pos.pb({x-1, y});
            }
        }else{
            int num;
            cin >> num;
            ll x, y;
            tie(x, y) = pos[pos.size() - num];
            cout << x << " " << y << endl;

        }
    }
    return 0;
}