//レ点の問題
import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Set<Integer> h = new HashSet<Integer>();
        for (int i = 0; i < m; i++) {
            int num = sc.nextInt();
            h.add(num);
        }
        sc.close();

        List<Integer> waitNum = new ArrayList<>();
        
        for (int i = 1; i <= n; i++) {
            if(h.add(i)){
                System.out.print(i + " ");
                int roop = waitNum.size();
                for (int j = 0; j < roop ; j++) {
                    int size = waitNum.size() - 1;
                    System.out.print(waitNum.get(size) + " ");
                    waitNum.remove(size);
                }
            }else{
                waitNum.add(i);
            }

        }
        System.out.println();
    }
}