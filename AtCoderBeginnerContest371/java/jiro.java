import java.util.*;

public class jiro {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String AB = sc.next();
        String AC = sc.next();
        String BC = sc.next();
        sc.close();

        if(AB.equals("<") && AC.equals("<")&& BC.equals("<"))System.out.println("B");
        if(AB.equals("<") && AC.equals("<")&& BC.equals(">"))System.out.println("C");
        if(AB.equals("<") && AC.equals(">")&& BC.equals(">"))System.out.println("A");
        if(AB.equals(">") && AC.equals("<")&& BC.equals("<"))System.out.println("A");
        if(AB.equals(">") && AC.equals(">")&& BC.equals("<"))System.out.println("C");
        if(AB.equals(">") && AC.equals(">")&& BC.equals(">"))System.out.println("B");
    }
}