#include <iostream>
#include <cmath>
using namespace std;

int Q;
long double T, L, X, Y, E;
long double PI = 3.14159265358979;

long double query(long double I) {
	//初期中心座標 ＝ (0, 0, (L/2))
	//でも簡単にするために(0, 0, 0)にして計算．最後にz座標だけ＋(L/2)足す
	//yを縦軸，ｚを横軸としてとらえると一番数学単位円のときと近い状態で考えられる
	//座標は半径×三角関数(sin or cos)で求められる
	//右回りなのでマイナスかける．y座標には詳しく↓
	//通常(数学のとき)は左周りで考えているけど，今回は右回りなので -θ 回ってると考えて最後にマイナスかける
	//右回りでも本来はcosはプラスのまま
	//でも今回はz座標が右から左に向けてプラスになってる「←」ためcosもマイナスつけてる(数学では左から右がプラス[→])
	/*         y
			   ^
			   |
	           |
	Z <-------------------
               |
			   |
			   |
	*/
	long double cx = 0;
	long double cy = -(L / 2.0) * sin(I / T * 2.0 * PI);
	long double cz = - (L / 2.0) * cos(I / T * 2.0 * PI) + (L / 2.0);
	//ここで観覧車から銅像までの直線距離求める（縦と横は分かっていて，斜辺が直線距離）
	// 観覧車と銅像のx座標の距離はずっと固定，観覧車の移動によってyが変わる
	long double d1 = sqrt(X * X + (cy - Y) * (cy - Y));
	//見上げる高さは観覧車の高さ
	long double d2 = cz;
	//arctanに入れると角度が出る
	long double rad = atan2(d2, d1);
	//ラジアンから弧度法に直す(180/piかけると直る)
	return rad * 180.0L / PI;
}

int main() {
	cin >> T;
	cin >> L >> X >> Y;
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> E;
		printf("%.12Lf\n", query(E));
	}
	return 0;
}