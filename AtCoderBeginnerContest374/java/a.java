import java.util.*;


public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        sc.close();

        if (text.endsWith("san")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}