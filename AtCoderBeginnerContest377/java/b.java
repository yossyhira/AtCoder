import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] n = new char[8][8];
        String hoge;
        int[] ansG = new int[8];
        int[] ansR = new int[8];

        for (int i = 0; i < 8; i++) {
            hoge = sc.next();
            n[i]= hoge.toCharArray();
        }
        sc.close();

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if(n[i][j] == '#'){
                    ansG[i] = 1;
                    ansR[j] = 1;
                }
            }
        }
         int ansGNum = 0, ansRNum = 0;
        for (int i = 0; i < 8; i++) {
            if(ansG[i] == 0){
                ansGNum ++;
            }
            if(ansR[i] == 0){
                ansRNum ++;
            }
        }

        System.out.println(ansGNum*ansRNum);
    }
}