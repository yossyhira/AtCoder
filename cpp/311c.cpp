#include <atcoder/scc>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	atcoder::scc_graph graph(++n);
	vector<int> a(n);
	for (int i = 1; i < n; ++i) {
        int b;
		cin >> a[i] >> b;
		graph.add_edge(a[i], b);
		graph.add_edge(b, a[i]);
	}
	auto scc = graph.scc();
	for (auto &s : scc) {
		int now = s[0], len = s.size();
		//if (len == 1) continue;
		cout << len << '\n';
		/*for (int i = 0; i < len; ++i) {
			cout << now << ' ';
			now = a[now];
		}*/
        for (int i = 0; i < len; i++) {
            cout << s[i] << ' ';
        }
        cout << endl;
	}
    return 0;
}
