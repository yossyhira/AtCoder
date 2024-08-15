//便利な関数とその使い方まとめファイル

//素数判定関数
public static boolean isPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = Math.sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)if(num % i == 0)return false;
    return true;
}
/* import java.util.Scanner;
   numを入力
        if (isPrime(num)) {
            System.out.println(num + " は素数");
        } else {
            System.out.println(num + " は素数ではない");
        }
    }
*/

//桁和
public static int digsum(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
/* 
int sum = digsum(num);
System.out.println("桁和: " + sum);
*/

//奇数偶数判定
public static boolean evenNum(int num) {
    if((num & 1)==0)return true;//偶数
    return false;//奇数
}
/*
if(evenNum(num)){
    System.out.println("偶数");
}else{
        System.out.println("奇数");
}
*/

//最大公約数
public static int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
/*
int ans = gcd(num, num1);
System.out.println(ans);
*/

//最小公倍数(最大公約数を使って求める)
public static int gcd(int a, int b) {
    return (b != 0) ? gcd(b, a % b) : a;
}
public static int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
/*
int ans = lcm(num, num1);
System.out.println(ans);
*/

//階乗(10^9+7で割った余りを表示) nとansがlong型なので注意
public static long factorial(long n){
    long mod = (long)Math.pow(10,9)+7;
    long ans = 1;
    for(int i = 1; i <= n; i++)ans =(ans*i) % mod;//オーバーフローを防ぐため毎回余りを求める
    return ans;
}
/*
long ans = factorial(num);
System.out.println(ans);
*/

//X^nを計算(10^9+7で割った余りを表示) nとansがlong型なので注意
public static long modPow(long x, long n) {
    long mod = (long)Math.pow(10,9)+7;
    long res = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
/*
long ans = modPow(x, n);
System.out.println(ans);
*/

//特定の文字の数をカウント
public static int stringCount(String s, char c) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == c) {
            count++;
        }
    }
    return count;
}
/*
//1の個数をカウント
String s = scanner.nextLine();
char c = '1';
int ans = stringCount(s, c);
System.out.println(ans);
*/

//降順並び替え
import java.util.Arrays;
import java.util.Comparator;
Integer[] num;
Arrays.sort(num, Comparator.reverseOrder());

//文字コードを使用して文字を表示
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char c = sc.next().charAt(0);
		System.out.println((char)(c+1));//次の文字を表示。(char)(文字コード)で文字を表示できる
        System.out.println((int)(c));//文字コードを表示
    }
}
/*
入力
a
出力
b 
97
*/

//特定の文字が何文字目にあるかカウント
//sの文字列のn文字目以降で文字cが何番目にあるかチャック
public static int stringCount(String s, int n, char c) {
    int ans = -1;//無ければ-1を返す
    for (int i = n; i < s.length(); i++) {
        if (s.charAt(i) == c) {
            ans = i;
            break;
        }
    }
    return ans;
 }
 /*
 import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        sc.close();
        int n = 0, ans = 0;
        for(int i = 0; i < t.length(); i++ ){
        n = ans;
        ans = stringCount(s, n, t.charAt(i));
        System.out.println(ans);
        ans ++; 
        }
    }

   public static int stringCount(String s, int n, char c) {
    int ans = -1;
    for (int i = n; i < s.length(); i++) {
        if (s.charAt(i) == c) {
            ans = i;
            break;
        }
    }
    return ans;
 }
}

実行結果１
入力
ddd
ddd
出力
0
1
2

実行結果２
入力
atcoder
toe
出力
1
3
5
*/