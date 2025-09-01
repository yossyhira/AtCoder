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
    int n;
    string s;
    cin >> n >> s;
    priority_queue<int, vector<int>, greater<int>> qa;//小さい順(昇順)に取り出す
    priority_queue<int, vector<int>, greater<int>> qb;//小さい順(昇順)に取り出す
    for (int i = 0; i < n*2; i++) {
        if(s[i] == 'A')qa.emplace(i);
        else qb.emplace(i);
    }
    string s_c = s;
    ll ans = 0;
    //ABAB
    for (int i = 0; i < n*2; i++) {
        //本来A
        if((i % 2) == 0){
            if(s_c[i] != 'A'){
                int idx_a = qa.top(); qa.pop();
                int idx_b = qb.top(); qb.pop();
                ans += (ll)(idx_a - idx_b);
                swap(s_c[idx_a], s_c[idx_b]);
                qb.emplace(idx_a);
            }else{
                qa.top();qa.pop();
            }
        }else{
            if(s_c[i] != 'B'){
                int idx_a = qa.top(); qa.pop();
                int idx_b = qb.top(); qb.pop();
                ans += (ll)(idx_b - idx_a);
                swap(s_c[idx_a], s_c[idx_b]);
                qa.emplace(idx_b);
            }else{
                qb.top();qb.pop();
            }
        }
    }

    ll mn = ans;
    //cout << ans << endl;
    priority_queue<int, vector<int>, greater<int>> qa_1;//小さい順(昇順)に取り出す
    priority_queue<int, vector<int>, greater<int>> qb_1;//小さい順(昇順)に取り出す
    for (int i = 0; i < n*2; i++) {
        if(s[i] == 'A')qa_1.emplace(i);
        else qb_1.emplace(i);
    }

    s_c = s;
    ans = 0;
    //BABA
    for (int i = 0; i < n*2; i++) {
        //本来B
        if((i % 2) == 0){
            if(s_c[i] != 'B'){
                int idx_a = qa_1.top(); qa_1.pop();
                int idx_b = qb_1.top(); qb_1.pop();
                ans += (ll)(idx_b - idx_a);
                swap(s_c[idx_a], s_c[idx_b]);
                qa_1.emplace(idx_b);
            }else{
                qb_1.top();qb_1.pop();
            }
        }else{
             if(s_c[i] != 'A'){
                int idx_a = qa_1.top(); qa_1.pop();
                int idx_b = qb_1.top(); qb_1.pop();
                ans += (ll)(idx_a - idx_b);
                swap(s_c[idx_a], s_c[idx_b]);
                qb_1.emplace(idx_a);
            }else{
                qa_1.top();qa_1.pop();
            }
        }
    }
    chmin(mn, ans);
    cout << mn << endl;
}