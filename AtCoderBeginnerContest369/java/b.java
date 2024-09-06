import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int[] L = new int[Idx];
        int[] R = new int[Idx];
        int key, countL = 0, countR = 0;
        String hand;
        for(int i = 0; i < Idx; i++){
            key = sc.nextInt();
            hand = sc.next();
            if(hand.equals("L")){
                L[countL] = key;
                countL++; 
            }else{
                R[countR] = key;
                countR++;
            }     
        }
        sc.close();
        int ans = 0;
        for(int i = 0; i < countL - 1; i++){
            ans += Math.abs(L[i] - L[i+1]);
        }
        
        for(int i = 0; i < countR - 1; i++){
            ans += Math.abs(R[i] - R[i+1]);
        }
        

        System.out.println(ans);
    }
}