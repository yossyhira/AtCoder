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
    string tex;
    int q;
    cin >> tex >> q;
    for (int i = 0; i < q; i++) {
        ll c, block, num;
        cin >> c;
        c --;
        block = c / tex.size();
        num = c % tex.size();
        ll cnt = __builtin_popcountll(block);//long long １の個数
        if (cnt % 2 == 0){
            cout << tex[num] << " ";
        }else{
            char ch = tex[num];
            if(isupper(ch)){
                ch -= 'A' - 'a';
                cout << ch << " ";
            }else{
                ch += 'A' - 'a';
                cout << ch << " ";
            }
        }
    }
    cout << endl;
    return 0;
}