import java.util.*;

public class EnumerateSequences {
    private static List<int[]> results = new ArrayList<>();
    
    private static void allNum(int[] array, int Idx, int sum, int K, int[] R) {
        if (Idx == array.length) {
            if (sum % K == 0) results.add(array.clone());
            return;
        }
        
        for (int i = 1; i <= R[Idx]; i++) {
            array[Idx] = i;
            allNum(array, Idx + 1, sum + i, K, R);
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] R = new int[N];
        for (int i = 0; i < N; i++) {
            R[i] = scanner.nextInt();
        }
        
        int[] array = new int[N];

        int Idx = 0;
        int sum = 0;
        allNum(array, Idx, sum, K, R);
        
        results.sort((a, b) -> {
            for (int i = 0; i < a.length; i++) {
                if (a[i] != b[i]) {
                    return a[i] - b[i];
                }
            }
            return 0;
        });
        
        for (int[] result : results) {
            for (int value : result) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
