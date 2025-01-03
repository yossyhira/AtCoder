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
   cout << "文字列追加 : " << s1 << endl; //Testtestabcd

   //文字列削除
   s1.erase(11); //dを削除
   cout << "文字列削除 : " << s1 << endl; //Testtestabc
   s1.erase(8,3); //abc 削除 8文字目から3文字分削除
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
}
