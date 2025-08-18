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
    vector<int> num(n+1);
    num[n] = INF;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    set<int> se;
    queue<int> que;
    int r = 0;
    int ans = 0;
    int add = 0;
    while(1){
        if(n <= r){
            int sz = se.size();
            chmax(ans, sz*2);
            break;
        }
        bool find = false;
        if((num[r] == num[r+1])) {
            if(se.count(num[r])) find = true;
            if(!find){
                se.insert(num[r]);
                que.push(num[r]);
                r += 2;
            }else{
                int sz = se.size();
                chmax(ans, sz*2);
                while(1){
                    int x = que.front();que.pop();
                    se.erase(x);
                    if(x == num[r]) break;
                }

                //if(3 <= r)if((num[r - 2] == num[r - 1]) && (num[r - 1] == num[r])) r --;
            }
        }else{
            int sz = se.size();
            chmax(ans, sz*2);
            add = 0;
            se.clear();
            queue<int> empty;   // 空のキューを用意
            swap(que, empty);
            r ++;
            if(3 <= r)if((num[r - 3] == num[r - 2]) && (num[r - 2] == num[r - 1])) r -=2;
        }
    }
    cout << ans << endl;
}

