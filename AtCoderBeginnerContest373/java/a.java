import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = 0;
        for(int i = 0; i < 12; i ++){
        String text = sc.next();
        if(text.length() == i+1){
            count++;
        }
        }
        sc.close();

        System.out.println(count);
    }
}