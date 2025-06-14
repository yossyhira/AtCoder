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
    int n, q;
    cin >> n >> q;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        num[i] = (i+1);
    }
    int st = 0;
    for (int qi = 0; qi < q; qi++) {
        int q;
        cin >> q;
        if(q == 1){
            int p, x;
            cin >> p >> x;
            p --;
            int idx = st + p;
            int subAns = ((n - 1) - idx);
            if(subAns < 0){
                idx = abs(subAns) - 1;
            }
            num[idx] = x;
        }else if(q == 2){
            int p;
            cin >> p;
            p --;
            int idx = st + p;
            int subAns = ((n - 1) - idx);
            if(subAns < 0){
                idx = abs(subAns) - 1;
            }
            cout << num[idx] << endl;
        }else{
            int k;
            cin >> k;
            int roop = k % n;
            int idx = st + roop;
            int subAns = ((n - 1) - idx);
            if(subAns < 0){
                idx = abs(subAns) - 1;
            }
            st = idx;
        }
    }
}