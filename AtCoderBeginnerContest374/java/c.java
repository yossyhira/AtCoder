import java.util.*;


public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int[] num = new int[Idx];
        for (int i = 0; i < Idx; i++) {
            num[i] = sc.nextInt();
        }
        sc.close();

        long ans = Long.MAX_VALUE;
        
    
        for (int i = 0; i < (1 << Idx); i++) {
            long A = 0;
            long B = 0; 
            for (int j = 0; j < Idx; j++) {
                if((i & (1 << j)) != 0){
                    A += num[j];
                }else{
                    B += num[j];
                }
            }

            long maxNum = Math.max(A, B);
            ans = Math.min(ans, maxNum);  
        }
        System.out.println(ans);
    }
}