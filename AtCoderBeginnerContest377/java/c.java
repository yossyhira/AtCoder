import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long M = sc.nextLong();
        
        long ans = (N * N);

        Set<String> used = new HashSet<>();
           
        for (int i = 0; i < M; i++) {
            int g = sc.nextInt() - 1;
            int r = sc.nextInt() - 1;
    
            if (used.add(g + "," + r)) {
                ans--;
            }
            
            
            if(0 <= g + 2 && g + 2 < N && 0 <= r + 1 && r + 1 < N && used.add((int)(g+2) + "," + (int)(r+1))){
                ans --;
            }
            if(0 <= g + 1 && g + 1 < N && 0 <= r + 2 && r + 2 < N&& used.add((int)(g+1) + "," + (int)(r+2))){
                ans --;
            }
            if(0 <= g - 1 && g - 1 < N && 0 <= r + 2 && r + 2 < N&& used.add((int)(g-1) + "," + (int)(r+2))){
                ans --;
            }
            if(0 <= g - 2 && g - 2 < N && 0 <= r + 1 && r + 1 < N&& used.add((int)(g-2) + "," + (int)(r+1))){
                ans --;
            }
            if(0 <= g - 2 && g - 2 < N && 0 <= r - 1 && r - 1 < N&&used.add((int)(g-2) + "," + (int)(r-1))){
                ans --;
               
            }
            if(0 <= g - 1 && g - 1 < N && 0 <= r - 2 && r - 2 < N&& used.add((int)(g-1) + "," + (int)(r-2))){
                ans --;
                
            }
            if(0 <= g + 1 && g + 1 < N && 0 <= r - 2 && r - 2 < N&& used.add((int)(g+1) + "," + (int)(r-2))){
                ans --;
             
            }
            if(0 <= g + 2 && g + 2 < N && 0 <= r - 1 && r - 1 < N&& used.add((int)(g+2) + "," + (int)(r-1))){
                ans --;
              
            }
        }
        sc.close();

        System.out.println(ans);
    }
}