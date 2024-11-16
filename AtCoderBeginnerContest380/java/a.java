import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();

        char[] s = text.toCharArray();

        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        for (int i = 0; i < 6; i++) {
            if(s[i] == '1'){
                count1 ++;
            }
            if(s[i] == '2'){
                count2 ++;
            }
            if(s[i] == '3'){
                count3 ++;
            }

        }

        if(count1 == 1 && count2 == 2 && count3 == 3){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

    }
}