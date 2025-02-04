#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> p(N);//3!の全探索
    for (int i = 0; i < N; i++) p[i] = i;

    string text;
    cin >> text;
    int ans = 0; 
    set<string> set;
    do {
        string NewText = "";  
        for (int i = 0; i < N; i++) {
            NewText.push_back(text.at(p[i]));
        }
        bool ok = true;
        if (!(set.count(NewText))) {
            set.insert(NewText);
            for (int i = 0; i < (N - K + 1); i++) {
                bool flag = true;
                for (int j = 0; j < K; j++) {
                    if(NewText[i + j] != NewText[i + K - 1 - j]) flag = false;
                }
                if(flag)ok = false;
            }
            if(ok)ans ++;
        }
        
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}