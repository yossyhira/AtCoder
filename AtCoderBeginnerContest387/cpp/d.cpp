#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int inf = 1e9;

/* 4 方向への隣接頂点への移動を表すベクトル */
//(1, 0) (0, 1) (-1, 0), (0, -1)の4通り(斜めは無し)
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main() {

    /* 入力受け取り */
    int height, width;
    cin >> height >> width;

    //stringで1次元の配列だけど2次元のようにも扱える
    //string a[0] = "....#" -> a[0][0] = '.' になる
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];

    //一度マップを全探索してスタートとゴールを探す
    //高さ(縦)x、幅(横)yで取る。
    int sx, sy, gx, gy;
    for (int h = 0; h < height; ++h) {
        for (int w = 0; w < width; ++w) {
            if (field[h][w] == 'S') {
                sx = h;
                sy = w;
            }
            if (field[h][w] == 'G') {
                gx = h;
                gy = w;
            }
        }
    }

    /* 幅優先探索の初期設定 */
    //全て-1で初期化
    vector<vector<int>> dist(height, vector<int>(width, -1));

    //スタートの座標を0ステップ目に指定
    dist[sx][sy] = 0;

    //キューを宣言。キューに 既に発見済み(探索はまだ)でステップ数が分かって、そのマスからいける場所を探したいやつを入れる。
    //pairで座標情報を持てるようにする
    queue<pair<int, int>> que;

    //スタートの座標をキューにいれる。
    que.push(make_pair(sx, sy));

    /* 幅優先探索 */
    //キューが空(いけるマスが無くなる)になるまで繰り返す
    while (!que.empty()) {

        //これから探索する座標(この座標からいける座標を探索)
        pair<int, int> current_pos = que.front();

        //x座標を取り出す
        int x = current_pos.first;

        //y座標を取り出す
        int y = current_pos.second;

        //先頭を削除
        que.pop();

        int num = dist[x][y];

        //縦横交互の時は2で割って奇数偶数で判定するといい
        if((num % 2) == 0){
        //移動方法記述
        //移動できるか試す
        //冒頭で宣言した4通りの移動方法を試す
            for (int direction = 0; direction < 4; direction += 2) {
                //xの移動
                int next_x = x + dx[direction];
                //yの移動
                int next_y = y + dy[direction];

                //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
                if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
                //壁か確認
                if (field[next_x][next_y] == '#') continue;

                //探索済みか確認(-1なら探索してない)
                if (dist[next_x][next_y] == -1) {
                    //発見済みにする(ステップ数を登録)
                    dist[next_x][next_y] = dist[x][y] + 1; //発見した箇所は、絶対に今の座標の隣なので＋１する

                    //発見したので、あとでいけるマスを探索するようにキューに登録
                    que.push(make_pair(next_x, next_y));
                }
            }

        }else{
            for (int direction = 1; direction < 4; direction += 2) {
                //xの移動
                int next_x = x + dx[direction];
                //yの移動
                int next_y = y + dy[direction];

                //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
                if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
                //壁か確認
                if (field[next_x][next_y] == '#') continue;

                //探索済みか確認(-1なら探索してない)
                if (dist[next_x][next_y] == -1) {
                    //発見済みにする(ステップ数を登録)
                    dist[next_x][next_y] = dist[x][y] + 1; //発見した箇所は、絶対に今の座標の隣なので＋１する

                    //発見したので、あとでいけるマスを探索するようにキューに登録
                    que.push(make_pair(next_x, next_y));
                }
            }
        }
    }

    int ans = 2147483647;
    bool ng = true;
    if(dist[gx][gy] != -1) {
        ans = dist[gx][gy];
        ng = false;
    }

   //全て-1で初期化
    vector<vector<int>> dist2(height, vector<int>(width, -1));

    //スタートの座標を0ステップ目に指定
    dist2[sx][sy] = 0;

    //キューを宣言。キューに 既に発見済み(探索はまだ)でステップ数が分かって、そのマスからいける場所を探したいやつを入れる。
    //pairで座標情報を持てるようにする
    queue<pair<int, int>> que2;

    //スタートの座標をキューにいれる。
    que2.push(make_pair(sx, sy));

    /* 幅優先探索 */
    //キューが空(いけるマスが無くなる)になるまで繰り返す
    while (!que2.empty()) {

        //これから探索する座標(この座標からいける座標を探索)
        pair<int, int> current_pos = que2.front();

        //x座標を取り出す
        int x = current_pos.first;

        //y座標を取り出す
        int y = current_pos.second;

        //先頭を削除
        que2.pop();

        int num = dist2[x][y];

        if((num % 2) != 0){
        //移動方法記述
        //移動できるか試す
        //冒頭で宣言した4通りの移動方法を試す
            for (int direction = 0; direction < 4; direction += 2) {
                //xの移動
                int next_x = x + dx[direction];
                //yの移動
                int next_y = y + dy[direction];

                //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
                if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
                //壁か確認
                if (field[next_x][next_y] == '#') continue;

                //探索済みか確認(-1なら探索してない)
                if (dist2[next_x][next_y] == -1) {
                    //発見済みにする(ステップ数を登録)
                    dist2[next_x][next_y] = dist2[x][y] + 1; //発見した箇所は、絶対に今の座標の隣なので＋１する

                    //発見したので、あとでいけるマスを探索するようにキューに登録
                    que2.push(make_pair(next_x, next_y));
                }
            }

        }else{
            for (int direction = 1; direction < 4; direction += 2) {
                //xの移動
                int next_x = x + dx[direction];
                //yの移動
                int next_y = y + dy[direction];

                //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
                if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
                //壁か確認
                if (field[next_x][next_y] == '#') continue;

                //探索済みか確認(-1なら探索してない)
                if (dist2[next_x][next_y] == -1) {
                    //発見済みにする(ステップ数を登録)
                    dist2[next_x][next_y] = dist2[x][y] + 1; //発見した箇所は、絶対に今の座標の隣なので＋１する

                    //発見したので、あとでいけるマスを探索するようにキューに登録
                    que2.push(make_pair(next_x, next_y));
                }
            }
        }
    }

    if(dist2[gx][gy] != -1){
        ans = min(ans, dist2[gx][gy]);
    }
    else if ((dist2[gx][gy] == -1) && ng)
    {
        ans = -1;
    }


    /* 最短距離を出力 */
    //ゴールの座標の距離を出力
    cout << ans << endl;

    return 0;
}