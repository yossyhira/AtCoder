import java.util.Scanner;

public class Shiftonly {

    private static int mod(int x){   
        if(x % 2 == 0){
            return 1;
        }else{
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] num,modNum;
        int tryCount =0;
        int Idx = sc.nextInt();
        
        num = new int[Idx];
        modNum = new int[Idx];
        for(int i = 0; i < Idx; i++){
            num[i] = sc.nextInt(); 
        }
        sc.close();

        while(true){
            int count = 0;

            for(int i = 0; i < Idx; i++){
                modNum[i] = mod(num[i]); 
                if (modNum[i] == 1){
                    num[i] = num[i]/2;
                }
                count += modNum[i];
            }
            if(count == Idx){
                tryCount++;
            }else{
                break;
            }
        }

        System.out.println(tryCount);
    }
}