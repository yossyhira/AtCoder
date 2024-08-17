import java.util.*;

public class XYetAnotherDieGame{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long num = sc.nextLong();
        sc.close();

        long count = (num / 11)*2;

        int mod = (int)(num % 11);

        while(mod > 0 ){
            if(mod > 0){
                mod -= 6;
                count++;
            }
            if(mod > 0){
                mod -= 5;
                count++;
            }
        }

        System.out.println(count);
    }

}