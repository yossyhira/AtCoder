import java.util.*;

public class oneDCountry {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        long[] town = new long[Idx];
        int[] peple = new int[Idx];
        for(int i = 0; i < Idx; i++){
            town[i] = sc.nextLong();
        }
        for(int i = 0; i < Idx; i++){
            peple[i] = sc.nextInt();
        }
        int loop = sc.nextInt();
        for(int i = 0; i < loop; i++){
            long start = sc.nextLong();
            long end = sc.nextLong();
            int startIdx = -1, endIdx = 0;
            long ans = 0;
            for(int j = 0; j < Idx; j++){
                if(start <= town[j] && startIdx == -1){
                    startIdx = j;

                }
                if(end <= town[j] || j == Idx -1){
                    if(end > town[j]){
                        endIdx = j + 1;
                    }else{
                        endIdx = j ;
                    }
                    break;
                }
            }
            for(int j = startIdx; j < endIdx; j++){
                ans += peple[j];
            }
            System.out.println(ans);
        }
        sc.close();
    }
}