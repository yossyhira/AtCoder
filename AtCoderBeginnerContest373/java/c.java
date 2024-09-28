import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numA = sc.nextInt();
        int numB = sc.nextInt();
        int numC = sc.nextInt();
        String text = sc.next();
        // 入力処理を行う
        sc.close();

        System.out.println((numA+numB+numC)+" "+text);
    }
}