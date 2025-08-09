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
    int n;
    cin >> n;
    int mx = 26;
    vector<vector<int>> cnt(n, vector<int>(mx, 0));
    set<string> se;
    map<string, int> M1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            int idx = s[j] - 'a';
            cnt[i][idx] ++;
        }
        string ans = "";
        for (int j = 0; j < mx; j++) {
            int num = cnt[i][j];
            string txt = to_string(num);
            ans.append(txt);
        }
        se.insert(ans);
        if (M1.count(ans)) {
            M1[ans]++;
        } else {
            M1[ans] = 1;
        }
    }

    ll ans = 0;
    for(string t : se){
        int x = M1[t];
        ans += ((ll)x*(x-1))/2;
    }
    cout << ans << endl;

}