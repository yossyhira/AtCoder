import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int q = sc.nextInt();
        int[] ring = new int[Idx];
        int Lnow = 0;
        int Rnow = 1;
        ring[Lnow] = 1;
        ring[Rnow] = 1;
        int ans = 0;

        for (int i = 0; i < q; i++) {
            char handc = sc.next().charAt(0);
            int goal = sc.nextInt() - 1;
            int plusAns = 0;
            int minAns = 0;
            int handNow = 0;
            if(handc == 'L') {
                handNow = Lnow;
            }
            if(handc == 'R'){
                handNow = Rnow;
            }

            if(handNow == goal)continue;


            for (int j = 1; j <= Idx; j++) {
                int now = (handNow + j) % Idx;

                if(now == goal){
                    break;
                }
                if((ring[now] == 0) && (now != goal)){
                    plusAns ++;
                }
                else if (ring[now] == 1){
                    plusAns = 1001001;
                    break;
                }
            }

            for (int j = 1; j <= Idx; j++) {

                int now = Math.abs((handNow - j + Idx) % Idx);
                if(now == goal){
                    break;
                }
                if((ring[now] == 0) && (now != goal)){
                    minAns++;
                }
                else if (ring[now] == 1){
                    minAns = 1001001;
                    break;
                }
            }

            ans += Math.min(plusAns, minAns) + 1;
            ring[handNow] = 0;
            ring[goal] = 1;
            if(handc == 'L') {
                Lnow = goal;   
            } else {
                Rnow = goal;  
            }
        }
        sc.close();

        System.out.println(ans);
    }
}