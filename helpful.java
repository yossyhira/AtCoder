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
//
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
    long mod = (long)Math.pow(10,9)+7;//Math.pow()はdouble型
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

        //一文字だけ取り出す
        System.out.println(str3.charAt(0));
        //str3 = "apple orange melon";
        //出力：a

        //後ろに文字を追加
        String str = "Hello ";
        System.out.println(str.concat("Java!"));  // Hello Java!
         //元のやつには追加されてない(Java特有のVMという仮想マシンのせい)
        System.out.println(str);  // Hello 
         //一度新しい変数に入れる必要あり
        String strConcat = str.concat("Java!");
        System.out.println(strConcat);  // Hello Java!

        //strが等しいか判別
        String str = "Hello Java!";
         //大文字小文字の区別なし
        System.out.println(str.equalsIgnoreCase("HELLO JAVA!"));  // true
         //大文字小文字の区別あり
        System.out.println(str.equals("HELLO JAVA!")); // false

        //指定した文字を置換(一文字だけの置換なら下の方にあるStringBuilderの.setCharAtを使うとよい)
        String str = "Hello Java!";
        //aをoに置換 replace(char, char);
        System.out.println(str.replace('a', 'o'));  // Hello Jovo!

        //両端の半角空白を全削除
        String str = " Hello Java! ";
        System.out.println(str.trim());           // Hello Java!
        System.out.println(str.trim().length());  // 11
         //後ろに文字列を追加のときと同様に元の文字列に変化なし
        System.out.println(str);           //  Hello Java! 
        System.out.println(str.length());  // 13
         //全ての半角削除 replaceAll(string, string);
         //エラー：System.out.println(str.replace(' ', ''));　charは空文字('')対応してない
        System.out.println(str.replaceAll(" ", ""));// HelloJava!

        //指定した回数文字列を生成(AtCoder/AtCoderBeginnerContest380/java/c.java)
        String text = "1";
        String one = text.repeat(5);
        System.out.println(one);//11111
    }
}

//StringBuilderの使い方
//文字列の挿入や削除などに便利
//同じ変数で使いまわせる
{
// 1. フツーに宣言、初期容量は16文字
StringBuilder sb1 = new StringBuilder();

// 2. 初期容量 capacity 文字で宣言
// 80.0 など実数を入れるとコンパイルエラーになります、指定できる数字はintのみ
StringBuilder sb2 = new StringBuilder(int capacity);

// 3. strで初期化する
StringBuilder sb3 = new StringBuilder(String str);

// 4. 宣言して即座に出力
System.out.println(new StringBuilder("Hello Java!"));

//文字列の指定した位置に指定した文字列を挿入
StringBuilder sb = new StringBuilder("Hello Java!");
//System.out.println(sb.insert(10, "Script"));  // Hello JavaScript!
String word = "Script";
System.out.println(sb.insert(10, word)); // Hello JavaScript!
System.out.println(sb);  // Hello JavaScript!

//指定した区間の文字削除
StringBuilder sb = new StringBuilder("Hello Java");
System.out.println(sb.delete(2, 4));  // Heo Java!
System.out.println(sb);  // Heo Java!
// length() と合わせて使えば、全部の文字を削除できます
System.out.println(sb.delete(0, sb.length()));  // (何も出力されない)

//文字列を逆順にする 回文判定に使えそう
StringBuilder sb = new StringBuilder("Hello Java!");
System.out.println(sb.reverse());  // !avaJ olleH
System.out.println(sb);  // !avaJ olleH

//文字列の指定した場所の文字(一文字)を置換(挿入ではなく置換)
StringBuilder sb = new StringBuilder("Hello Java!");
sb.setCharAt(6, 'j');//jを小文字にする
System.out.println(sb);  // Hello java!

/*
文字列の指定した場所の“文字列”を置換
replace(start, end, String)で
startは初めの文字の位置,
endは置換したい最後の文字の位置 + 1に注意
また、Javaは4文字で置換させたい文字列pythonは6文字と長さが違っても問題ない
*/
StringBuilder sb = new StringBuilder("Hello Java!");
System.out.println(sb.replace(6, 10, "python"));  // Hello python!
System.out.println(sb);  // Hello python!

//StringBuilderをString型に変更
StringBuilder sb = new StringBuilder("Hello Java!");
System.out.println( sb.toString());  // Hello Java!

//文字列の部分抜き出し
//Stringのsubstring()と同じ
StringBuilder sb = new StringBuilder("Hello Java!");
System.out.println( sb.substring(0,5));  // Hello
}

//回文判定
import java.util.*;

public class hoge {
    public static boolean rotateString(String base) {
        StringBuilder sb = new StringBuilder(base);
        String reverse = sb.reverse().toString();
        if(base.equals(reverse)){
            return true;
        }else{
            return false;
        }
}
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       String text = sc.next();

       if(rotateString(text)){
        System.out.println("回文です");
       }else{
        System.out.println("回文ではないです");
       }

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

//配列のコピー配列コピー(AtCoder/AtCoderBeginnerContest383/java/b.java)
 char[][] n = new char[H][W];
for (int i = 0; i < H; i++) {
    String hoge = sc.next();
    n[i]= hoge.toCharArray();
}
char[][] array = new char[H][W]; // コピー先の配列を作成
for (int j = 0; j < H; j++) {
    array[j] = n[j].clone(); // 1次元配列をコピー
}

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
        //list宣言
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

        //listの内容を頭からすべて出力
        for(int n : list1){
            System.out.print(n + " ");// 1 2 3 4 
        }
        System.out.println();

        
        // Listから配列への変換
        List<String> list4 = new ArrayList<>(Arrays.asList("s", "a", "m", "u", "r", "a", "i"));
        String[] array2 = list4.toArray(new String[list4.size()]);
        
        for(String s: array2) {
            System.out.println(s);
        }
    }
}

//listの内容を末尾から出力(AtCoder/AtCoderBeginnerContest289/java/b.java)
List<Integer> waitNum = new ArrayList<>();

for (int i = 1; i <= n; i++) {
    if(h.add(i)){
        System.out.print(i + " ");
        //現在の総要素数を入れる
        int roop = waitNum.size();
        for (int j = 0; j < roop ; j++) {
            //末尾のインデックスを取得
            int size = waitNum.size() - 1;
            //末尾の値を表示
            System.out.print(waitNum.get(size) + " ");
            //最後のインデックスの要素を削除
            waitNum.remove(size);
        }
    }else{
        waitNum.add(i);
    }
}

// listの二次元配列？みたいなやつ(AtCoder/AtCoderBeginnerContest289/java/c.java)
import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // NとMを読み込み
        int N = sc.nextInt();
        int M = sc.nextInt();

        // 二次元リストを初期化
        List<List<Integer>> groups = new ArrayList<>();

        // M 個のグループを読み込む
        for (int i = 0; i < M; i++) {
            int C = sc.nextInt(); // このグループの要素数

            // グループの要素を格納するリストを作成
            List<Integer> group = new ArrayList<>();
            for (int j = 0; j < C; j++) {
                group.add(sc.nextInt()); // 各要素を追加
            }

            // グループを二次元リストに追加
            groups.add(group);
        }
        System.out.println("=========================確認===========================");
       for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups.get(i).size(); j++) {
            System.out.print(groups.get(i).get(j)+" ");
        }
        System.out.println();
       }


        sc.close();
    }
}
/*
入力
3 3
2　
1 2　<= これを入れる
2
1 3　<= これを入れる
1
2　<= これを入れる

出力
1 2 
1 3 
2 
*/

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

//文字を配列に変換。一文字ずつ分割.文字列を配列
char[] s = Str.toCharArray();

//文字列の中から一文字だけ表示
String text = sc.next();
System.out.println(text.charAt(0));

//bit全探索ビット全探索（AtCoder/AtCoderBeginnerContest374/java/c.java）
//他の類似問題（AtCoder/AtCoderBeginnerContest289/java/c.java）
//2^Idx N = Idx
for (int i = 0; i < (1 << Idx); i++) {
    for (int j = 0; j < Idx; j++) {
        if((i & (1 << j)) != 0){
        }
    }
}

for (int i = 0; i < (1 << Idx); i++) {
    //long A = 0;
    //long B = 0; 
    for (int j = 0; j < Idx; j++) {
        //j番目の数字や物を選ぶ
        if((i & (1 << j)) != 0){
            //一つの組み合わせの中で選ぶ「一つ」を選んだ後の処理を記述
            //A += num[j]; //1があったらAチーム
        }else{
           // B += num[j];//0ならBチーム
        }
    }
    //一つの組み合わせを「全て」選びきった後の処理
    //long maxNum = Math.max(A, B);
    //ans = Math.min(ans, maxNum);  
}

//順列全探索　階乗の組み合わせ探索
import java.util.Arrays;

public class hoge {
    private static void permutation(int[] seed) {
        int[] perm = new int[seed.length];
        boolean[] used = new boolean[seed.length];
        buildPerm(seed, perm, used, 0);
    }

    private static void buildPerm(int[] seed, int[] perm, boolean[] used, int index) {
        if (index == seed.length) {
            procPerm(perm);
            return;
        }

        for (int i = 0; i < seed.length; i++) {
            if (used[i])
                continue;
            perm[index] = seed[i];
            used[i] = true;
            buildPerm(seed, perm, used, index + 1);
            used[i] = false;
        }
    }

    private static void procPerm(int[] perm) {
        System.out.println(perm[0]);//ここに追加
    }

    public static void main(String[] args) throws Exception {
        permutation(new int[] { 1, 2, 3 });//3!計算
    }
}

//二分探索(AtCoder/AtCoderBeginnerContest376/java/c.java)
//下に類似問題あり(AtCoder/AtCoderBeginnerContest382/java/c.java)
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n - 1];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            b[i] = sc.nextInt();
        }

        Arrays.sort(a);
        Arrays.sort(b);

        final int INF = 1001001001;
        int ac = INF, wa = 0;

        // ここが二分探索
        while (ac - wa > 1) {
            int wj = (wa + ac) / 2;
            if (judge(wj, a, b, n)) {
                ac = wj;
            } else {
                wa = wj;
            }
        }
        //
        
        if (ac == INF) {
            System.out.println(-1);
        } else {
            System.out.println(ac);
        }

        sc.close();
    }

    // Moved the judge method outside the main method
    public static boolean judge(int x, int[] a, int[] b, int n) {
        List<Integer> nb = new ArrayList<>();
        for (int value : b) {
            nb.add(value);
        }
        nb.add(x);
        Collections.sort(nb);

        for (int i = 0; i < n; i++) {
            if (a[i] > nb.get(i)) {
                return false;
            }
        }
        return true;
    }
}
//二分探索の問題２(AtCoder/AtCoderBeginnerContest382/java/c.java)
    public static void main(String[] args)throws IOException {
        int n = sc.nextInt();
        int m  = sc.nextInt();
        int[] a = new int[n];
        int sushi = 0;
        a[0] = sc.nextInt();
        for (int i = 1; i < n; i++) {
            a[i] = sc.nextInt();
            a[i] = Math.min(a[i-1], a[i]);
        }
        for (int i = 0; i < m; i++) {
            int ac = n-1, wa = 0; 
            sushi = sc.nextInt();
            if(a[n-1] > sushi){
                System.out.println(-1);
                continue;
            }
            else if(a[0] <= sushi){
                System.out.println(1);
                continue;
            }
        //(ac - wa) > 1の間ループ。for分みたいにＯＯまでじゃないことに注意。
            while((ac - wa) > 1){
                int judgeNum = ((ac - wa) / 2) + wa;
                //int judgeNum = ((ac + wa) / 2);　上を式変形するとこれになる。上と下どっちも結果は同じ
                
                if(judge(a,judgeNum, sushi)){
                    ac = judgeNum;
                }else{
                    wa = judgeNum;
                }
            }

            System.out.println(ac+1);
            
        }
        
       
    }
    // Moved the judge method outside the main method
    //探索する配列(a)、判定するIdx(judgeNum)、判定基準の数値(sushi)を引数にする
    public static boolean judge(int[] a, int judgeNum, int sushi) {
        //寿司がa番目の人の美味度以上ならtrue
        if(a[judgeNum] <= sushi){
            return true;
        }else{
            return false;
        }
    }


//輪・円問題(atcoder/AtCoderBeginnerContest376/java/b2.java)
//基本、場合分けして数直線で考えるとよい。配列はやめた方がいい。
//循環するときは割った余りで場所を求められる
//ただ進むだけを考えるなら↓(AtCoder/cpp/146b.cpp)
//now:今の場所 j:進む距離　N:円の大きさ(大きさなので最大値＋１)に注意！！
(now + j) % N//時計周り
(now - j + N) % N//反時計

//重複がないようにする。要素がかぶらないようにする。
Set<String> set = new HashSet<String>();

//配列の最大オーバーするときの既にあるかチェックするときは文字列として考える。(atcoder/AtCoderBeginnerContest377/java/c2.java)
Set<String> used = new HashSet<>();
//使用済みの座標を追加(下のCPPのJAVAの方がいいかも)
//もし[g][r]があればfalseなければ、trueを出して[g][r]を追加
if(used.add(g + "," + r))

//上よりもこっちの方がいいかも！！　cppのset pareをjavaで実装
import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

class Pair {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return first == pair.first && second == pair.second;
    }

    @Override
    public int hashCode() {
        return Objects.hash(first, second);
    }
}

public class Main { //<=Mainをファイル名に変えてね
    public static void main(String[] args) {
        Set<Pair> badCell = new HashSet<>();
        badCell.add(new Pair(1, 2));//追加
        badCell.add(new Pair(3, 4));

        System.out.println(badCell.contains(new Pair(1, 2))); // new Pair(1, 2)があればtrue
    }
}
//出力
true

//グリッド入力（＃#とか・･のやつ）(atcoder/AtCoderBeginnerContest377/java/b.java)
Scanner sc = new Scanner(System.in);
char[][] n = new char[8][8];//8*8のグリッド
for (int i = 0; i < 8; i++) {
    hoge = sc.next();
    n[i]= hoge.toCharArray();
}
sc.close();

//map
//二つの物の関係を記録したいときに使う
//keyのときどんな値なのか

//宣言
//Map<key, 値>
Map<Integer, Integer> indexMap = new HashMap<>();//int,intの組み合わせの場合

//key,値追加
//既にkeyがある場合は値を上書き保存
indexMap.put(key, 値);

//keyがmapの中に既にあるかないか
//返り値 true/false
indexMap.containsKey(num)

//keyに対応している値を取得
indexMap.get(key)

//宣言と同時に値を追加したい
Map<String, String> map = new HashMap<String, String>() {
    {
        put("samurai", "侍");
        put("engineer", "エンジニア");
    }
};

//中身を表示
for (Map.Entry<String, String> entry : map.entrySet()) {
    System.out.println(entry.getKey() + " : " + entry.getValue());
}
//出力
samurai : 侍
engineer : エンジニア

//mapをlistに変換
// Mapの宣言
Map<String, String> map = new HashMap<>();

// MAPにデータを格納
map.put("key1", "apple");
map.put("key2", "orange");
map.put("key3", "melon");

// Listを宣言し、valuesメソッドを使用してMapの"値"を取得する
List<String> list = new ArrayList<>(map.values());
//全ての"key"をlistに変換
//List<String> list = new ArrayList<>(map.keySet());

// 要素番号を指定してListの値を取得する
System.out.println(list.get(0));
//出力
apple

//昇順ソート
//treemapは追加されたら自動でソートしてくれる
//今までのhushmapは追加された順に登録
//TreeMapオブジェクトの生成
Map<String, String> treeMap = new TreeMap<>();

//TreeMapオブジェクトにデータを追加 
treeMap.put("B","Brazil");
treeMap.put("A","America");
treeMap.put("C","China");
treeMap.put("E","England");
treeMap.put("D","Denmark");

System.out.println("TreeMapの場合");

for (String nKey : treeMap.keySet()){
    System.out.println(treeMap.get(nKey));
}

//keyの昇順ソート
// Mapの宣言
Map<Integer, String> mMap = new HashMap<Integer, String>();

// Mapにデータを格納
mMap.put( 1, "apple");
mMap.put( 2, "orange");
mMap.put( 4, "pineapple");
mMap.put( 5, "strawberry");
mMap.put( 3, "melon");

// キーでソートする
Object[] mapkey = mMap.keySet().toArray();
Arrays.sort(mapkey);

for (Integer nKey : mMap.keySet())
{
    System.out.println(mMap.get(nKey));
}
//出力
apple
orange
melon
pineapple
strawberry

//key昇順・降順(comparator使用ver.)
Map<String, Integer> mMap = new HashMap<String, Integer>();
        
// 1. Mapにデータを格納
mMap.put( "apple", 1);
mMap.put( "orange", 2);
mMap.put( "pineapple", 4);
mMap.put( "strawberry", 5);
mMap.put( "melon", 3);

// 2.Map.Entryのリストを作成する
List<Entry<String, Integer>> list_entries = new ArrayList<Entry<String, Integer>>(mMap.entrySet());

//ここから昇順の処理
// 3.比較関数Comparatorを使用してMap.Entryの値を比較する(昇順)
Collections.sort(list_entries, new Comparator<Entry<String, Integer>>() {
    public int compare(Entry<String, Integer> obj1, Entry<String, Integer> obj2) {
        // 4. 昇順
        return obj1.getValue().compareTo(obj2.getValue());
    }
});

System.out.println("昇順でのソート");
// 5. ループで要素順に値を取得する
for(Entry<String, Integer> entry : list_entries) {
    System.out.println(entry.getKey() + " : " + entry.getValue());
}


//ここから降順の処理
// 6. 比較関数Comparatorを使用してMap.Entryの値を比較する（降順）
Collections.sort(list_entries, new Comparator<Entry<String, Integer>>() {
    //compareを使用して値を比較する
    public int compare(Entry<String, Integer> obj1, Entry<String, Integer> obj2)
    {
        //降順
        return obj2.getValue().compareTo(obj1.getValue());
    }
});

System.out.println("降順でのソート");
// 7. ループで要素順に値を取得する
for(Entry<String, Integer> entry : list_entries) {
    System.out.println(entry.getKey() + " : " + entry.getValue());
}
//出力
昇順でのソート
apple : 1
orange : 2
melon : 3
pineapple : 4
strawberry : 5
降順でのソート
strawberry : 5
pineapple : 4
melon : 3
orange : 2
apple : 1

 


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

 //型の最大値・最小値指定方法
 int = Integer.MIN_VALUE //最小
 int = Integer.MAX_VALUE //最大
 long = Long.MIN_VALUE
 long = Long.MAX_VALUE


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