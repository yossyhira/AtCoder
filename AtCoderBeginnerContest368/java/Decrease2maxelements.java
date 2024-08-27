import java.util.*;

public class Decrease2maxelements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int zeroCount = 0, count = 0;
        int Idx = sc.nextInt();
        Integer[] num = new Integer[Idx];

        for(int i = 0; i < Idx; i++){
            num[i] = sc.nextInt();
        }
        sc.close();
        while (zeroCount < Idx - 1){
            Arrays.sort(num, Comparator.reverseOrder());
            for (int i = 0; i < 2; i++){
                num[i] --;
                if(num[i] == 0){
                    zeroCount ++;
                }
            }
            count ++;
        }
        System.out.println(count);
    }
}