#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  const int INF = 1001001001;
  vector<vector<int>> dp(n+1, vector<int>(3,-INF));
  rep(i,3) dp[0][i] = 0;

  for (int i = 1; i <= n; i++) {
    int x = 0;
    if (s[i-1] == 'R') x = 0;
    if (s[i-1] == 'P') x = 1;
    if (s[i-1] == 'S') x = 2;

    rep(j,3) {
      int val = 0;
      if (j == (x+1)%3) val = 1;
      if (j == (x+2)%3) continue;
      rep(pj,3) {
        if (j == pj) continue;
        dp[i][j] = max(dp[i][j], dp[i-1][pj]+val);
      }
    }
  }

  int ans = max({dp[n][0],dp[n][1],dp[n][2]});
  cout << ans << endl;
  return 0;
}


/*#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans = 0;
string anstext = "";

void judge(char c, int i) {  // void に変更（return しないから）
    if (c == 'R') {
        if (i > 0 && anstext.at(i - 1) == 'P') {
            anstext += "R";
        } else {
            anstext += "P";
            ans++;
        }
    } 
    else if (c == 'S') {
        if (i > 0 && anstext.at(i - 1) == 'G') {
            anstext += "S";
        } else {
            anstext += "G";
            ans++;
        }
    } 
    else if (c == 'P') {
        if (i > 0 && anstext.at(i - 1) == 'S') {
            anstext += "P";
        } else {
            anstext += "S";
            ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string text;
    cin >> text;

    // 1文字目の処理
    char c = text.at(0);
    if (c == 'R') anstext += "P";
    else if (c == 'S') anstext += "G";
    else if (c == 'P') anstext += "S";
    ans++;

    // 2文字目以降の処理
    for (int i = 1; i < text.size(); i++) {  // i = 1 からスタート（範囲外アクセス防止）
        judge(text.at(i), i);
    }
    //cout << anstext << endl;
    cout << ans << endl;
}*/
