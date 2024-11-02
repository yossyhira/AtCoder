import java.util.*;

public class c2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        Map<Integer, Integer> indexMap = new HashMap<>();

        int size = 0;
        
        for (int i = 0; i < Idx - 1; i++) {
            int num = sc.nextInt();
            if (!indexMap.containsKey(num)) {
                System.out.print(-1 + " ");
            } else {
                System.out.print(indexMap.get(num) + 1 + " ");
            }
            indexMap.put(num, size);
            size++;
        }
        
        int num = sc.nextInt();
        if (!indexMap.containsKey(num)) {
            System.out.println(-1);
        } else {
            System.out.println(indexMap.get(num) + 1);
        }
    }
}
