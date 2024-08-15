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
        
        //str1がある最初のIdxを出力。無ければ-1を出力。
        int result = str.indexOf(str1);
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
        
        //splitメソッド
        String str2 = "apple orange melon";
        String[] fruits = str2.split(" ");//空白区切りで表示
        for (String fruit : fruits) {
            System.out.println(fruit);
        }
        String str3 = "apple orange melon";
        str3.trim();//半角スペース削除
        String[] fruits2 = str.split("");//1文字区切りで表示
        for (String fruit : fruits2) {
            System.out.println(fruit);
        }

        //文字連結。appendを使用する
        StringBuilder sb = new StringBuilder("apple");
        System.out.println("sb : " + sb.append("orange"));

        //文字連結。joinを使用する
        String strarray[] = {"apple", "orange", "melon"};
        String str4 = String.join(",", strarray);//各要素を“,”で区切る
        System.out.println(str4);




    }
}

/*import java.util.Scanner;

public class hige {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        sc.close();
        int n = 0, ans = 0, mode = 0, mode1 = 0;
        int[] ans1=new int[101];

        if(s.length() == 1){
            if(s.charAt(0) == t.charAt(0)){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        }
        else if(t.length() == 1){
            System.out.println("No");
        }else{
        for(int i = 0; i < 2; i++ ){
            n = ans;
            ans = stringCount(s, n, t.charAt(i));
            if(ans != -1){
             ans1[i] = ans;
             //System.out.println(ans);
             ans ++;
             mode ++;
            }else{
                System.out.println("No");
                break;
            }
        }
        }

        if(mode != 0){

            if(ans1[0] == 0){
                System.out.println("No");
            }

            int x = ans1[1] - ans1[0];
            int count = 0;
            for(int i = ans1[0]; i < s.length(); i += x ){
                
                if(s.charAt(i) != t.charAt(count)){
                    System.out.println("No");
                    mode1 ++;
                }else{
                    if(count != t.length())count ++;
                }
            }
            if(mode1 == 0 && count == t.length()){
                System.out.println("Yes");
            }
            else if (mode1 == 0 && count != t.length()){
                System.out.println("No");
            }
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
/*ans=0
n=ans
n番目みる*/

