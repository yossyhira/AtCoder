import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        String text = sc.next();
        sc.close();
        char[] s = text.toCharArray();
        boolean isOddNum = false, isOne = false, isSlash = false, isTwo = false;
        if((len % 2) != 0) isOddNum = true;

        int roop = ((len + 1) / 2) - 1;
        int Onecount = 0;
        for (int i = 0; i < roop; i++) {
            if(s[i] == '1'){
                Onecount ++;
            }
        }
        if(Onecount == roop) isOne = true;

        if(s[roop] == '/') isSlash = true;

        int Twocount = 0;
        for (int i = roop + 1; i < len; i++) {
            if(s[i] == '2'){
                Twocount ++;
            }
        }
        if(Twocount == (len - (roop + 1))) isTwo = true;
        if(isOddNum && isOne && isSlash && isTwo){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}