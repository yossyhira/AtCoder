#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pof pop_front
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
    int m;
    cin >> m;
    vector<int> num(m);
    for (int i = m - 1; i >= 0; i --) {
        cin >> num[i];
    }
    deque<int> deq;
    
    auto f1 = [&](int n){
        for (int i = 0; i < n; i++) {
            deq.pof();
        }
    };
    auto f = [&](int r) {
        int pos = lower_bound(deq.begin(), deq.end(), r) - deq.begin();
        f1(pos);
    };
    deq.pb(num[0]);
    vector<int> ans;
    ans.pb(0);
    
    for (int i = 1; i < m; i++) {
        ans.pb(deq.size());
        if(deq[deq.size() - 1] < num[i]){
            f1(deq.size());
            deq.pb(num[i]);
        }
        else if(num[i] < deq[0]){
            deq.pf(num[i]);
        }
        else{
            f(num[i]);
            deq.pf(num[i]);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}