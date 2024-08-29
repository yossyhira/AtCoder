import java.util.*;

public class BuyaPen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int money = 0;
        int red = sc.nextInt();
        int green = sc.nextInt();
        int blue = sc.nextInt();  
        String color = sc.next();
        sc.close();

        if(color.equals("Red")){
            money = Math.min(green, blue);
        }
        else if(color.equals("Green")){
            money = Math.min(red, blue);
        }
        else if(color.equals("Blue")){
            money = Math.min(green, red);
        }

        System.out.println(money);
    }
}