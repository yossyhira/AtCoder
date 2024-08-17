import java.util.*;

public class AtoZString{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();
       
       int A = text.indexOf("A");
       int Z = text.lastIndexOf("Z");

        System.out.println(Z-A+1);
    }

}