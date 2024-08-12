import java.util.Scanner;

public class Election2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int takahashi = sc.nextInt();
        int aoki = sc.nextInt();
        // 入力処理を行う
        sc.close();

        int win = 0;

        win = (num / 2) + 1;

        if(win <= takahashi || win <= aoki){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
