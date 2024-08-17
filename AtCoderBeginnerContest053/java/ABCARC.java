import java.util.*;

public class ABCARC{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rate = sc.nextInt();
        sc.close();
       
       String ans = (rate < 1200)?"ABC":"ARC";

        System.out.println(ans);
        //これでも可
        //System.out.println(rate < 1200?"ABC":"ARC");
    }

}