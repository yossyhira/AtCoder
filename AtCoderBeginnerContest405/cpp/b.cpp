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
    int n, m;
    cin >> n >> m;
    vector<int> all(n);
    vector<int> num(m+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> all[i];
        num[all[i]]++;
    }
    int cnt = 0;
    reverse(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if(num[j]==0){
                cout << cnt << endl;
                return 0;
            }
        }
        num[all[i]] --;
        cnt ++;
    }
    for (int j = 1; j <= m; j++) {
            if(num[j]==0){
                cout << cnt << endl;
                return 0;
            }
        }
}