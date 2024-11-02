import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();

        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < Idx-1; i++) {
            int num = sc.nextInt();
            if(a.indexOf(num) == -1){
                System.out.print(a.indexOf(num)+" ");
            }else{
                System.out.print(a.indexOf(num) + 1+" ");
                int aIdx = a.indexOf(num);
                a.set(aIdx, -1);
            }
            a.add(num);
        }
       int num = sc.nextInt();
        if(a.indexOf(num) == -1){
            System.out.println(a.indexOf(num));
        }else{
            System.out.println(a.indexOf(num) + 1);
        }
    }
}