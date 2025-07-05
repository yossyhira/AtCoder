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
    vector<int> num(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        num[i] --;
        pos[num[i]] = i;
    }
    vector<P> ans;
    for (int i = 0; i < n; i++) {
        if(num[i] != i){
            int a = i;
            int b = pos[i];
            swap(num[a], num[b]);
            pos[num[b]] = b;
            ans.pb({a+1, b+1});
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        int a, b;
        tie(a, b) = ans[i];
        cout << a << " " << b << endl;
    }
    //num[i]++;

}