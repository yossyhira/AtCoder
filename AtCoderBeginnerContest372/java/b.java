import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt() - 1;
        char word = sc.next().charAt(0);
        // 入力処理を行う
        sc.close();

        String A = "HHHHABC";

        int result = 0;
            
         result = A.indexOf("ABC", result);
        System.out.println(Idx+" "+word+" "+result);
    }
}