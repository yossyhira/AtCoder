import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();

        char[] s = text.toCharArray();

        int count = 0;

        for (int i = 1; i < text.length(); i++) {
            if(s[i] == '-'){
                count++;
            }else{
                System.out.print(count + " ");
                count = 0;
            }
        }

        System.out.println();
    }
}