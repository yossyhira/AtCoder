import java.util.Scanner;

public class hige {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();
        char c = '1';
        int ans = stringCount(s, c);
        System.out.println(ans);
    }

   public static int stringCount(String s, char c) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == c) {
            count++;
        }
    }
    return count;
}
}

/*public class hige {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        //int num1 = scanner.nextInt();
        scanner.close();
        //long ans = modPow(num, num1);
        if(evenNum(num)){
            System.out.println("G");
        }else{
             System.out.println("K");
        }
    }

    public static boolean evenNum(int num) {
        if((num & 1)==0)return true;//偶数
        return false;//奇数
    }
}*/

