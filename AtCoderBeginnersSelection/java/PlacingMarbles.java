import java.util.Scanner;

public class PlacingMarbles {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        int sum = 0;

        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == '1') {
                sum++;
            }
        }

        System.out.println(sum);
    }
}
