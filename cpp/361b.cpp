#include<iostream>
using namespace std;

int main()
{
  int a, b, c, d, e, f, g, h, i, j, k, l;
  cin >> a >> b >> c >> d >> e >> f;
  cin >> g >> h >> i >> j >> k >> l;
  
  string ans = "No";
  if (((a <= g && g < d) || (a < j && j <= d)) || ((g <= a && a < j) || (g < d && d <= j)))
  {
    if (((b <= h && h < e) || (b < k && k <= e)) || ((h <= b && b < k) || (h < e && e <= k)))
    {
      if (((c <= i && i < f) || (c < l && l <= f)) || ((i <= c && c < l) || (i < f && f <= l)))
      {
        ans = "Yes";
      }
    }
  }
  cout << ans << endl;
  return 0;
}