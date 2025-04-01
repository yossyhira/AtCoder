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
    int que;
    cin >> que;
    for (int i = 0; i < que; i++) {
        int n;
        cin >> n;
        vector<int> num(2*n);
        for (int i = 0; i < 2*n; i++) {
            cin >> num[i];
        }
        map<P, int> M1;
        map<int, bool> seen;
        ll ans = 0;
        int befa = num[0], befb = num[1];
        bool flag = false;
        for (int i = 1; i < (2*n)-1; i++) {
            //cout << num[i] << " "<< num[i + 1] << endl;
            if(befa == befb){
                seen[befa] = true;
            }
            if(befa != befb && (befa != num[i + 1]) || (befa != befb && flag)){
                //cout << befa <<" : "<< befb << endl;
                flag = false;
                if(befa > befb) swap(befa, befb);
                if (!(seen.count(befa)) && !(seen.count(befb)) && M1.count({befa, befb})) {
                    //cout << befa <<" : "<< befb << endl;
                    ans ++;
                } else if(!seen.count(befa) && !(seen.count(befb))) {
                    M1[{befa, befb}] = 1;
                }
            }else if((befa == num[i + 1])) flag =true;

            befa = num[i]; befb = num[i + 1];
        }
       // cout << "a" << endl;
        //cout << befa <<" : "<< befb << endl;
        if(befa != befb){
            //cout << "a" << endl;
            if(befa > befb) swap(befa, befb);
            if (!(seen.count(befa))  && !(seen.count(befb))&& M1.count({befa, befb})) {
                //cout << befa <<" : "<< befb << endl;
                ans ++;
            } else {
                M1[{befa, befb}] = 1;
            }
        }
        cout << ans << endl;
       

    }

}