#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<P> qe;
    for (int i = 0; i < q; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        int bef_num = c1 - 'a';
        int aft_num = c2 - 'a';
        qe.eb(bef_num, aft_num);
    }

    vector<int> trs(26);
    for (int i = 0; i < 26; i++) {
        trs[i] = i;
    }
    for (int i = (q-1); i >= 0; i --) {
        int bef_num, aft_num;
        tie(bef_num, aft_num) = qe[i];
        trs[bef_num] = trs[aft_num];
    }
    for (int i = 0; i < n; i++) {
        s[i] = trs[s[i] - 'a'] + 'a';
    }
    cout << s << endl;
}