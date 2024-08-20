import java.util.*;

public class ShoutEveryday {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        sc.close();

        if (b < c) {
            if (b < a && a < c) { 
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }
        }else{
            if(b < a || a < c){
                System.out.println("No");
            }else{
                System.out.println("Yes");
            }
        }
    }
}
