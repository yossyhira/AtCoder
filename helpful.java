//便利な関数とその使い方まとめファイル
//ctrl+Fでキーワードの文字検索できる

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

//重複がないようにする。要素がかぶらないようにする。
Set<String> set = new HashSet<String>();

//文字列操作のコマンド集
public class hige {

    public static void main(String[] args) throws Exception {
        
        //String型を宣言
        String str = "appleorangemelonorangemelon";
        
        //文字列にorangeがあるか無いかを出力
        if(str.matches(".*orange.*"))
        {
            System.out.println("orange matched");
        }

        String str1 = "orange";
        
        //文字列検索(位置)
        //str1がある最初のIdxを出力。無ければ-1を出力。
        int result = str.indexOf(str1);//indexOfの”O”👈大文字
        //int result = str.indexOf(str1, 2); strの2要素目以降でstr1があるか判定
        //str1がある最後のIdxを出力。無ければ-1を出力。
        int result1 = str.lastIndexOf(str1);

        if (result != -1) {
            System.out.println(str1 + "が見つかった位置：" + result);
        } else {
            System.out.println(str1 + "は見つかりませんでした");
        }

        if (result1 != -1) {
            System.out.println(str1 + "が見つかった位置：" + result1);
        } else {
            System.out.println(str1 + "は見つかりませんでした");
        }

        //文字列に含まれるすべての”o”のインデックスを返す
        int ans = -1;
        do{
            ans++;
            ans = str.indexOf("o", ans);
            System.out.println(ans);
        }while(ans != -1 );

        //特定の範囲の文字を抜き出し(特定の範囲の文字削除)
        str = str.substring(0,5);//要素0~4の5文字分抜き出し
        /*
        str = str.substring(0,5);
        System.out.println(str);

        出力 
        apple
         */
        str = str.substring(0,str.length() - 5);//末尾の5文字を削除
        
        //文字列の先頭にappleがあるか無いかを調べる
          if (str.startsWith("apple")) {
            System.out.println("前方一致しました");
        } else {
            System.out.println("前方一致しませんでした");
        }
        //文字列の最後にmelonがあるか無いかを調べる
        if (str.endsWith("melon")) {
            System.out.println("後方一致しました");
        } else {
            System.out.println("後方一致しませんでした");
        }
        
        //splitメソッド(区切り系)
        String str2 = "apple orange melon";
        String[] fruits = str2.split(" ");//空白区切りで表示
        for (String fruit : fruits) {
            System.out.println(fruit);
        }
        String str3 = "apple orange melon";
        //str3.trim();//文字列全体の前後の半角スペース削除
        str3 = str3.replaceAll(" ", ""); //文字の間の半角スペースを空文字に変換
        String[] fruits2 = str3.split("");//1文字区切りで表示
        for (String fruit : fruits2) {
            System.out.println(fruit);
        }
        
        // 二文字区切り(n文字区切りは少し下にあるよ)
        int n = 2;
        for (int i = 0; i < fruits2.length; i += 2) {
            if (i + 1 < fruits2.length) {
                System.out.println(fruits2[i] + fruits2[i + 1]);
            } else {
                System.out.println(fruits2[i]);
            }
        }

        //文字連結。appendを使用する
        StringBuilder sb = new StringBuilder("apple");
        System.out.println("sb : " + sb.append("orange"));

        //文字連結。joinを使用する
        String strarray[] = {"apple", "orange", "melon"};
        String str4 = String.join(",", strarray);//各要素を“,”で区切る
        System.out.println(str4);

        //大文字変換
        System.out.println(str.toUpperCase());

        //小文字変換
        System.out.println(str.toLowerCase());

        //頭だけ大文字 substringを使用
        //substring(start Idx,end Idx)
        str = str.substring(0, 1).toUpperCase() + str.substring(1).toLowerCase();
        System.out.println(str);
    }
}

//n文字区切りで表示
public class Main {
    public static void main(String[] args) {
        String str3 = "apple orange melon";
        str3 = str3.replaceAll(" ", ""); // 半角スペース削除
        int splitLength = 2; // 任意の区切り文字数を指定

        String[] fruits2 = splitString(str3, splitLength);

        for (String fruit : fruits2) {
            System.out.println(fruit);
        }
        // n文字目だけ表示
        for (String fruit : fruits2) {
            if(fruit.length() == splitLength){
                fruit = fruit.substring(splitLength - 1);
                System.out.println(fruit);
            }
        }
    }

    public static String[] splitString(String str, int length) {
        int arraySize = (int) Math.ceil((double) str.length() / length);
        String[] result = new String[arraySize];

        for (int i = 0; i < arraySize; i++) {
            int start = i * length;
            int end = Math.min(start + length, str.length());
            result[i] = str.substring(start, end);
        }

        return result;
    }
}

//横書きを縦書きに変換(AtCoderBeginnerContest366のB問題)
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
       int n, m = 0;
       Scanner sc = new Scanner(System.in);
       n = sc.nextInt();
       String[] s = new String[n];

       for(int i = 0; i < n; i++){
           s[i] = sc.next();

           while(i > 0 && s[i].length() < s[i-1].length()) {
            s[i]+=' ';//ここだけB問題から変更
           }

           m=Math.max(m,s[i].length());
       }

       for(int i = 0; i < m; i++){
           for(int j = n - 1; j >= 0; j--){
               if(i < s[j].length()){
               System.out.print(s[j].charAt(i));
               }
           }
           System.out.println();
       }
    }
}
/*
入力
3
apple
orange 
melon

出力
moa
erp
lap
onl
nge
 e
*/

//辞書順にソート(List ver.)
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class hoge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        ArrayList<String> list = new ArrayList<>();
        String T;
        for(int i = 0; i < num; i++){
            T = sc.next();
            list.add(T);
        }

        Collections.sort(list);

        System.out.println("辞書順：");
        for (String str : list) {
            System.out.println(str);
        }
    }
}

/*
入力
4
apple
applo
appla
applb

出力
辞書順：
appla
applb
apple
applo
 */

//辞書順にソート(Array ver.)
import java.util.ArrayList;
import java.util.Collections;
import java.util.*;

public class hoge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        String[] foo = new String[num];
        for(int i = 0; i < num; i++){
            foo[i] = sc.next();
        }
         
        Arrays.sort(foo);
        System.out.println("辞書順：");
        for(int i = 0; i < num; i++){
            System.out.println(foo[i]);
        }
    }
}
/*
入力
4
apple
applo
appla
applb

出力
辞書順：
appla
applb
apple
applo
 */
//文字を逆順に並び替えて表示
import java.util.Scanner;

public class hoge {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 単語数を入力
        int wordCount = scanner.nextInt();

        // 単語を格納する配列
        String[] words = new String[wordCount];

        // 単語を入力
        for (int i = 0; i < wordCount; i++) {
            words[i] = scanner.next();
        }

        // 単語を逆順にして出力
        for (String word : words) {
            System.out.println(reverse(word));
        }

        scanner.close();
    }
    //逆順にする関数
    public static String reverse(String word){
        String reverseWord;
        reverseWord = new StringBuilder(word).reverse().toString();//StringBuilderのメソッドにあるreverseを使い文字列を逆順にして
                                                                   //toStringでString型に戻す
        return reverseWord;
    }
}
/*
入力
3
hoge
huga
haga

出力
egoh
aguh
agah
 */

//配列を右にシフト
import java.util.*;

public class hoge {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5};
        int n = array.length;
        int[] shiftedArray = new int[n];

        // 配列の要素を右にシフト
        //System.arraycopy(コピー元, コピー元開始位置, コピー先, コピー先開始位置, いくつコピーするか);
        System.arraycopy(array, 0, shiftedArray, 1, n - 1);
        shiftedArray[0] = array[n - 1];//最後の要素を最初にシフト

        // 結果を表示
        for (int i : shiftedArray) {
            System.out.print(i + " ");
        }
        System.out.print('\n');
    }
}
/*
1 2 3 4 5
5 1 2 3 4
 */

//list使い方
import java.util.*;

public class hoge {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
 
        list.add("a");
        list.add("b");
        list.add("c");

        // forEachメソッド　listの全ての要素を出力
        list.forEach(System.out::println);//printlnで各文字ごとに改行, printでつなげて出力
                                          // ::はメソッド参照
        //ラムダ(->)を使いbを飛ばして出力                                  
        list.forEach(s -> { // forEachメソッド
            if (s.equals("b")){ 
                return; // continueだとエラーが出るので代わりにreturnを使う(bを飛ばす)
            }
            System.out.println(s);
        });
        
        //addAllメソッド　listの末尾に別のリストを追加
        List<Integer> list1 = new ArrayList<>();
 
        list1.add(1);
        list1.add(2);
        list1.add(3);
        list1.add(4);
         
        List<Integer> list2 = new ArrayList<>();
         
        list2.add(5);
        list2.add(6);
        list2.add(7);
        list2.add(8);
         
        list1.addAll(list2); //list1にlist2を追加
        
        System.out.println(list1); //[1, 2, 3, 4, 5, 6, 7, 8]
        list1.forEach(s -> System.out.print(s + " "));//[]を無くして出力　1 2 3 4 5 6 7 8
        System.out.println(); 

        //getメソッド　要素0に何があるのか調べる.
        //配列のhoge[0]と同じ意味
        System.out.println(list1.get(0)); // 1

        //indexOfメソッド　1がどの要素にあるのか調べる
        System.out.println(list1.indexOf(1)); // 1

        //setメソッド　listの値を書き換え
        list1.set(0, 3); //list1の要素0を３に書き換え
        
        System.out.println(list1); //[3, 2, 3, 4, 5, 6, 7, 8]

        
        //subListメソッド　部分的に配列を抜き出し
        List<Integer> sbList = list1.subList(1, 3); //要素1から3未満まで(1~2)を抜き出し
        System.out.println(sbList);//[2, 3]

        //subListを使い指定範囲削除
        list1.subList(1, 3).clear();
        System.out.println(list1); //[2, 3]を削除して[3, 4, 5, 6, 7, 8]

        //removeメソッド　指定した要素を削除
        list1.remove(0); 
        System.out.println(list1);//[4, 5, 6, 7, 8]

        //addメソッド　先頭に追加
        //list1.add(追加したい場所, 追加するもの);　追加したい場所を指定しないと末尾に追加
        list1.add(0, 3);
        System.out.println(list1);//[3, 4, 5, 6, 7, 8]

        // 配列からListへの変換
        String[] array1 = {"s", "a", "m", "u", "r", "a", "i"};
        List<String> list3 = Arrays.asList(array1);
         
        System.out.println(list3);
        
        // Listから配列への変換
        List<String> list4 = new ArrayList<>(Arrays.asList("s", "a", "m", "u", "r", "a", "i"));
        String[] array2 = list4.toArray(new String[list4.size()]);
        
        for(String s: array2) {
            System.out.println(s);
        }
    }
}

///AtCoderBeginnerContest370/java/c.javaのコード
import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        sc.close();

        ArrayList<String> hoge = new ArrayList<>();//List宣言
        ArrayList<String> ans = new ArrayList<>();

        while(!S.equals(T)){
            char[] s = S.toCharArray();//文字列を一文字ずつ分解して配列に保存
            char[] t = T.toCharArray();
            for(int i = 0; i < S.length(); i++){
                if(s[i] != t[i]){
                    char x = s[i];
                    s[i] = t[i];
                    String A = new String(s);//配列を文字列に変換
                    hoge.add(A);
                    s[i] = x;
                }
            }
            Collections.sort(hoge);//List辞書順にソート
            S = hoge.get(0);
            ans.add(hoge.get(0));
            hoge.clear();//Listの初期化
        }

        System.out.println(ans.size());

        for (int i = 0; i < ans.size(); i++) {
            System.out.println(ans.get(i));
        }
    }
}

//部分文字列がその文字列に何個含まれるか
int Count = 0;
String str = "hogeABChugahugaABC"
int index = str.indexOf("ABC");
//含まなければ　-1　を返す
while (index != -1) {
    Count++;
    index = Str.indexOf("ABC", index + 1);
}

//文字操作で先頭から最後まで検索したいときに
//先頭以下や最後以上の数字にならないようにする
//先頭なら0と検索したいIdx最「大」値, 最後なら文字.length()とIdxの最「小」値
//下記は AtCoderBeginnerContest372/java/c2.java 参照
int start = Math.max(0, Idx - 2);
int end = Math.min(n, Idx + 2);

//文字列。配列版substring。char配列から指定した範囲の文字で文字列作成
char[] s = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
String str = new String(s, 2, 3);//2, 3, 4で lloが出力
String str = new String(s);//これはただchar配列を文字列にするだけ。出力: Hello World

//文字列を配列に変換。一文字ずつ分割
char[] s = Str.toCharArray();



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