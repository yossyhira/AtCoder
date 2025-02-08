#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<unordered_set<int>> d0(n);
    vector<int> dsize(n);
    vector<vector<int>> count(n, vector<int>(1001010, 0));

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        dsize[i] = k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            d0[i].insert(a);
            count[i][a]++;
        }
    }

    vector<vector<int>> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = vector<int>(d0[i].begin(), d0[i].end()); // 変換
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < d[i].size(); j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/
    double ans = -1;

    cout << fixed << setprecision(10);  // 🔥 小数点以下8桁を固定
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int oneSize = dsize[i];
            int twoSize = dsize[j];
            double subans = 0;
            for (int k = 0; k < d[i].size(); k++) {
                int m = d[i][k];
                if(count[j][m] == 0) continue;
                //cout << m << endl;
                subans += (double(count[i][m]) / double(oneSize)) * 
                          (double(count[j][m]) / double(twoSize));
                //cout << subans << endl;
            }
            ans = max(ans, subans);
        }
    }

    cout <<  ans << endl;  
}
