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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> num(n+1, 0);
    for (int i = 0; i < n; i++) {
        num[i+1] += (num[i] + a[i]);
    }
    int st = 0;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if(x == 1){
            int c;
            cin >> c;
            st = (st + c) % n;
        }else{
            int l, r;
            cin >> l >> r;
            l --; r --;
            l = (st + l) % n; 
            r = (st + r) % n; 

            if(l <= r){
                cout << num[r+1] - num[l] << endl;
            }else{
    
                cout << (num[n] - num[l]) + num[r+1] << endl;
            }
        }
    }
}