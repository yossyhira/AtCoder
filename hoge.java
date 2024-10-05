import java.util.*;

public class hoge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double numA = sc.nextDouble();
        // 入力処理を行う
        sc.close();

        System.out.println(numA);


    }
}


/*public class hoge {
    public static void main(String[] args) {
        String str3 = "apple orange melon";
        str3 = str3.replaceAll(" ", ""); // 半角スペース削除
        int splitLength = 3; // 任意の区切り文字数を指定

        String[] fruits2 = splitString(str3, splitLength);

        for (String fruit : fruits2) {
            System.out.println(fruit);
        }
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
}*/

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

