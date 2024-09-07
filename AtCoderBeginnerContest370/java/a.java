import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();
        sc.close();
        
        if(l + r == 1){
            if(l == 1 && r == 0){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        }else{
            System.out.println("Invalid");
        }
    }
}