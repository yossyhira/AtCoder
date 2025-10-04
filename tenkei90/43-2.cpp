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

/* 4 方向への隣接頂点への移動を表すベクトル */
//(1, 0) (0, 1) (-1, 0), (0, -1)の4通り(斜めは無し)
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const char mv[4] = { 'D', 'R', 'U', 'L' };


int main() {

    /* 入力受け取り */
    int height, width;
    cin >> height >> width;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    //stringで1次元の配列だけど2次元のようにも扱える
    //string a[0] = "....#" -> a[0][0] = '.' になる
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];


    /* 幅優先探索の初期設定 */
    //全て-1で初期化
    vector<vector<vector<ll>>> dist(height, vector<vector<ll>>(width, vector<ll>(4, -1)));

    //スタートの座標を0ステップ目に指定
    
    //キューを宣言。キューに 既に発見済み(探索はまだ)でステップ数が分かって、そのマスからいける場所を探したいやつを入れる。
    //pairで座標情報を持てるようにする
    priority_queue<tuple<ll, int, int, int, char>, vector<tuple<ll, int, int, int, char>>, greater<tuple<ll, int, int,int, char>>> que;//小さい順(昇順)に取り出す

    //スタートの座標をキューにいれる。
    /*for (int direction = 0; direction < 4; direction++) {
        //xの移動
        int next_x = sx + dx[direction];
        //yの移動
        int next_y = sy + dy[direction];
        
        //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
        if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
        //壁か確認
        if (field[next_x][next_y] == '#') continue;
        que.emplace(0, next_x, next_y, mv[direction]);
        }*/
        
        for (int i = 0; i < 4; i++) {
            dist[sx][sy][i] = 0;
            que.emplace(0, sx, sy, i, mv[i]);
        }

    /* 幅優先探索 */
    //キューが空(いけるマスが無くなる)になるまで繰り返す
    while (!que.empty()) {

        //これから探索する座標(この座標からいける座標を探索)
        ll cnt;
        int x, y, mv_idx;
        char move;
        tie(cnt, x, y, mv_idx, move) = que.top();
        que.pop();
        //if(dist[x][y] != -1) continue;
        //dist[x][y] = cnt;
        //先頭を削除
        
        //移動方法記述
        //移動できるか試す
        //冒頭で宣言した4通りの移動方法を試す
        for (int direction = 0; direction < 4; ++direction) {
            //xの移動
            int next_x = x + dx[direction];
            //yの移動
            int next_y = y + dy[direction];
            
            //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
            //壁か確認
            if (field[next_x][next_y] == '#') continue;
            //探索済みか確認(-1なら探索してない)
            if (dist[next_x][next_y][direction] == -1) {
                //発見済みにする(ステップ数を登録)
                ll plus = 0;
                if(mv[direction] != move) plus = 1;
                dist[next_x][next_y][direction] = cnt+plus;
                //発見したので、あとでいけるマスを探索するようにキューに登録
                que.emplace(cnt+plus, next_x, next_y, direction, mv[direction]);
            }
        }
    }

    /* 最短距離を出力 */
    //ゴールの座標の距離を出力
    ll ans = INF;
    for (int i = 0; i < 4; i++) {
        cout << dist[0][1][i] << endl;
        if(dist[gx][gy][i] != -1)chmin(ans, dist[gx][gy][i]);
    }
    cout << ans << endl;
    return 0;
}

/*
11 10
1 1
5 5
.......#..
.##.#..#..
...#..#...
....#..#..
...#.#....
.#.#..#...
..#..#..##
#.#.#..#..
.#...#....
..##.#....
.......#..

3 3
1 1
3 3
..#
..#
...
*/