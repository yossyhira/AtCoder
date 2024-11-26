import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();
        char[] s = text.toCharArray();
        boolean isEvenNum = false, isEqual = true, isTwoCount = true;
        int len = text.length();

        if((len % 2) == 0)isEvenNum = true;
        
        
        for (int i = 1; i <= len / 2; i++) {
            if(s[2*i - 2] != s[2*i - 1]){
                isEqual = false;
            }
        }

        Map<Character, Integer> twoMap = new HashMap<>();

        for (int i = 0; i < len; i++) {
            char key = s[i];
            if(!twoMap.containsKey(key)){
                twoMap.put(key, 1);
            }else{
                int count = twoMap.get(key) + 1;
                twoMap.put(key, count);
            }
        }

        for (Map.Entry<Character, Integer> entry : twoMap.entrySet()) {
            if(entry.getValue() != 2){
                isTwoCount = false;
            }
        }
        if(isEvenNum && isEqual && isTwoCount){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}