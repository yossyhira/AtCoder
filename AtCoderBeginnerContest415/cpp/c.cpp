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
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int mxn = 1 << n;
        vector<bool> visited(mxn, false);
        visited[0] = true;
        for (int i = 0; i < mxn; i++) {
            if(!visited[i]) continue;
            for (int j = 0; j < n; j++) {
                int num = i | (1 << j);

                if(i == num) continue;
                if(s[num - 1] == '1') continue;

                visited[num] = true;
            }
        }

        if(visited[mxn - 1]) yn;
    }
}