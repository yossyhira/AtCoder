import java.util.Scanner;

public class TripleAttack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int enemy, mod;
        long T = 0;

        for(int i = 0; i < Idx; i++){
            enemy = sc.nextInt();

            T += (long)((enemy / 5) * 3);

            if (enemy % 5 != 0){
                mod = enemy % 5;
                do{
                    T++;
                    if(T % 3 != 0){
                        mod --;
                    }else{
                        mod -= 3;
                    }
                }while(mod > 0);
            }
        }
        sc.close();
        System.out.println(T);
    }
}