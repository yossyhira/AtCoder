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
vector<vector<char>> s;
vector<vector<char>> t;
vector<vector<char>> ans;
int n;

void one(int i, int j){
    ans[j][(n - 1 - i)] = s[i][j];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    s.resize(n, vector<char>(n));
    t.resize(n, vector<char>(n));
    ans.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = s[i][j];
        }
    }
    int minx = 1000100;
    int rot = -1;
    int a = 0;
    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(ans[i][j] != t[i][j]){
                    cnt ++;
                }
            }
        }
        //cout << cnt << endl;
        int befx = minx;
        chmin(minx, cnt + i);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s[i][j] = ans[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][(n - 1 - i)] = s[i][j];
            }
        }
    }

    cout << minx<< endl;

}