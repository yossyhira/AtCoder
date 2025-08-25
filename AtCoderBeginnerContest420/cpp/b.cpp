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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> cnt(n, 0);
    for (int j = 0; j < m; j++) {
        int one_cnt = 0, zero_cnt = 0;
        for (int i = 0; i < n; i++) {
            if(s[i][j] == '1'){
                one_cnt ++;
            }else{
                zero_cnt ++;
            }
        }
        if(zero_cnt == 0 || one_cnt == 0) continue;

        char check = '0';
        if(one_cnt < zero_cnt) check = '1';

        for (int i = 0; i < n; i++) {
            if(s[i][j] == check) cnt[i] ++;
        }
    }
    int mx = -1;
    for (int i = 0; i < n; i++) {
        chmax(mx, cnt[i]);
    }
    for (int i = 0; i < n; i++) {
        if(cnt[i] == mx){
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}