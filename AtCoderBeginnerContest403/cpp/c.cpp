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

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> all(n, -1);
    vector<set<int>> num(n);
    for (int i = 0; i < q; i++) {
        int que;
        cin >> que;
        if(que == 1){
            int x, y;
            cin >> x >> y;
            x --;
            num[x].insert(y);
        }else if(que == 2){
            int x;
            cin >> x;
            x--;
            all[x] = 1;
        }else{
            int x, y;
            cin >> x >> y;
            x --;
            if(all[x] == 1){
                yes;
                continue;
            }
            if (num[x].contains(y)) {
                yes;
                continue;
            }
            no;
        }
    }
}