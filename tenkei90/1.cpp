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
    int n, l;
    cin >> n >> l;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto judge = [&](int t){
        int cnt = 0;
        int bef = 0;
        for (int i = 0; i < n; i++) {
            if(t <= (a[i] - bef)){
                cnt ++;
                bef = a[i];
            }
        }
        if(t <= (l - bef)) cnt ++;
        if((k + 1) <= cnt) return true;
        else return false;
    };
    int ac = 0;
    int wa = 2e9;
    while(1 < (wa - ac)){
        int t = (wa+ac)/2; //wa"+"ac注意
        if(judge(t)) ac = t;
        else wa = t;
    }
    cout << ac << endl;
}