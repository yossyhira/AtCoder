//順列全探索
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {

    vector<int> p(3);//3!の全探索
    rep(i, 3) p[i] = i;

    int cnt = 0, tot = 0;
    do {
        rep(i,3) cout << p[i];
        cout<<'\n';
    } while (next_permutation(p.begin(), p.end()));
    return 0;
}
/*出力
012
021
102
120
201
210
*/

//順列の例(AtCoder/cpp/054c.cpp)
//問題(https://atcoder.jp/contests/abc054/tasks/abc054_c)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// グラフを隣接行列で管理する
bool G[10][10];

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; 
        cin >> a >> b; 
        --a, --b;
        //双方向行き来できるようにする
        G[a][b] = G[b][a] = true;
    }

    // 順列
    vector<int> ord(N);
    for (int i = 0; i < N; ++i) ord[i] = i;

    // 順列を全部試すa
    int res = 0;
    do {

        //今の順列の中身
        for (int num : ord) {
            cout << num << " ";
        }
        cout<<endl;

        //開始が１(配列の都合で-1して0にした)かどうか確認
        //1で無ければやり直し
        if (ord[0] != 0) {
            cout << "今 : " << ord[0] << endl;
            break;
        }

        bool ok = true;
        for (int i = 0; i + 1 < N; ++i) {
            int from = ord[i];
            int to = ord[i+1];
            //途中に道が無ければfalseにする
            if (!G[from][to]) ok = false;
        }
        //全て道があったら答えを1増やす
        if (ok) ++res;
    } while (next_permutation(ord.begin(), ord.end()));

    cout << res << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//2分探索(376のC)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n-1);
  rep(i,n) cin >> a[i];
  rep(i,n-1) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  auto judge = [&](int x) {
    auto nb = b;
    //選んだ箱追加
    nb.push_back(x);
    sort(nb.begin(), nb.end());
    //大きさ合うか合わないか検索
    rep(i,n) if (a[i] > nb[i]) return false;
    return true;
  };

//ここが二分探索
  const int INF = 1001001001;
  int ac = INF, wa = 0;
  //×と〇の境界になるまで(差が１)ループ
  while (ac-wa > 1) {
    int wj = (wa+ac)/2;
    if (judge(wj)) ac = wj; else wa = wj;
  }
//
  if (ac == INF) cout << -1 << endl;
  else cout << ac << endl;
  return 0;
}

//////////////////////////////////////////////////////////////////////
//文字列操作
#include <bits/stdc++.h>
using namespace std;

int main() {
   string s1 = "Testtest";
   
   //一文字取り出し
   char c = s1[3]; //3文字目取り出し
   cout << "一文字取り出し : " << c << endl; //t

   //文字列追加
   s1 += "abc";         // "abc"   （文字列の追加）	
   s1.append("d");    // "d"  （文字列の追加）
   s1.push_back('e'); //末尾に一"文字"追加(引数はChar)文字列じゃ無いよ！！！！！
   cout << "文字列追加 : " << s1 << endl; //Testtestabcde

   //文字列削除
   s1.pop_back(); //末尾の1文字(e)削除
   cout << "文字列削除 : " << s1 << endl; //Testtestabcd
   s1.erase(11); //11文字目(d)を削除
   cout << "文字列削除 : " << s1 << endl; //Testtestabc
   s1.erase(8,3); //abc 削除 0始まりで、8文字目から3文字分削除
   cout << "文字列削除 : " << s1 << endl; //Testtest
   
   //文字列切り抜き(元の文字列(s1)は変わらない)
   string s1_cut = s1.substr(4); //4文字目以降を抽出
   cout << "文字列切り抜き : " << s1_cut << endl; //test
   s1_cut = s1.substr(4, 3); //4文字目から3文字分抜き出し
   cout << "文字列切り抜き : " << s1_cut << endl; //tes

   //文字列を指定した位置に追加
   s1.insert(4, "add"); //4文字目から指定した文字(add)を追加
   cout << "指定位置に文字列追加 : " << s1 << endl; //Testaddtest
   
   //文字列検索(無い場合は[-1]が返ってくる)　　＊厳密には18446744073709551615が返るけど-1でOK(詳しく：https://qiita.com/yakigac/items/8797cc256d6dcbd5e36a)
   int s1_place = s1.find("add");//何文字目から指定した文字列が始まるか
   cout << "指定した文字列の位置 : " << s1_place << endl; //4
   
   //文字列置換
   string s1_coppy = s1;
   s1.replace(4, 3, "test"); //4文字目から3文字分を削除して文字列(長さは3で無くてよい)を挿入
   cout << "指定位置の文字列を置き換え : " << s1 << endl; //Teettesttest
    //以下とやってること同じ
   s1_coppy.erase(4,3); //削除
   s1_coppy.insert(4, "test"); //追加
   cout << "指定位置の文字列を置き換え : " << s1_coppy << endl; //Teettesttest
   
   //文字列反転
   reverse(s1.begin(), s1.end());
   cout << s1 << endl; //tsettsettseT

   //文字列をソート
   string s2 = "482tTest";
   //降順
   sort(s2.begin(), s2.end());
   cout << s2 << endl; //248Testt 数字1-9▶英大文字A-Z▶英小文字a-z
   //昇順
   sort(s2.begin(), s2.end(), greater<char>());
   cout << s2 << endl; //ttseT842  英小文字z-a▶英大文字Z-A▶数字9-1
   /*
   //これでも昇順できる。事前に降順に並び替える必要ある
   reverse(s2.begin(), s2.end());
   */
}

////////////////////////////////////////////////////////////////////////////
//文字列比較
#include <bits/stdc++.h>
using namespace std;

int main() {
   string s1 = "test";

    //文字列が等しいか比較
    if(s1 == "test" ){
        cout << "test" << endl;
    }
    //文字が等しいか比較
    if(s1[0] == 't' ){
        cout << "t" << endl;
    }

    //文字が英小文字かどうか判定
    if(s1[0] >= 'a' && s1[0] <= 'z'){
        cout << "small" << endl;

    //文字が英大文字かどうか判定
    }else if(s1[0] >= 'A' && s1[0] <= 'Z'){
        cout << "large" << endl;

    //文字が数字かどうか判定
    }else if(s1[0] >= '0'){
        cout << "number" << endl;
    }

   char c;
   cin >> c;
/*
   //文字が英小文字かどうか判定
    if(c >= 'a' && c <= 'z'){
    cout << "small" << endl;

    //文字が英大文字かどうか判定
    }else if(c >= 'A' && c <= 'Z'){
    cout << "large" << endl;

    //文字が数字かどうか判定
    }else if(c >= '0'){
    cout << "number" << endl;
    }
*/
    //アルファベットか判定
    if(isalpha(c)){
        cout << "alpha" << endl;

        //文字が英小文字かどうか判定
        if(islower(c)){
            cout << "small" << endl;
            
            //大文字にする
            c += 'A' - 'a';
            if(isupper(c)){
                cout <<"large : " << c << endl;
            }

        //文字が英大文字かどうか判定
        }else if(isupper(c)){
            cout << "large" << endl;

            //小文字にする
            c -= 'A' - 'a';
            if(islower(c)){
                cout << "small : " << c << endl;
            }
        }
    //数字か判定
    }else if (isdigit(c)){
        cout << "number" << endl;
        
        //文字を数字にする
        int num = c - '0';
        cout << "int : " << num << endl;
        
        /*
        二桁の数字化
        char c2;
        cin >> c2;
        int num = (c - '0') * 10;
        int num2 = c2 - '0';
        cout << "int : " << num + num2 << endl;
        */
    }

    //文字列を数字にする
    string num_text = "123456789";
    int num = 0;    
    istringstream(num_text) >> num;
    cout << num << endl; //123456789

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
//vectorの使い方
//(https://qiita.com/ysuzuki19/items/df872d91c9c89cc31aee)
//宣言
//一次元配列
vector<int> num(3); //サイズ3, 0で初期化
vector<int> num(3, 100); //サイズ3, 100で初期化
vector<int> num_copy = num; // 配列コピー
copy(v1.begin(), v1.end(), v2.begin()); //配列コピー(上と同じ)

//追加
vector<int> num;//サイズ宣言しない。push_back使う。

for (int i = 0; i < 3; i++) {
    int hoge;
    cin >> hoge;
    num.push_back(hoge);
}

//二次元配列
vector<vector<Type>> num(3, vector<Type>(5));//サイズを3*5, 0で初期化

//サイズ変更
//一次元
num.resize(10);//サイズを10に変更, 増やした箇所は0で初期化, 既に値が場所はそのまま
//二次元
num.resize(n, vector<Type>(n));//n*nにサイズ変更

//num2という配列の末尾にnumを追加
copy(num.begin(), num.end(), front_inserter(num2));//末尾に追加

//ソート
sort(num.begin(), num.end());//昇順　12345
sort(num.begin(), num.end(), greater<int>()); //降順　54321

//要素削除
num.erase(num.begin()); //先頭削除
num.erase(num.end() - 1); //末尾削除
num.pop_back();//末尾削除
num.erase(num.begin()+i); //i番目の要素削除

// 5を探す
//イテレータを使う(https://atcoder.jp/contests/apg4b/tasks/APG4b_ai)
//簡単にいうと、要素の値が何か(例：num[1])を指すもの。そして、どの場所(1番目)にあったかも覚えてる
auto it = find(num.begin(), num.end(), 5);
cout << *it << endl;
int ans = (it != num.end()) ? distance(num.begin(), it) : -1; // 見つからなければ-1を返す

//途中に追加
// v1の1番目にv2を追加
vector<int> v1{10, 9, 8};
vector<int> v2{7, 6, 5};
v1.insert(v1.begin() + 1, v2.begin(), v2.end()); //10 7 6 5 9 8

//グリッド
int h = 8, w = 8;// 8x8のグリッド
vector<vector<char>> n(h, vector<char>(w));
for (int i = 0; i < h; i++) {
    string hoge;
    cin >> hoge; // 入力を1行受け取る
    for (int j = 0; j < w; j++) {
        n[i][j] = hoge[j]; // 文字を1つずつ格納
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//pairの使いかた
// 得点と名前の組を格納する配列(AtCoder/cpp/384c.cpp)
//宣言
vector<pair<int, string>> standings;
//追加
standings.push_back({solved_point, name});

// 昇順にソート
sort(standings.begin(), standings.end(), [](const auto& a, const auto& b) {
    return a.first < b.first;//第1引数
    return a.second < b.second;//第2引数
});
// 降順にソート
sort(standings.begin(), standings.end(), [](const auto& a, const auto& b) {
    return a.first  > b.first;//第1引数
    return a.second >  b.second;//第2引数
});

// 昇順に安定ソート(同じ値同士は元の並び順維持したまま)
stable_sort(standings.begin(), standings.end(), [](const auto& a, const auto& b) {
    return a.first < b.first;//第一引数
    return a.second < b.second;//第二引数
});
// 降順に安定ソート(同じ値同士は元の並び順維持したまま)
stable_sort(standings.begin(), standings.end(), [](const auto& a, const auto& b) {
    return a.first > b.first;//第一引数
    return a.second > b.second;//第二引数
});

//出力
//全て出力
for (const auto& entry : score) {
        cout << entry.first<<" "<<entry.second << endl;
}
//分かりやすく丁寧に出力(結果は上と同じ)
for (int i = 0; i < N; i++) {
    int a, b;
    tie(a, b) = p.at(i);  
    cout << a << " " << b << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////
//setの使い方(重複しない＆昇順に自動で並び替え)
//宣言
set<int> set;
set<int> set{ 3, 4, 2, 3 };

//追加
int Idx;
cin >> Idx;
for (int i = 0; i < Idx; i++) {
    int num = 0;
    cin >> num;
    set.insert(num);//追加
}
//追加出来たか確認
//result の型は std::pair<std::set<int>::iterator, bool>
//イテレータ（result.first）: 挿入した要素、または既存の要素を指すイテレータ
//ブール値（result.second）: 挿入が成功した場合は true、失敗（既に存在していた場合）は false
set<int> set;
auto result1 = set.insert(5); // 5 を挿入
cout << "挿入成功した？: " << result1.second << "\n"; // true
auto result2 = set.insert(5); // 再び 5 を挿入
cout << "挿入成功した？: " << result2.second << "\n"; // false

//出力1
for(auto v: set) {
    cout << v << " ";
}
//出力2
for (auto ite = set.begin(); ite != set.end(); ite++) {
    cout << *ite << " ";
}

//削除
//2という値を削除
set.erase(2);

//全要素削除
set.clear();

//値が存在するか確認
if (set.contains(3)) {
    // 「3」が存在するときの処理
    //c++のコンパイラが20以降
}
if (set.count(1)) {
    // 「1」が存在するときの処理
}
if (set.find(4) != set.end()) {
    // 「4」が存在するときの処理
}

//最大値、最小値取得
//自動で昇順なるので、先頭と末尾取得
auto minIte = set.begin();
auto maxIte = set.end() - 1;
cout << *minIte << endl; //最小
cout << *maxIte << endl; //最大

//指定した要素目の値を取得
//2番目の要素を取得
int get = 2;
 // stの先頭のイテレータを取得
auto ite = set.begin();
 // イテレータを2回進めて、2番目の要素を取得
advance(ite, get);
cout << "2番目の要素は" << *ite << std::endl;
 //intにしたいときは直接int型に入れられる
int ans = *ite;
cout << "2番目の要素は" << ans << std::endl;


//指定した値がどの要素にあるか取得(要素は0始まり)
// 5を探す
//イテレータを使う(https://atcoder.jp/contests/apg4b/tasks/APG4b_ai)
//簡単にいうと、要素の値が何か(例：num[1])を指すもの。そして、どの場所(1番目)にあったかも覚えてる
auto it = find(set.begin(), set.end(), 5);
cout << *it << endl;
int ans = (it != set.end()) ? distance(set.begin(), it) : -1; 
cout << ans << endl;

//逆順出力
// リバースイテレータで逆順に出力(reverse(set.begin(), set.end());は使えない)
for (auto it = set.rbegin(); it != set.rend(); ++it) {
    cout << *it << " ";
}
//vectorにしてreverseする
vector<int> vec(st.begin(), st.end());
reverse(vec.begin(), vec.end());
// 出力
for (int val : vec) {
    std::cout << val << " ";
}

//もしくはカスタム(詳しくは下)
struct ReverseCompare {
    bool operator()(int a, int b) const {
        return a > b; // 降順
    }
};
int main() {
    multiset<int, ReverseCompare> set; //自動で降順
}

//並び順をカスタムしたい
#include <bits/stdc++.h>
using namespace std;

// カスタム比較関数
struct CustomCompare {
    bool operator()(int a, int b) const {
        if ((a % 2 != b % 2)) { 
            return a % 2 > b % 2; // 奇数が先になるように並べていく
        }
        return a < b; // 奇数同士・偶数同士なら昇順
    }
};

int main() {
    int Idx;
    cin >> Idx;

    multiset<int, CustomCompare> multiset; // カスタム比較関数を適用
    for (int i = 0; i < Idx; i++) {
        int num = 0;
        cin >> num;
        multiset.insert(num); //7 2 4 5 9 6
    }

    // 出力
    for (auto v : multiset) {
        cout << v << " "; //5 7 9 2 4 6 <- 奇数先で、奇数同士・偶数同士なら昇順なってる
    }

    cout << "\n";
}

//setでpair使うsetpair
// pair<int, int> を格納するセット
set<pair<int, int>> st;
for (int i = 0; i < Idx; i++) {
    int num = 0, num2 = 0;
    cin >> num >> num2;
    st.insert({num, num2});
}

// セット内のペアを順番に出力
for (auto it = st.begin(); it != st.end(); ++it) {
    cout << "(" << it->first << ", " << it->second << ") ";
}

//setをvectorに変換
vector<int> vec(st.begin(), st.end());
//setpairをvec
vector<pair<int, int>> vec(st.begin(), st.end());

//vectorからset
//重複取り除かれて、昇順なってる
set<int> st(vec.begin(), vec.end());
//vecをsetにする
set<pair<int, int>> st(vec.begin(), vec.end());

/////////////////////////////////////////////////////////////////////////////
//数字を各桁ごとに配列に入れる
int a;
cin >> a;
string s = to_string(a);
int n = s.size();
vector<int> num;
for (int i = 0; i < n; i++) {
    int digit = s[i] - '0';
    num.push_back(digit); //数字を配列
}

/////////////////////////////////////////////////////////////////////////////
//bfs(幅優先探索)
/*
+------------------+----------------------------------------------------+
| メンバ関数       | 説明                                               |
+------------------+----------------------------------------------------+
| push(const T& x) | 要素 `x` をキューの末尾に追加する                   |
| pop()            | キューの先頭要素を削除する                          |
| front()          | キューの先頭要素を返す（削除しない）                |
| back()           | キューの末尾要素を返す（削除しない）                |
| empty()          | キューが空かどうかを判定する（空なら `true` を返す）|
| size()           | キューに含まれる要素数を返す                        |
+------------------+----------------------------------------------------+
*/
//宣言
queue<int> que;