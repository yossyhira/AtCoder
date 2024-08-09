import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class MinimumGlutton {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int maxDishes = sc.nextInt();
        long maxSweet = sc.nextLong();
        long maxSolt = sc.nextLong();
        
        Integer[] sweet = new Integer[maxDishes];
        Integer[] solt = new Integer[maxDishes];

        for(int i = 0; i < maxDishes; i++){
            sweet[i] = sc.nextInt();
        }
        for(int i = 0; i < maxDishes; i++){
            solt[i] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(sweet, Comparator.reverseOrder());
        Arrays.sort(solt, Comparator.reverseOrder());

        long sumSweet = 0, sumSolt = 0;
        int ans = maxDishes;
        for(int i = 0; i < maxDishes; i++){

            sumSweet += sweet[i];
            sumSolt += solt[i];

            if(sumSweet > maxSweet || sumSolt > maxSolt){
                ans = i + 1;
                break;
            }
        }

        System.out.println(ans);
        
    }
}