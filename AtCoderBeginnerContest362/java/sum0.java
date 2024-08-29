import java.util.*;

public class sum0 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long minNum = 0, maxNum = 0;
        int Idx = sc.nextInt();
        int[] l = new int[Idx];
        int[] r = new int[Idx];
        for(int i = 0; i < Idx; i++){
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
            minNum += (long)l[i];
            maxNum += (long)r[i];
        }
        sc.close();

        if(minNum > 0 || maxNum < 0){
            System.out.println("No");
            return;
        }

        System.out.println("Yes");
        if(minNum == 0){
            for(int i = 0; i < Idx; i++){
                System.out.print(l[i]+" ");
            }
            System.out.println();
            return;
        }
        else if(maxNum == 0){
            for(int i = 0; i < Idx; i++){
                System.out.print(r[i]+" ");
            }
            System.out.println();
            return;
        }
        
        int[] ans = new int[Idx];
        int count = 0;
        long num = 0 - minNum;
        for(int i = 0; i < Idx; i++){
            ans[i] = (int) Math.min(l[i] + num, r[i]);
            num -= (long)(ans[i] - l[i]);
            count ++;
            if(num == 0)break;
        }

        for(int i = 0; i < count; i++){
            System.out.print(ans[i]+" ");
        }
        for(int i = count; i < Idx; i++){
            System.out.print(l[i]+" ");
        }
        System.out.println();
    }
}