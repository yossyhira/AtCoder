import java.util.*;

public class taro {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int roop = sc.nextInt();
       

        int[] taro = new int[Idx];

        for(int i = 0; i < roop; i++){
            int home = sc.nextInt();
            String sex = sc.next();
            if(taro[home - 1] != 1 && sex.equals("M")){
                System.out.println("Yes");
                taro[home - 1] = 1;
            }else{
                System.out.println("No");
            }
        }
        sc.close();
    }
}