import java.util.*;

public class Main {
  static Scanner scanner;
  static int ans;
  public static void main(String[] args) {
    scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int k = scanner.nextInt();
    String s = scanner.next();
    int[] count = new int[26];
    for (char c : s.toCharArray()) {
      count[c-'a']++;
    }
    ans = 0;
    char[] a = new char[n];
    f(count, a, 0, k, n);
    System.out.println(ans);
  }
  
  private static void f(int[] count, char[] a, int i, int k, int n) {
    if (i >= k) {
      if (palindromeK(a, i-k, i-1)) {
        return;
      }
    }
    if (i == n) {
      ans++;
      return;
    }
    for (int j = 0; j < 26; j++) {
      if (count[j] > 0) {
        count[j]--;
        a[i] = (char) (j + 'a');
        f(count, a, i+1, k, n);
        count[j]++;
      }
    }
  }
  
  private static boolean palindromeK(char[] a, int lo, int hi) {
    int i = lo;
    int j = hi;
    while (i < j && a[i] == a[j]) {
      i++;
      j--;
    }
    return i >= j;
  }
}