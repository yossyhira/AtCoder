import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();

        char[] t = text.toCharArray();
        int pointA = 0, pointB = 0, pointC= 0 ;

        for (int i = 0; i < 3; i++) {
            if(t[i] == 'A'){
                pointA = 1;
            }
            if(t[i] == 'B'){
                pointB = 1;
            }
            if(t[i] == 'C'){
                pointC = 1;
            }
        }
        if(pointA == 1 && pointB == 1 && pointC==1){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
        
    }
}