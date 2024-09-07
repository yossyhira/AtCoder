import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int[][] num = new int[Idx][Idx];
        for(int i = 0; i < Idx; i++){
            for(int j = 0; j < i + 1; j++){
                num[i][j] = sc.nextInt();
            }
        }
        sc.close();

        int nowNum = num[0][0];

        for(int i = 2; i <= Idx; i++){
            if(nowNum >= i){
                nowNum = num[nowNum - 1][i - 1];
            }else{
                nowNum = num[i - 1][nowNum - 1];
            }
        }

        System.out.println(nowNum);
    }
}