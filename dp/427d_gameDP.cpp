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
const int mod = 1e9 + 7; //ll % modしても自動でmod型変換でllなるからバグらないよ
using Graph = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n, m, k; cin >> n >> m >> k;
        string s;
        cin >> s;
        // グラフ入力受取 (ここでは無向グラフを想定)
        Graph G(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            G[a].push_back(b);
        }
        //2人でk回ずつやるので合計k*2ターン
        int k_2 = k*2;
        //dp[i][j] = 2人合計でi回目の操作にjマス目にいたらalice,bobどっち勝つか？？
        vector<vector<bool>> dp(k_2+1, vector<bool>(n+1, false));

        //ゲームのＤＰは後ろから見る
        /*
        最後の一回を考える
        その回がbobだったとしたら移動前のマスから移動後のマスにＢが書いてある遷移があればbobは必勝
            B
            |
        A - now - B
        だったらbobが勝つ
        これを次ターンの必勝結果をもとに今のターンの必勝結果決めていけば最適解でる
        */
        //最後の状態(最後bobが動かしたあと)を初期化
        for (int i = 0; i < n; i++) {
            if(s[i] == 'A') dp[k_2][i] = true;
        }
        for (int i = (k_2-1); i >= 0; i--) {
            //有向辺なのでn*mでO(2*10^5);
            for (int j = 0; j < n; j++) {
            //i回目がaliceかbobかを判定
            //aliceは問題文より先行確定
            //0, 2, 4 => 偶数回目 alice
            //1, 3, 5 => 奇数回目 bob
            //alice = true; bob = false;とする
            bool judge = true; 
            if((i % 2) != 0) judge = false;

            for (int k = 0; k < G[j].size(); k++) {
                    //遷移全部がＡだけＢだけの可能性あって
                    //このあとのif文入らないことあるので
                    //ここで初期化
                    /*
                    詳しくは以下ケースのため
                    bobターンでどうやってもアリスしか勝たない(trueしかない)時に
                        dp[i][j] は上記宣言でfalse(bob必勝)で初期化してる
                        judge = false;
                        dp[i+1][G[j][k]] = true;
                        でif文入らない．
                        アリス必勝なので
                        dp[i][j] = true
                        にしたいけど，dp[i][j]がfalseのままなので毎ターン一応dp[i+1][G[j][k]]で初期化しておく
                        if文はいったら上書きしてbreakするので問題なし
                    */
                    dp[i][j] = dp[i+1][G[j][k]];
                    //その回のjudgeの人が必勝の遷移あるか？？
                    if(judge == dp[i+1][G[j][k]]){
                        dp[i][j] = judge;//judgeの人が必勝
                        break;
                    }
            }
            }
        }
        if(dp[0][0]) cout << "Alice\n";
        else cout << "Bob\n";
        
        /*
        //dp配列確認
        for (int i = 0; i < (k_2+1); i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
}
