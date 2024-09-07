import java.util.*;

public class a369 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numA = sc.nextInt();
        int numB = sc.nextInt();
        sc.close();

        int num = Math.abs(numA - numB);
        if(num == 0){
            System.out.println(1);
        }
        else if(num % 2 == 0){
            System.out.println(3);
        }else{
            System.out.println(2);
        }
        
    }
}