import java.util.*;

public class CountABCAgain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        String text = sc.next();
        char[] s = text.toCharArray();
        char[] s2 = new char[5];

        int count = 0;
        int index = text.indexOf("ABC");
        while (index != -1) {
            count++;
            index = text.indexOf("ABC", index + 3);
        }

        

        for (int i = 0; i < q; i++) {
            int Idx = sc.nextInt() - 1;
            char word = sc.next().charAt(0);

            int start = Math.max(0, Idx - 2);
            int end = Math.min(n, Idx + 3);//+2ではなく+3なのは, 下のend - startはstratから何文字切り出すかなので一文字余計に多くとる
            String beforeChange = new String(s, start, end - start);
            int beforeCount = 0;
            index = beforeChange.indexOf("ABC");
            while (index != -1) {
                beforeCount++;
                index = beforeChange.indexOf("ABC", index + 1);
            }

            
            s[Idx] = word;

            
            String afterChange = new String(s, start, end - start);
            int afterCount = 0;
            index = afterChange.indexOf("ABC");
            while (index != -1) {
                afterCount++;
                index = afterChange.indexOf("ABC", index + 1);
            }

         
            count = count - beforeCount + afterCount;
            System.out.println(count); 
        }
        sc.close();
    }
}
