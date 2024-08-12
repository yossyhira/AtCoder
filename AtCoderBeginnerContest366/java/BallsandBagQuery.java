import java.util.Scanner;

public class BallsandBagQuery {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int[] ball = new int[1000001];//問題で1<= ball <=10^6と指定されている。
                                      //そして配列は０から始まるので１つ余分に配列を取り
                                      //10^6 + 1で1000001の配列になる
        
        int uniq = 0, ballNum = 0;;
        
        
        for(int i = 0; i < num; i++){
            int Q =sc.nextInt();
            switch (Q) {
                case 3:
                    System.out.println(uniq);
                    break;

                case 1:
                    ballNum = sc.nextInt();
                    ball[ballNum]++;
                    if(ball[ballNum] == 1){
                        uniq++;
                    }
                    break;

                case 2:
                    ballNum = sc.nextInt();
                    ball[ballNum]--;
                    if(ball[ballNum] == 0){
                        uniq--;
                    }
                    break;
            }
        }
        sc.close();
    }
}

/*import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class BallsandBagQuery {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        ArrayList<Integer> ball = new ArrayList<>();
        int count = 0;
        
        
        for(int i = 0; i < num; i++){
            int Q =sc.nextInt();
            switch (Q) {
                case 1:
                    ball.add(sc.nextInt());
                    break;

                case 2:
                    ball.remove(Integer.valueOf(sc.nextInt()));
                    break;

                case 3:
                    HashSet<Integer> uniqueNumbers = new HashSet<>(ball);
                    System.out.println(uniqueNumbers.size());
                    break;
            }
        }
        sc.close();
    }
}*/ 

