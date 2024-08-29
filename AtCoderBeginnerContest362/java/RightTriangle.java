import java.util.*;

public class RightTriangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int xA = sc.nextInt();
        int yA = sc.nextInt();
        int xB = sc.nextInt();
        int yB = sc.nextInt();
        int xC = sc.nextInt();
        int yC = sc.nextInt();
        sc.close();

        double AB, AC, BC;
        AB = Math.pow((xA - xB), 2) + Math.pow((yA - yB), 2);
        AC = Math.pow((xA - xC), 2) + Math.pow((yA - yC), 2);
        BC = Math.pow((xB - xC), 2) + Math.pow((yB - yC), 2);

        if(AB + AC == BC || AB + BC == AC || AC + BC == AB){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}