import java.util.Scanner;

public class PilingUp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        sc.close();

        for(int i = 1; i < 4; i++){
            int ans = (i*100) - num;
            if(ans > 0){
                System.out.println(ans);
                break;
            }
        }
    }
}