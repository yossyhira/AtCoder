import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] q = new int [N];
        int[] r = new int [N];
        for (int i = 0; i < N; i++) {
            int qnum =sc.nextInt();
            int rnum =sc.nextInt();
            q[i] = qnum;
            r[i] = rnum;
        }
        int Q = sc.nextInt();
        for (int i = 0; i < Q; i++) {
            int kind = sc.nextInt() - 1;
            int day = sc.nextInt();

            int dayAdd = r[kind] - (day % q[kind]);

            if(dayAdd >= 0){
                System.out.println(day+dayAdd);
            }else{
                System.out.println(day + (q[kind] + dayAdd));
            }

        }
        sc.close();
    }
}