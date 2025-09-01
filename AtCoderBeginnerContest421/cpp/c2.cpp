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
    string s;
    cin >> n >> s;
    priority_queue<int, vector<int>, greater<int>> qa;//小さい順(昇順)に取り出す
    priority_queue<int, vector<int>, greater<int>> qb;//小さい順(昇順)に取り出す
    for (int i = 0; i < n*2; i++) {
        if(s[i] == 'A')qa.emplace(i);
        else qb.emplace(i);
    }
    ll ansa = 0, ansb = 0;
    for (int i = 0; i < n*2; i += 2) {
        int x = qa.top(); qa.pop();
        ansa += (ll)abs(i-x);
        x = qb.top(); qb.pop();
        ansb += (ll)abs(i-x);
    }
    cout << min(ansa, ansb) << endl;
}