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
    set<int> set;
    int n;
    cin >> n;
    for (int i = 1; i <= (2*n+1); i++) {
        set.insert(i);//追加//O(logN)
    }
    while(1){
        // stの先頭のイテレータを取得
        auto ite = set.begin();
        cout << *ite << endl;
        int ans = *ite;
        set.erase(ans);
        int num;
        cin >> num;
        if(num == 0) break;
        set.erase(num);
    }
    return 0;
}