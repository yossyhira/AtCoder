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
    string tex;
    cin >> tex;
    vector<int> num(26,0);
    for (int i = 0; i < tex.size(); i++) {
        int n = tex[i] - 'a';
        num[n] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if(num[i] != 1){
            char c = 'a' + i;
            cout << c << endl;
            return 0;
        }
    }
}