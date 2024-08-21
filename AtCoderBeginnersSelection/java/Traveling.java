import java.util.Scanner;

public class Traveling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int nowPx = 0, nowPy = 0, nowTime = 0, nextPx, nextPy, nextTime, d, dt;

        for(int i = 0; i < Idx; i++){
            nextTime = sc.nextInt();
            nextPx = sc.nextInt();
            nextPy = sc.nextInt();
            d = Math.abs(nowPx-nextPx) + Math.abs(nowPy-nextPy);
            dt = nextTime - nowTime;

            if(d > dt || (!((dt - d) % 2 == 0))){
                System.out.println("No");
                return;
            }
            nowPx = nextPx;
            nowPy = nextPy;
            nowTime = nextTime;
        }
        sc.close();
        System.out.println("Yes");
    }
}