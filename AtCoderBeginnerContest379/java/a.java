import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();
        char[] s = text.toCharArray();
        System.out.print(s[1]);
        System.out.print(s[2]);
        System.out.print(s[0]);
        System.out.print(" ");
        System.out.print(s[2]);
        System.out.print(s[0]);
        System.out.println(s[1]);

        
    }
}