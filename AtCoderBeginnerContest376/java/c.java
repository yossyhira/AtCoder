import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n - 1];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            b[i] = sc.nextInt();
        }

        Arrays.sort(a);
        Arrays.sort(b);

        final int INF = 1001001001;
        int ac = INF, wa = 0;

        // ここが二分探索
        while (ac - wa > 1) {
            int wj = (wa + ac) / 2;
            if (judge(wj, a, b, n)) {
                ac = wj;
            } else {
                wa = wj;
            }
        }
        //
        
        if (ac == INF) {
            System.out.println(-1);
        } else {
            System.out.println(ac);
        }

        sc.close();
    }

    // Moved the judge method outside the main method
    public static boolean judge(int x, int[] a, int[] b, int n) {
        List<Integer> nb = new ArrayList<>();
        for (int value : b) {
            nb.add(value);
        }
        nb.add(x);
        Collections.sort(nb);

        for (int i = 0; i < n; i++) {
            if (a[i] > nb.get(i)) {
                return false;
            }
        }
        return true;
    }
}
