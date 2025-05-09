//順列全探索
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    //並び替えたい配列を作成
    //pairを使ったり複雑な並び替えはこっち
    //(AtCoder/cpp/374d.cpp)
    vector<int> p(3);//3!の全探索
    for (int i = 0; i < 3; i++) p[i] = i;

    do {
        for (int i = 0; i < 3; i++) cout << p[i];
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
   
   //文字列反転 O(N)
   reverse(s1.begin(), s1.end());
   cout << s1 << endl; //tsettsettseT
   reverse(text.begin(), text.begin()+4);//tseTtesttest 0~3文字目(4文字分)まで逆にする

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

   //特定の文字をカウント
   int c; //変数名をcountにすると下の関数名と同じ名前になるのでエラーなる
    c = count(text.begin(), text.end(), 'g');
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
    
    //数字を文字列に
    string text = to_string(num);
    cout << text << endl; //123456789


    return 0;
}

//部分文字列の回文判定(Kは部分文字列に含まれる回文の長さ)
//(AtCoder/AtCoderBeginnerContest363/cpp/c.cpp)
//(https://atcoder.jp/contests/abc363/tasks/abc363_c)
for (int i = 0; i < (N - K + 1); i++) {
    bool flag = true;
    for (int j = 0; j < K; j++) {
        if(NewText[i + j] != NewText[i + K - 1 - j]) flag = false;
    }
    if(flag)ok = false;
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
vector<vector<int>> num(3, vector<int>(5));//サイズを3*5, 0で初期化

//サイズ変更
//一次元
num.resize(10);//サイズを10に変更, 増やした箇所は0で初期化, 既に値が場所はそのまま
//二次元
num.resize(n, vector<int>(n));//n*nにサイズ変更

//num2という配列の末尾にnumを追加
copy(num.begin(), num.end(), front_inserter(num2));//末尾に追加

//ソート
//num = 4 1 3 2 5
sort(num.begin(), num.end());//昇順　12345
sort(num.begin() + 1, num.end());//1文字目から最後まで昇順　4 1 2 3 5 ＊ 配列と同じで頭は0文字目とする
sort(num.begin(), num.end(), greater<int>()); //降順　54321

//逆順
//num = 3 5 8 
reverse(num.begin() + 1, num.end());//1文字目から最後まで逆　3 8 5　＊ 配列と同じで頭は0文字目とする
reverse(num.begin(), num.end());//全て逆 8 5 3

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

//特定の数字をカウント
//O(N)
int c; //変数名をcountにすると下の関数名と同じ名前になるのでエラーなる
count(num.begin(), num.end(), 3);//numに3がいくつあるかカウント

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

//[0][0]から縦に出力
//(AtCoder/cpp/254c.cpp)
vector<int> test;
for (int i = 0; i < ((n/k) + 1); i++) {
    for (int j = 0; j < k; j++) {
        if(sep[j].size() > i){
            test.push_back(sep[j][i]);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
//pairの使いかた
// 得点と名前の組を格納する配列(AtCoder/cpp/384c.cpp)
//宣言
vector<pair<int, string>> standings;
//追加
standings.push_back({solved_point, name});

//一つ目・二つ目それぞれ別で入力もできる
vector<pair<int, int>> x(m);
for (int i = 0; i < m ; i++) {
    cin >> x[i].first;
}
for (int i = 0; i < m ; i++) {
    cin >> x[i].second;
}
//特定の場所に追加
s[Idx].second = 10;
s[Idx].first = 10;

// 昇順にソートO(nlogn)
sort(standings.begin(), standings.end(), [](const auto& a, const auto& b) {
    return a.first < b.first;//第1引数
    return a.second < b.second;//第2引数
});
// 降順にソート
sort(standings.begin(), standings.end(), [](const auto& a, const auto& b) {
    return a.first  > b.first;//第1引数
    return a.second >  b.second;//第2引数
});

// 昇順に安定ソート(同じ値同士は元の並び順維持したまま)o(n*(logn)^2)
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
//tuple使い方(AtCoder/cpp/354c.cpp)(https://atcoder.jp/contests/abc354/tasks/abc354_c)
//宣言
vector<tuple<int, int, int>> card;
//入力
for (int i = 0; i < n; i++) {
    int a, c;
    cin >> a >> c;
    card.push_back({a, c, i+1});
}
//要素数が分かっている時
vector<tuple<int, int, int>> card(n);
for (int i = 0; i < n; i++) {
    int a, c;
    cin >> a >> c;
    card[i] = {a, c, i + 1}; // 直接代入
}

//出力
for (int i = 0; i < card.size(); i++) {
    int x, y, z;
    tie(x, y, z) = card[i];
    cout << x << " " << y << " " << z << endl;
}

//特定の場所の値を変更
get<1>(card[Idx]) = 10;  // pairのsecond 相当の要素を変更
get<0>(card[Idx]) = 10;  // pairのfirst 相当の要素を変更

//ソート(O(nlogn))
//昇順
sort(card.begin(), card.end(), [](const auto &a, const auto &b) {
    return get<0>(a) < get<0>(b);//第一
    return get<1>(a) < get<0>(b);//第二
    return get<2>(a) < get<0>(b);//第三
});
//降順
sort(card.begin(), card.end(), [](const auto &a, const auto &b) {
    return get<0>(a) > get<0>(b);//第一
    return get<1>(a) > get<0>(b);//第二
    return get<2>(a) > get<0>(b);//第三
});
//安定ソート(o(n*(logn)^2))
//昇順
stable_sort(card.begin(), card.end(), [](const auto &a, const auto &b) {
    return get<0>(a) < get<0>(b);//第一
    return get<1>(a) < get<0>(b);//第二
    return get<2>(a) < get<0>(b);//第三
});
//降順
stable_sort(card.begin(), card.end(), [](const auto &a, const auto &b) {
    return get<0>(a) > get<0>(b);//第一
    return get<1>(a) > get<0>(b);//第二
    return get<2>(a) > get<0>(b);//第三
});

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
    set.insert(num);//追加//O(logN)
}
//追加出来たか確認
//result の型は std::pair<std::set<int>::iterator, bool>
//イテレータ（result.first）: 挿入した要素、または既存の要素を指すイテレータ
//ブール値（result.second）: 挿入が成功した場合は true、失敗（既に存在していた場合）は false
set<int> set;
auto result1 = set.insert(5); // 5 を挿入//O(logN)
cout << "挿入成功した？: " << result1.second << "\n"; // true
auto result2 = set.insert(5); // 再び 5 を挿入//O(logN)
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
set.erase(2);//O(logN)

//全要素削除O(N)
set.clear();

//値が存在するか確認
//全部O(logN)
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

//二分探索
//集合 set の中で x 以上である最小の要素を指すイテレーターを返す。
auto itr2 = set.lower_bound(20);
if (itr2 == set.end()) cout << "End" << endl;
else cout << (*itr2) << endl;

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

//map使い方//////////////////////////////////////////////////////////////////
//(https://qiita.com/_EnumHack/items/f462042ec99a31881a81)
//テンプレ
map<int, int> M1;
if(M1.count(x)){
    M1[x] ++;
}else{
    M1[x] = 1;
}

//宣言
// int 型の番地に int 型の変数を記録する場合（2^31 要素の int 型配列と同じような感じ）
map<int, int> M1;

// int 型の番地に string 型の変数を記録する場合（2^31 要素の string 型配列と同じような感じ）
map<int, string> M2;

// string 型の番地に double 型の変数を記録する場合
map<string, double> M3;

//入力 : O(log N)
map<string, int> Map;
Map["qiita"] = 777;
Map["algorithm"] = 1111;
Map["competitive_programming"] = 1073741824;

//出力 : O(log N)
cout << Map["algorithm"] << endl; // 1111 と出力される
cout << Map["tourist"] << endl; // まだ何も書き込まれていないので、0 と出力される

//pairをキー
map<pair<int, int>, int> M1;//(AtCoder/AtCoderBeginnerContest393/cpp/c.cpp)
//入力
M1[{a, b}] = 1;
//キーがあるか確認 : O(log N)
if(M1.count(a))//あればtureなければfalse
if(M1.count({a, b}))//あればtureなければfalse

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
//木構造/////////////////////////////////////////////////////////////////////
//単純無向グラフとかは何個かグラフ分かれてる
//グラフが一つだけのときは単純”連結”無向グラフ
//グラフのサイクル → 閉路で一周して元の場所にかえって来れるやつ（abc404/c）

/////////////////////////////////////////////////////////////////////////////
//bfs(幅優先探索)
//グラフで連結成分がいくつか分かれてる時(AtCoder/bfs/399c.cpp)
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

//グリッド問題(スタートからゴールまでの最短距離)
//例（AtCoder/AtCoderBeginnerContest387/cpp/d.cpp）<- 縦横交互の時は2で割って奇数偶数で判定するといい
//問題(https://qiita.com/drken/items/6a95b57d2e374a3d3292)
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

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
            if (dist[next_x][next_y] == -1) {
                //発見済みにする(ステップ数を登録)
                dist[next_x][next_y] = dist[x][y] + 1; //発見した箇所は、絶対に今の座標の隣なので＋１する

                //発見したので、あとでいけるマスを探索するようにキューに登録
                que.push(make_pair(next_x, next_y));
            }
        }
    }

    /* 最短距離を出力 */
    //ゴールの座標の距離を出力
    cout << dist[gx][gy] << endl;

    return 0;
}

//多始点bfs//////////////////
//問題（https://atcoder.jp/contests/abc383/tasks/abc383_c）
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/* 4 方向への隣接頂点への移動を表すベクトル */
//(1, 0) (0, 1) (-1, 0), (0, -1)の4通り(斜めは無し)
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main() {

    /* 入力受け取り */
    int height, width, d;
    cin >> height >> width >> d;

    //stringで1次元の配列だけど2次元のようにも扱える
    //string a[0] = "....#" -> a[0][0] = '.' になる
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];

    //一度マップを全探索して加湿器を探す
    //高さ(縦)x、幅(横)yで取る。
    //加湿器の座標入れ
    vector<pair<int, int>> humidifier;
    for (int h = 0; h < height; ++h) {
        for (int w = 0; w < width; ++w) {
            if (field[h][w] == 'H') {
                humidifier.push_back({h,w});
            }
        }
    }

    /* 幅優先探索の初期設定 */
    //加湿マスカウンター
    int count = 0;
    //加湿マスかどうか記録
    vector<vector<bool>> humidifier_Grid(height, vector<bool>(width, false));

    //全て-1で初期化
    vector<vector<int>> dist(height, vector<int>(width, -1));

    //キューを宣言。キューに 既に発見済み(探索はまだ)でステップ数が分かって、そのマスからいける場所を探したいやつを入れる。
    //pairで座標情報を持てるようにする
    queue<pair<int, int>> que;
    
    //多始点BFSでは、最初のスタート位置を全てキューに持たせておくのがポイント
    for (int i = 0; i < humidifier.size(); i++) {
        //今回の加湿器の座標
        pair<int, int> humidifier_pos = humidifier.at(i);

        //x座標を取り出す
        int humidifier_X = humidifier_pos.first;

        //y座標を取り出す
        int humidifier_Y = humidifier_pos.second;

        //スタートの座標を0ステップ目に指定
        dist[humidifier_X][humidifier_Y] = 0;

        //加湿器の座標も加湿する
        humidifier_Grid[humidifier_X][humidifier_Y] = true;
        count ++;

        //スタートの座標をキューにいれる。
        que.push(make_pair(humidifier_X, humidifier_Y));
    }

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
            //自分以外の加湿器の場所は加湿したくない(このアルゴリズムだと冒頭で探索済み判定なってるので以下は無駄)
            //if (field[next_x][next_y] == 'H') continue;

            //探索済みか確認(-1なら探索してない)
            if ((dist[next_x][next_y] == -1)) {
                //ステップ数確認
                int step = dist[x][y] + 1;
                //ステップ数が加湿距離範囲内だったら探索済みにする
                if(step <= d){
                    //発見済みにする(ステップ数を登録)
                    dist[next_x][next_y] = step; //発見した箇所は、絶対に今の座標の隣なので＋１する

                    //加湿してればカウント。してなければただその上を”通る”だけ。
                    //通ることはできるので、加湿してたらcontiueだと間違えなる。
                    if(!(humidifier_Grid[next_x][next_y])){
                        //加湿マスをカウント
                        humidifier_Grid[next_x][next_y] = true;
                        count ++;
                    }
                    //発見したので、あとでいけるマスを探索するようにキューに登録
                    que.push(make_pair(next_x, next_y));
                }
            }
        }
    }
    

    /* 加湿マスを出力 */
    cout << count << endl;

    return 0;
}

//01BFS/////////////////////////////////////////////////////////
//01BFS(普通のBFSとダイクストラの概念を混ぜた感じ)
//普通の場合と特殊な場合の2パターンがあるBFS
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int di[] = {-1,0,1,0};
int dj[] = {0,-1,0,1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  int si, sj, ti, tj;
  cin >> si >> sj >> ti >> tj;
  --si; --sj; --ti; --tj;

  const int INF = 1001001001;
  vector<vector<int>> dist(h,vector<int>(w, INF));
  vector<vector<bool>> used(h,vector<bool>(w));
  deque<pair<int,int>> q;

  // i, j : 座標
  // d : その頂点までの総距離（コスト）
  // cost : その辺単体の重み(dequeの前か後のどっちに入れるのか判別に使う)
  auto push = [&](int i, int j, int d, int cost) {
    //最短距離更新するかどうか
    if (dist[i][j] <= d) return;
    dist[i][j] = d;
    //コストが0なら前，1なら後ろに追加
    if (cost == 0) q.emplace_front(i,j);
    else q.emplace_back(i,j);
  };
  push(si,sj,0,0);

  while (q.size()) {
    //最短距離で取り出しているので，見てなければ距離確定
    int i, j;
    tie(i, j) = q.front(); q.pop_front();
    if (used[i][j]) continue;
    //その座標を見たにする
    used[i][j] = true;
    //その座標の距離
    int d = dist[i][j];

    //普通の道(コスト0)
    rep(v,4) {
      int ni = i+di[v], nj = j+dj[v];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '.') push(ni,nj,d,0);
    }
    //壁の道(コスト1)
    //普通の道でも壁とみなして移動する
    //普通の道の方はif (used[i][j]) continue;かコスト0なのでpush関数のif (dist[i][j] <= d) return;ではじいてくれる
    rep(v,4) {
      int ni = i, nj = j;
      //壁の2マス分同じ方向に移動
      rep(k,2) {
        ni += di[v]; nj += dj[v];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) break;
        push(ni,nj,d+1,1);
      }
    }
  }

  int ans = dist[ti][tj];
  cout << ans << endl;
  return 0;
}

//グラフの問題(各頂点までの距離)//////////////////////////////////
//問題(https://qiita.com/drken/items/996d80bcae64649a6580)
//類似問題(AtCoder/bfs/376d.cpp)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//可変長の配列
using Graph = vector<vector<int>>;
//(https://qiita.com/drken/items/4a7869c5e304883f539b#2-%E8%A8%88%E7%AE%97%E6%A9%9F%E4%B8%8A%E3%81%A7%E3%81%AE%E3%82%B0%E3%83%A9%E3%83%95%E3%81%AE%E8%A1%A8%E3%81%97%E6%96%B9)

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に(-1)初期化
    queue<int> que; 

    // 初期条件 (頂点 0 を初期ノードとする)
    //dist[v] はスタート頂点から頂点 v まで最短何ステップで到達できるかを表す
    int start = 0;
    dist[start] = 0; //スタートは0ステップ
    //その時点での橙色頂点 (発見済みだが未訪問な頂点) を格納するキュー
    que.push(start); // スタートを橙色(自分からいける場所を見たい)頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop(); //先頭削除

        // 自分（v） から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済み(ステップ数が分かってる)の頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            //distは各頂点の最短ステップ数
            dist[nv] = dist[v] + 1; //自分がいる所の次なので自分の場所から1ステップ増やす
            que.push(nv);//発見した(そこまでのステップ数が分かった)ので
                         //自分からいける場所を後で調べる
        }
        /*
        for (int i = 0; i < G[v].size(); i++) {
            int nv = G[v][i];
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
        */
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}

//dequeの使い方/////////////////////////////////////////////////////////////////////////////////////////////////
//(AtCoder/cpp/237d.cpp)
// (AtCoder/cpp/372d.cpp) <= define関数あり
// 挿入・削除の計算量比較
//
//| 操作                   | `vector`                     | `deque`  |
//|------------------------|-----------------------------|----------|
//| `push_back()`          | **O(1)** (アモルタイズド)    | **O(1)** |
//| `push_front()`         | **O(N)** (全要素を移動)     | **O(1)** |
//| `pop_back()`          | **O(1)**                     | **O(1)** |
//| `pop_front()`         | **O(N)** (全要素を移動)     | **O(1)** |
//| `insert(pos, val)`    | **O(N)**                     | **O(N)** |
//| `erase(pos)`          | **O(N)**                     | **O(N)** |
//| `operator[]` (ランダムアクセス) | **O(1)**             | **O(1)** |

//dequeは先頭と末尾に要素を追加していきたいときに使える。
//ほとんどvectorと同じだが、dequeは先頭に値を追加する時の計算量がO(1)で済む

//宣言
deque<int> deq;

//先頭追加
deq.push_front(5);

//末尾追加
deq.push_back(5);

//特定の要素の値を変更 : O(1)
deq[0] = 0; 

//出力
for(int x : deq){
    cout << x << " ";
}
cout << endl;

///dfs 深さ優先探索///////////////////////////////////////////////////////////////////////////////
//グリッド系
//(https://qiita.com/drken/items/4a7869c5e304883f539b)
//AtCoder/dfs/grid.cpp
//ゴールまで行けるかいけないか判定。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
int H, W;
vector<string> field;

// 探索
bool seen[510][510]; // seen[h][w] := マス (h, w) が検知済みかどうか
void dfs(int h, int w) {
    seen[h][w] = true;

    // 四方向を探索
    for (int dir = 0; dir < 4; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        // 場外アウトしたり、移動先が壁の場合はスルー
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;

        // 移動先が探索済みの場合
        if (seen[nh][nw]) continue;

        // 再帰的に探索
        dfs(nh, nw);
    }
    //いろいろな動きのパターンを調べたいとき(同じ動線でも動くマス順番が変わると答えも変わる場合など)
    //今回はゴールに一度でもいければ良いのでいらない
    //これは(AtCoder/dfs/378d.cpp)(https://atcoder.jp/contests/abc378/tasks/abc378_d)
    //seen[h][w] = false;
}

int main() {
    // 入力受け取り
    cin >> H >> W;
    field.resize(H);
    for (int h = 0; h < H; ++h) cin >> field[h];

    // s と g のマスを特定する
    int sh, sw, gh, gw;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (field[h][w] == 's') sh = h, sw = w;
            if (field[h][w] == 'g') gh = h, gw = w;
        }
    }

    // 探索開始
    memset(seen, 0, sizeof(seen)); // seen 配列全体を false に初期化
    dfs(sh, sw);

    // 結果
    if (seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

//木構造/////////////////////////
//AtCoder/dfs/1.cpp
//(https://qiita.com/drken/items/4a7869c5e304883f539b)
//O(N+M)
//行きがけ順、帰りがけ順
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> first_order; // 行きがけ順
vector<int> last_order; // 帰りがけ順

void dfs(const Graph &G, int v, int& first_ptr, int& last_ptr) {
    // 行きがけ順をインクリメントしながらメモ
    //first_ptr++というのは、値を追加した後に1足すという意味。
    //++first_ptrにすると追加する前に1足す
    first_order[v] = first_ptr++;
    
    //vを探索済みにする
    seen[v] = true; 

    //vからいける場所を探索
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;//探索済みならコンティニュー
        dfs(G, next_v, first_ptr, last_ptr);
    }

    // 帰りがけ順をインクリメントしながらメモ
    //全部行き終わったら値を追加
    last_order[v] = last_ptr++;
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    //assignはresize + 変数初期化
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    //resize
    first_order.resize(N);
    last_order.resize(N);
    int first_ptr = 0, last_ptr = 0;
    dfs(G, 0, first_ptr, last_ptr);

    /*
    (AtCoder/dfs/373d.cpp)
    //グラフが一つにまとまってない時は以下を繰り返す
    // 訪問済みか一つずつみて未訪問であれば探索(この時に一つのグラフ内で探索したやつは訪問済みに置き換わる)
    //一つのグラフが探索完了したのにまだ未探索なものは別のグラフにあるので新たな始点として探索
    for (int i = 0; i < N; i++) {
        if(seen[i] == false){
            //始点の値はなんでもよいので適当に0とした
            ans[i] = 0;
            dfs(G, i);
        }
    }
    */

    // 各頂点 v の行きがけ順、帰りがけ順を出力
    for (int v = 0; v < N; ++v)
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
}

//スタック//////////////////////////////////////////////////////////////////////
/*
+------------------+----------------------------------------------------+
| メンバ関数       | 説明                                               |
+------------------+----------------------------------------------------+
| push(const T& x) | 要素 `x` をキューの末尾に追加する                   |
| pop()            | キューの先頭要素を削除する                          |
| top()            | キューの先頭要素を返す（削除しない）                |
| back()           | キューの末尾要素を返す（削除しない）                |
| empty()          | キューが空かどうかを判定する（空なら `true` を返す）|
| size()           | キューに含まれる要素数を返す                        |
+------------------+----------------------------------------------------+
*/
//宣言
stack<int> s;
//追加
s.push(10);
s.push(20);
//取り出し
cout << s.top() << endl;  //20
//削除
s.pop();
cout << s.top() << endl;  //10
//値変更
s.top -= 5;
cout << s.top() << endl;  //5

//二分探索、upper_bound(より大きい)、lower_bound(以上)////////////////////////////
//問題(AtCoder/cpp/371sunuke.cpp)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), p(n);
  rep(i,n) cin >> x[i];
  rep(i,n) cin >> p[i];
  
  vector<ll> s(n+1);
  rep(i,n) s[i+1] = s[i]+p[i];

  rep(i, n+1){
    cout << s[i] << " ";
  }
  cout << endl;
  //retunない時もvoidはいらない(AtCoder/cpp/372d.cpp)
  auto f = [&](int r) {
    int pos = upper_bound(x.begin(), x.end(), r) - x.begin(); //lower_bound(x.begin(), x.end(), r) - x.begin();
    cout << pos << endl;
    return s[pos];
  };
  /*
  // 探す値がlong long ver
  auto f = [&](ll r) {
        int pos = upper_bound(b.begin(), b.end(), r) - b.begin(); //lower_bound(x.begin(), x.end(), r) - x.begin();
        cout << pos << endl;
        return s[pos];
    };
  */
  int q;
  cin >> q;
  rep(qi,q) {
    int l, r;
    cin >> l >> r;
    ll ans = f(r) - f(l-1);
    cout << ans << '\n';
  }
  return 0;
}

//最大公約数と最小公倍数/////////////////////////////////////////////////////
//(https://qiita.com/e869120/items/518297c6816adb67f9a5)
//gcd -> 最大公約数と最小公倍数
//O(log a)
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 例 1: 2 つの整数 a, b を入力し、a と b の最大公約数と最小公倍数を出力する
    int a, b;
    cin >> a >> b;
    cout << __gcd(a, b) << endl;//最大公約数
    cout << a / __gcd(a, b) * b << endl;//最小公倍数
    return 0;
}

//bitビット///////////////////////////////////////////////////////////
//__builtin_popcount(x);int型 の整数 x を二進数で表したとき、1 のビットの個数を返す関数
//__builtin_popcountll(x); long long型 の整数 x を二進数で表したとき、1 のビットの個数を返す関数
//O(log x)
//0Idxで1,2,4,7,8,11,13,14...に1が立ってるやつはこれかも
//(AtCoder/saiki/380d2.cpp)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    int c = 0;
    c = __builtin_popcount(x);//int 1の個数
    //ll x;
    //cin >> x;
    //ll c = 0;
    //c = __builtin_popcountll(x);//long long １の個数
    cout << c << endl;
    return 0;
}

//bitset////////////////////////////////////////
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// 汎用的なbitset出力関数
void out(const bitset<2000>& bs) {
    bool flag = false;
    for (int i = 1999; i >= 0; i--) {
        if (bs[i] == 1) flag = true; // 頭の余計な0をスキップ
        if (flag) cout << bs[i];
    }
    if (!flag) cout << "0"; // 全部0なら "0" を出力
    cout << endl;
}

int main() {
    int A, B;
    cin >> A >> B;
    
    bitset<2000> A1(A);
    bitset<2000> B1(B);
    bitset<2000> OR  = (A1 | B1);  // OR 計算
    bitset<2000> AND = (A1 & B1);  // AND 計算
    bitset<2000> XOR = (A1 ^ B1);  // XOR 計算
    bitset<2000> NOT = (~A1);      // NOT 計算
    bitset<2000> LSHIFT = (A1 << 1); // 左シフト
    bitset<2000> RSHIFT = (A1 >> 1); // 右シフト

    cout << "OR   : "; out(OR);
    cout << "AND  : "; out(AND);
    cout << "XOR  : "; out(XOR);
    cout << "NOT  : "; out(NOT);
    cout << "LSHFT: "; out(LSHIFT);
    cout << "RSHFT: "; out(RSHIFT);

    return 0;
}

//配列にする
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    int N = 3; // 行数
    vector<bitset<2000>> bits(N); // 2000ビットのbitsetをN個持つベクター

    // 適当に値を代入
    bits[0] = bitset<2000>(5);  // 000...0000101 (5 = 101)
    bits[1] = bitset<2000>(10); // 000...0001010 (10 = 1010)
    bits[2] = bitset<2000>(15); // 000...0001111 (15 = 1111)

    // 出力
    for (int i = 0; i < N; i++) {
        cout << "bits[" << i << "] = " << bits[i] << endl;
    }

    return 0;
}


//約数列挙////////////////
//ソートなしO(root(N))
//ソートするとO(root(N)logN)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getDivisors(int N) {
    vector<int> divisors;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            divisors.push_back(i);
            if (i != N / i) {
                divisors.push_back(N / i);
            }
        }
    }
    //sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> divisors = getDivisors(N);
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}

//累積和////////////////////////////////////////////////////////////
//一次元
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n+1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num[i+1] = num[i] + x;
    }

    //確認
    for (int i = 0; i < n + 1; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    
    //クエリ
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int Lx, Rx;
        cin >> Lx >> Rx;
        Lx --;
        cout << num[Rx] - num[Lx] << endl;
    }
    return 0;
}
/*
//入力
5  
1 1 1 1 1

//確認
0 1 2 3 4 5 

//クエリ
1
3 5　//入力の3~5個目の和
3
*/
//二次元(https://qiita.com/drken/items/56a6b68edef8fc605821)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力: H × W のグリッド
    int H, W; cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];

    // 二次元累積和
    vector<vector<int> > s(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            //求めたいマス s[i+1][j+1]の　上＋左-上下の累積の重なりs[i][j]を引く＋最後に求めたいマスの値a[i][j]を足す
            //求めたいマス s[i+1][j+1]の左上s[i][j]基準なので
            //求めたいマス s[i+1][j+1]の 上：s[i][j+1]　左：s[i+1][j]になる
            //最後に求めたいマスの値a[i][j]を足す 
            //👆配列sは外側に無駄な0があるのでs[i+1][j+1]とa[i][j]同じ場所を表している
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    //確認
    for (int i = 0; i < H+1; ++i){
        for (int j = 0; j < W+1; ++j){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
        
    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        x1 --; y1 --;
        //最大値 s[x2][y2]の累積から縦横の余分な累積　s[x1][y2]　s[x2][y1]を引いて
        //重なり部分のs[x1][y1]を余計に引いたので足す
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }
}
/*
//入力
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

//確認
0 0 0 0 0 0 
0 1 2 3 4 5 
0 2 4 6 8 10 
0 3 6 9 12 15 
0 4 8 12 16 20 
0 5 10 15 20 25 

//クエリ
1
5 5 1 5　//入力の5行目から5行目までの1列目から5列目までの和
5
*/

//三次元///
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 3D配列の初期化
    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n, 0)));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> a[i][j][k];
            }
        }
    }

    // 累積和の計算
    vector<vector<vector<long long>>> sum(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                sum[i + 1][j + 1][k + 1] =
                    sum[i][j + 1][k + 1] + sum[i + 1][j][k + 1] +
                    sum[i + 1][j + 1][k] - sum[i][j][k + 1] - sum[i][j + 1][k] -
                    sum[i + 1][j][k] + sum[i][j][k] + a[i][j][k];
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        lx--, ly--, lz--;
        //lxなどで0が与えられても-1となりエラーならないように
        // 境界をはみ出さないように max(0, lx) で補正
        long long result = sum[rx][ry][rz]
                         - sum[max(0, lx)][ry][rz]
                         - sum[rx][max(0, ly)][rz]
                         - sum[rx][ry][max(0, lz)]
                         + sum[max(0, lx)][max(0, ly)][rz]
                         + sum[max(0, lx)][ry][max(0, lz)]
                         + sum[rx][max(0, ly)][max(0, lz)]
                         - sum[max(0, lx)][max(0, ly)][max(0, lz)];
        
        cout << result << "\n";
    }
}
//差分累積
// （AtCoder/cpp/334c_1.cpp）
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    if(k == 1){
        cout << 0 << endl;
        return 0;
    }
    int num = k / 2;
    int ans = 0;
    //ｋが偶数なら隣同士
    if((k % 2) == 0){
        for (int i = 1; i <= num; i++) {
            ans += a[((i - 1)*2) + 1] - a[(i - 1)*2];
        }cout << ans << endl;
        return 0;
    }
    vector<int> Foward(num + 1,0);
    vector<int> Back(num + 1,0);
    for (int i = 1; i <= num; i ++) {
        Foward[i] = Foward[i - 1] + (a[((i - 1)*2) + 1] - a[(i - 1)*2]);
    }
    for (int i = 1; i <= num; i ++) {
        Back[i] = Back[i - 1] + (a[i * 2] - a[((i - 1)*2) + 1]);
    }
    
    ans = Foward[num]; //最後除外
    //cout << ans << endl;
    ans = min(ans, Back[num]); //0番目除外
    //cout << Back[num] << endl;

    //1~最後-1番目まで一つずつ除外したパターン
    for (int i = 1; i < k-1; i++) {
        int subAns = 0;
        //奇数
        if((i % 2) != 0){
            int Idx = (i / 2);
            subAns = Foward[Idx] + (a[i+1] - a[i-1]) + (Back[num] - Back[((i + 2)/ 2)]);//前までの差＋新しいペア＋後ろの差
        }else{//偶数
           int Idx = (i / 2);
           subAns = Foward[Idx] + (Back[num] - Back[((i + 1)/ 2)]);//前までの差＋後ろの差
        }
        //cout << i << "回目　"<< subAns << endl;
        ans = min(ans, subAns);
        
    }
    cout << ans << endl;
    return 0;
}

//DP/////////////////////////////////////////////////////////////////////////////////
// ========================
//  DPの種類ごとの初期値表
// ========================

/*
| DPの種類                  | 初期値                         |
|---------------------------|--------------------------------|
| 状態DP (最大価値)  　　　　| 全てINF -> dp[0] = 0 or dp[0][j]=0|
| ナップサックDP (最大価値)  | dp[0][j] = 0                  |
| 最短経路DP (最小コスト)    | dp[0] = 0, 他は INF           |
| 部分和DP (特定の和が作れるか) | dp[0] = true, 他は false    |
| コイン問題 (最小枚数)      | dp[0] = 0, 他は INF           |
| 道順の数え上げDP           | dp[0][0] = 1, 他は 0          |
*/


//状態DP//////////////
//(AtCoder/dp/365d.cpp)(https://atcoder.jp/contests/abc365/tasks/abc365_d)
//じゃんけんで前の手を連続せずに勝つ最大値を求める
//じゃんけんのように不可能な手がないときは
// (AtCoder/dp/frag2_1.cpp)のようにまとめて考える
//AtCoder/dp/403d.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string text;
    cin >> text;
    //マイナス無限でDP配列初期化
    //DPにはその回までの各手の置ける勝利数の最大値を格納
    const int INF = 1001001001;
    vector<vector<int>> dp(n+1,vector<int>(3, -INF)); //最初0を置きたいため、n+1の配列にしたので注意
    //最初はすべて0で初期化
    for (int i = 0; i < 3; i++) dp[0][i] = 0;

    for (int i = 0; i < n; i++) {
        //文字だと扱いづらいので相手の手を数値変換
        int x = 0;
        if(text.at(i) == 'R') x = 0;
        else if(text.at(i) == 'P') x = 1;
        else if(text.at(i) == 'S') x = 2;

        //DPをおこなう
        //今出す手を0~2で全探索
        for (int nowHand = 0; nowHand < 3; nowHand++) {
            //相手の手に勝てば＋１, あいこは０, 今回は負ける場合は計算しない(問題記載)
            int win = 0;
            if(x == (nowHand + 2) % 3) win = 1;
            else if( x == (nowHand + 1) % 3) continue;
            
            //前に出した手までの勝利数を0~2ですべて調べる
            for (int befHand = 0; befHand < 3; befHand++) {
                //前の手と同じ手は出せない
                if(nowHand == befHand) continue;

                //前の回の結果をもとに今回の手の最大値を計算
                dp[i + 1][nowHand] = max(dp[i + 1][nowHand], dp[i][befHand] + win);
            }
        }
    }

    //最後の回の各手における勝利数の最大値を計算
    int ans = max({dp[n][0], dp[n][1], dp[n][2]}); 
    cout << ans << endl;
}

//ナップサックDP///////////////////////////////
//(AtCoder/dp/knapsack1.cpp)
//荷物に入る重さいないで最大価値を選ぶ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //宝石の個数と最大の重さ
    int n, weightMax;
    cin >> n >> weightMax;

    //重さと価値を格納
    vector<ll> weight(n);
    vector<ll> val(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> val[i];
    }
    //0でDP配列初期化
    //DPにはその回までかつその重さ内での最大価値を格納
    //最大価値がintの範囲外になる可能性に注意(long long にする)
    vector<vector<ll>> dp(n+1,vector<ll>(weightMax+1, 0)); //1行目と1列目に0を置きたいため、n+1, weightMax+1の配列にしたので注意

    //入れる宝石(i)を決める
    for (int i = 0; i < n; i++) {

        //その宝石の価値
        ll value = val[i];

        //各jの重さが限界の重さであると仮定して、その重さ内での最大価値について探索
        for (int j = 0; j <= weightMax; j++) {
            
            //入れる場合
            //追加した宝石がその重さ(j)以内だったら
            //重さの限界値のjをweight[i]超えていたら
            //j - weight[i]がマイナスになり、宝石が入らないと判定できる
            //つまりj - weight[i]が0以上なら宝石が入る
            if((j - weight[i]) >= 0){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j - weight[i]] + value);
            }

            //入れない場合
            //上記で重さ(j)以内に入っても（入らなくても）宝石を入れなかった場合が最大価値になる可能性があるので調べる
            //宝石を入れなかったということは、つまり重さも価値も0の物を入れたとも考えられるので
            // weight[i] = 0, value = 0より（dp[i][j - weight[i]] + value = dp[i][j -0] + 0 = dp[i][j]）となり
            // 純粋に自分の前の宝石ときの最大価値（dp[i][j]）を引き継ぐ
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
        
    }

    //最後の回の最大価値を調べる
    //n個眼目の宝石の処理が終わって、
    //重さがweightMax以内のときの最大価値は[n][weightMax]番目になる
    cout << dp[n][weightMax] << endl;
    return 0;
}

//ダイクストラ///////////////////////////////////////////////////////////////////////////////////////////////
//ここは普通のダイクストラ。下の拡張ダイクストラの方がよく出る
//(AtCoder/dijkstra/362d.cpp)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n); //頂点のコスト
  for(int i = 0; i < n; i ++) cin >> a[i];

  vector<vector<Edge>> g(n);
  for (int i = 0; i < m; i++) {
      int u,v,b;
      cin >> u >> v >> b;
      u--; v--;
      g[u].emplace_back(v, b+a[v]); //uからvに行くためにコストb+a[v]かかる
      g[v].emplace_back(u, b+a[u]); //vからuに行くためにコストb+a[v]かかる
  }

  const ll INF = 1e18;
  vector<ll> dist(n, INF); //各頂点までのコストを格納(確定済みと未確定のやつが入ってる)
  //最短距離の候補を入れる
  //pair<コスト, 頂点>
  priority_queue<P, vector<P>, greater<P>> q;//小さい順(昇順)に取り出す
  //priority_queue<P> q;//大きい順(降順)に取り出す
  dist[0] = a[0]; //最初の距離はa[0]
  q.emplace(a[0], 0); //(コスト, 頂点)最初の頂点は0

  int count = 0;
  while (!q.empty()) {
    //cout << count << "回目" << endl;
    count ++;
    ll d; //距離
    int point; //頂点
    tie(d, point) = q.top(); q.pop();
    //dist[point]には今の距離が入ってる
    //dが今の距離と違う = 更新前のキューを取り出したので見ない(結果は変わらないけど無駄な探索になる)
    //一致したら最短距離確定
    if (dist[point] != d) {
      cout << "dist[point] : "<< dist[point] << endl;
      cout << "d : "<< d << endl;
      continue;
    }
    //cout << "dist[point] : "<< dist[point] << endl;
    //cout << "d : "<< d << endl;

    //今の頂点point(確定済み)からいける場所をすべて試す
    for (int goPoint = 0; goPoint < g[point].size(); goPoint++) {
      //その頂点からいける場所とコストを取得
      Edge e = g[point][goPoint];
      //その場所までのコストdと行先の道のコストを足して
      // 行先のコストを取得
      ll newd = d + e.cost;
      //新しいコストのほうが行先のコストe.to以上ならコンティニュー
      if (dist[e.to] <= newd) continue;
      //距離を更新
      dist[e.to] = newd; 
      //新しいコストと行先を追加
      q.emplace(newd,e.to);
    }
  }

  for (int i = 1; i < n; i++) cout << dist[i] << ' ';
  cout << endl;
  return 0;
}
//拡張ダイクストラ//////////////////////////////////////////////////////////////
//(AtCoder/dijkstra/395e.cpp)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

int main() {
  int n, m, x;
  cin >> n >> m >> x;
 ///////////////////////////////////////////////////////////////////////
 //拡張ダイクストラは複数のパターンの頂点を用意(今回は順方向・逆方向の2パターン)
 // i : 頂点番号 (6 頂点の場合(i = 0 ~ 5))
 // a : 普通のパターン頂点(順方向) => (i * 2) - 2
 // b : 特殊パターン頂点(逆方向) => (i * 2) - 1
 // i | 0 | 1 | 2 | 3 | 4 | 5 |
 // a | 0 | 2 | 4 | 6 | 8 | 10 |
 // b | 1 | 3 | 5 | 7 | 9 | 11 |
  vector<vector<Edge>> g(n*2);
  for (int i = 1; i <= n; i ++) {
    int from = (i * 2) - 2;
    int to = (i * 2) - 1;
    //順方向から逆方向に変えるときのコスト
    g[from].emplace_back(to, x); 
    g[to].emplace_back(from, x);
  }
  for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      //順方向同士のコスト
      int conU = (u * 2) - 2; 
      int conV = (v * 2) - 2;
      g[conU].emplace_back(conV, 1); //移動のコストは1

      //逆方向同士のコスト
      int revU = (u * 2) - 1; 
      int revV = (v * 2) - 1;
      g[revV].emplace_back(revU, 1); //移動のコストは1
  }

  const ll INF = 1e18;
  vector<ll> dist(2*n, INF); //各頂点までのコストを格納(確定済みと未確定のやつが入ってる)dist[0]には頂点0のコスト

  //最短距離の候補を入れる
  priority_queue<P, vector<P>, greater<P>> q;//小さい順(昇順)に取り出す
  //priority_queue<P> q;//大きい順(降順)に取り出す
  // 降順は(priority_queue<P, vector<P>, less<P>> q;)とも書けるが、less<P>>はデフォルトで省略される(上とやってることは全く同じ)
  dist[0] = 0; //最初の距離は0 dist[スタート頂点] = 初期コスト;
  q.emplace(0, 0); //最初の頂点は0 q.emplace(初期コスト, スタート頂点);

  while (!q.empty()) {
    ll d; //距離(コスト)
    int point; //頂点
    tie(d, point) = q.top(); q.pop();
    //dist[point]には今の距離が入ってる
    //dが今の距離と違う = 更新前のキューを取り出したので見ない(結果は変わらないけど無駄な探索になる)
    //一致したら最短距離確定
    if (dist[point] != d) continue;
    
    //今の頂点point(確定済み)からいける場所をすべて試す
    for (int goPoint = 0; goPoint < g[point].size(); goPoint++) {
      //その頂点からいける場所とコストを取得
      Edge e = g[point][goPoint];
      //その場所までのコストdと行先の道のコストを足して
      // 行先のコストを取得
      ll newd = d + e.cost;
      //新しいコストのほうが行先のコストe.to以上ならコンティニュー
      if (dist[e.to] <= newd) continue;
      //距離を更新
      dist[e.to] = newd;
    
      //新しいコストと行先を追加
      q.emplace(newd,e.to);
    }
  }
  //2パターンの内の最小を選ぶ
  cout << min(dist[(n * 2) - 2], dist[(n * 2) - 1])<< endl;
  return 0;
}

//数直線の一か所に何かを集める系////////////////////////////////////////////////////////////////////////////
//ここでは1を一か所に集めていく
//(AtCoder/AtCoderBeginnerContest393/cpp/d.cpp)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string text;
    cin >> n >> text;
    vector<int> one;
    int oneCount = 0;
    for (int i = 0; i < text.size(); i++) {
        if(text.at(i) == '1'){
            oneCount ++;
            one.push_back(i);
        }
    }
    //一か所に集めるのは中央値が最適
    int point = oneCount / 2;
    ll ans = 0;
    for (int i = 0; i < point; i++) {
        ans += ll(one.at(point) - one.at(i) - i - 1);//前にある1の個数も考慮(-i)して、移動回数は数直線の距離-1
        //cout << ans << endl;
    }
    int count = 0;
    for (int i = point+1; i < one.size(); i++) {
        ans += ll(one.at(i) - one.at(point) - count - 1);//前にある1の個数も考慮(-count)して、移動回数は数直線の距離-1
        count ++;
    }
    cout << ans << endl;
}
//2乗////////////////////////////////////////////////////////////////////////
const ll max = 1ll<<60;//2^60

//longの計算///////////////////////////////////////////////////////////
long = long + int;//できる(intを暗黙の型変換してくれる)
long = int + int;//int + int でintの範囲外になるとオーバーフローする
long = (long)int + int;//できる(intを暗黙の型変換してくれる)
//double小数点の計算//////////////////////////////////////////////////////////////////////////////////////////
//精度は小数点以下ではなく、「すべて」の桁数
/*
| 項目              | double                         | long double                      |
|------------------|-----------------------------|--------------------------------|
| 精度（有効桁数）  | 約 15～17 桁                 | 約 18～21 桁（環境による）     |
| 最大値           | 約 1.8 × 10³⁰⁸              | 約 1.2 × 10⁴⁹³²（環境依存）   |
| 最小値（正の最小）| 約 2.2 × 10⁻³⁰⁸              | 約 3.3 × 10⁻⁴⁹³²（環境依存）   |
| メモリサイズ     | 8 バイト（64 ビット）        | 12～16 バイト（80～128 ビット）|
| IEEE-754 規格    | 倍精度浮動小数点数（binary64）| 拡張倍精度浮動小数点数（環境依存） |
| リテラル表記     | 1.23 または 1.23e4          | 1.23L または 1.23e4L           |
| 用途             | 通常の浮動小数点計算         | 高精度計算、大きな値の扱い     |
*/

double = double + int;//できる(intを暗黙の型変換してくれる)
double = int + int;//int + int でintの範囲外になるとオーバーフローする
double = (double)int + int;//できる(intを暗黙の型変換してくれる)

//ユーグリッド距離・三平方の定理
double dist(int sx, int sy, int gx, int gy) {
    return sqrt((double)((sx - gx) * (sx - gx) + (sy - gy) * (sy - gy)));
}
//出力
printf("%.10f\n",ans);

//その値までの総和/////////////////////////////////////////////////////////////////////////////////////////////////////
int addNum(int a){
    return (a * (a + 1)) / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a; 
    cin >> a; //10
   int sum = addNum(a);
    cout << sum << endl; //55
}

//尺取り/////////////////////////////////////////////////////////////////////////////////////////////////////
//(AtCoder/cpp/384d.cpp)
//尺取り類似問題(https://atcoder.jp/contests/abc369/tasks/abc369_c)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, s;
    vector<ll> num;
    cin >> n >> s;
    //別のsumをあとで使いたい
    {
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            num.push_back(x);
            sum += x;
        }
        s = s % sum;
    }
    if(s == 0){
        cout << "Yes" << endl; 
        return 0;  
    } 
        
    ll sum = num[0];//一番目のものを入れておく
    //rとlは最初0番目にセット
    ll r = 0;
    ll l = 0;
    bool frag = false;
    //連続部分列の和がちょうどsになるものがあるか尺取り
    //rが二周期分進んだら終わり
    while(r <= num.size()*2 - 1){
        
        //sumの方がsより小さければrを進める(長い範囲を見る)
        if(sum < s){
            r++;
            //r % num.size() -> 周期なので円環問題で考えられる
            sum += num.at(r % num.size());//進めた先のrを足す
        }
        //sumがsより大きければlを進める(rを固定して短い範囲を見る)
        else if(sum > s){
            //lは以下より一周期以内なのでnum.at(l)でよい(rと同じ表現したいからl % num.size()にした)
            sum -= num.at(l % num.size()); //進める前のl(エル)の値を引く
            l++;
            
            //lが一周期の終わりまで行ったら終わり
            if(l == num.size()) break; 

        }
        else{
            frag = true;//sumとsが一致した
            break;
        }
    }
    
    if(frag)cout <<"Yes"<< endl;
    else cout << "No" << endl;
    return 0;
}

//再帰枝刈り全列挙//////////////////////////////////////////////////////////////////////////////////////////
//(AtCoder/saiki/382dac.cpp)
//ラムダ式(解説) <= こっちのやり方が高速
// Time : 198ms
//枝かり全列挙ver(無駄なやつは列挙しない)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> ans;

  //ここで配列を宣言すると前状態の配列を引き継げる
  //末尾を毎回消す必要ない
  //ラムダ式ではauto f = [&](auto f)で引数に自分を呼び出すことで再帰になる
  auto f = [&](auto f, vector<int> a) {
    if (a.size() == n) {
      ans.push_back(a); 
      return;
    }

    int l = 1; //最初の一回用に1を入れる
    if (a.size() > 0) l = a.back()+10;
    a.push_back(l);

    //末尾がm以下の時(10 * (n - a.size()))で最後の答えをしる
    //一番最後のループはn - size() = 0になるので
    //a.back() <= m でmを超えない範囲で1を足し続けてくれる
    while (a.back() + 10 * (n - a.size())<= m) {
      f(f,a);
      a.back()++; //末尾に１を足して次を調べる(新たに配列の要素を増やすわけではない)　-> 例えば　a{1}; a[0] = 1; => a.back()++; a[0] = 2; 
      //足したら上のf(f, a)にループ
      //実質、ここで1足された値をaに追加したと同じになる
      //イメージ↓
      //f(f, 1);
      //1 ++;
      //f(f, 2);
    }
  };

  //空の配列を引数にする
  f(f, vector<int>());

  cout << ans.size() << '\n';
  for (auto a : ans) {
    rep(i,n) cout << a[i] << ' ';
    cout << '\n';
}
return 0;
}

//for文(自作)//////////////////////////////////////////////////////////////
//(AtCoder/cpp/382d2.cpp)
// Time : 466ms
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> ans;

//ここの引数でvector<int> currentを宣言すると前の回までの状態の配列を引き継げる
//つまり、末尾を毎回消す必要ない
void solve(int num, int cnt, vector<int> current) {
    current.push_back(num);
    
    //目標のサイズnになったら
    if(current.size() == n){
        //配列に配列を入れると二次元配列にしてくれる
        ans.push_back(current);
        return;
    }
    
    for (int i = num + 10; i <= m ; i++) {
        //10 * (n - 1)であと何回10足されるか計算する
        //つまり、i + 10 * (n - (current.size() + 1))で最終的な値を計算できる。
        //最終的な値が目標値mを超えたら探索しない(枝刈り)
        if((i + 10 * (n - (current.size() + 1))) > m) return;
        solve(i, cnt + 1, current);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        //10 * (n - 1)であと何回10足されるか計算する
        //つまり、i + 10 * (n - 1)で最終的な値を計算できる。
        //最終的な値が目標値mを超えたら探索しない(枝刈り)
        if(i + 10 * (n - 1) > m) break;
        //ここでからの配列を入れる
        solve(i, 0, {});
    }
    cout << ans.size() << endl;
    for (const auto& vec : ans) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

//入力がNに比例して徐々に減っていく系/////////////////////////////////////////////////////
//三角(AtCoder/cpp/371c.cpp)
for (int i = 0; i < N ; i++) {
    for (int j = 0; j < N; j++) {
         if(j > i){
            cin >> cost[i][j];
            //cost[j][i] = cost[i][j];
         }
    }
 }

//座標回転////////////////////////////////////////////////////////////////////////
//(AtCoder/cpp/375c.cpp)
//回転の関数
//0回転
void zero(int i, int j){
    ans[i][j] = s[i][j];
}
//1回転
void one(int i, int j){
    ans[j][(n - 1 - i)] = s[i][j];
}
//2回転
void two(int i, int j){
    ans[(n - 1 - i)][(n - 1 - j)] = s[i][j];
}
//3回転
void three(int i, int j){
    ans[(n - 1 - j)][i] = s[i][j];
}

//unionfind ユニオンファインド///////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  // 頂点と辺
  int n, m;
  cin >> n >> m;

  int ans = 0;
  //宣言
  dsu uf(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    //abが同じグループならans++
    if (uf.same(a,b)) {
      ans++;
      continue;
    }
    //abくっつける
    uf.merge(a,b);
  }
  //グループすべて見る
  vector<vector<int>> num = uf.groups();
  for (int i = 0; i < num.size(); i++) {
    for (int j = 0; j < num[i].size(); j++) {
      cout << num[i][j] << " ";
    }
    cout << endl;
  }
  cout << ans << endl;
  return 0;
}

//素因数分解・エラストテネスのふるい///////////////////////////////////////////////////////
//(AtCoder/eratosthenes/prime.cpp)
//計算量 : O(n log log n)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Sieve {
  //n = 求めたい最大値
  int n; //メンバ関数
  /*
  f = 各値の最小の素因数(素数ならその数自身)
  prime = 素数と判定したものを追加

  メイン文でこの配列の中身を見れる
    auto primes = sieve.primes;
    auto f = sieve.f;
  */
  vector<int> f, primes;
  //ここが肝
  //メイン文のsieve()の引数でnを指定
  //何も入れずに宣言すると自動で1が入るようにする
  //入力された引数をメンバ関数nに追加．fを初期化
  Sieve(int n=1):n(n), f(n+1) {
    //0,1は素数でないので-1を入れる
    f[0] = f[1] = -1;

    //2からnが素数か判定
    for (ll i = 2; i <= n; ++i) {
      //fに値があったら素数ではないのでコンティニュー
      if (f[i] != 0) continue;

      //上ではじかれなければ素数なので追加
      primes.push_back(i);

      //fにiを追加
      f[i] = i;

      //iが最小の素因数を持つ数字を追加
      for (ll j = i*i; j <= n; j += i) {
        if (f[j] == 0) f[j] = i;
      }
    }
  }

  //引数が素数かどうかをboolで判定
  //xが最小の素数ならtrue
  bool isPrime(int x) { return f[x] == x;}

  //指数表記しない素因数分解を返す関数
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }

  //引数 x に対して素因数分解を行い
  //素因数とその指数（回数）をペアで返す関数
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int cnt = 0; //指数部分カウント
      //素数pで割り切れるだけ割る
      while (x%p == 0) x /= p, ++cnt;
      //pで何回割れたか記録
      //素因数に持たなければ(cnt = 0回)記録しない
      if (cnt != 0) res.emplace_back(p,cnt);
    }
    //万が一記録していない素数だった時用に例外処理
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  //宣言
  //nまでの素因数分解を宣言と同時に行う
  //計算量 : O(n log log n)
  Sieve sieve(n);

  cout << "primes使い方" << endl;
  //primes使い方
  //nまでの素数列挙
  auto primes = sieve.primes;
  for (int i = 0; i < primes.size(); i++) {
    cout << primes[i] << " ";
  }
  cout << endl;
  
  cout << "f 使い方" << endl;
  //f使い方
  //nまでの各数字の最小の素因数を出力
  auto f = sieve.f;
  for (int i = 0; i < f.size(); i++) {
    cout << i << " : " <<f[i] << endl;
  }
 

  cout << "isprime使い方" << endl;
  //isprime使い方(引数は"0"以上)
  //引数が素数かどうかをboolで判定
  for (int i = 0; i < n; i++) {
    if(sieve.isPrime(i)) cout << i << " ";
  }
  cout << endl;;

  cout << "factorList使い方" << endl;
  //factorList(引数は2以上)
  ////指数表記しない素因数分解を返す関数
  for (int i = 2; i <= n; i++) {
    auto factors = sieve.factorList(i);
    cout << i << " = ";
    for (int j = 0; j < factors.size(); j++) {
      if (j > 0) cout << " * ";
      cout << factors[j];
    }
    cout << endl;
  }

  cout << "factor使い方" << endl;
  //factor使い方(引数は2以上)
  //引数 x に対して素因数分解を行い
  //素因数とその指数（回数）をペアで返す関数
  for (int i = 2; i <= n; ++i) {
    auto factors = sieve.factor(i);
    cout << i << " = ";
    for (int j = 0; j < factors.size(); ++j) {
      if (j > 0) cout << " * ";
      cout << factors[j].first;
      if (factors[j].second > 1)
        cout << "^" << factors[j].second;
    }
    cout << endl;
  }

  return 0;
}
