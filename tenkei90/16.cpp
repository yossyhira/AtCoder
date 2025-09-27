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
    cin >> n;
    vector<int> num(3);
    cin >> num[0] >> num[1] >> num[2];
    sort(all(num));
    int a = num[2], b = num[1], c = num[0];
    int mx_a = n/a;
    int ans = INF;
    for (int i = 0; i <= mx_a; i++) {
        int dif_a = (n - (a*i));
        int mx_b = dif_a/b;
        for (int j = 0; j <= mx_b; j++) {
            int dif_b = dif_a - (b*j);
            if(dif_b % c == 0)chmin(ans, (i + j + (dif_b/c)));
        }
    }
    cout << ans << endl;
}