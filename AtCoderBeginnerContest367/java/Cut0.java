import java.util.*;

public class Cut0 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] num = new char[7]; // 修正: String[] を char[] に変更
        Arrays.fill(num, '0');
        String a = sc.nextLine();
        sc.close();

        for(int i = 0; i < a.length(); i++){
            num[i] = a.charAt(i);
        }
        int count = 0;

        for(int i = a.length()-1; i >= 0; i--){
            if(num[i] == '0'){
                count++;
            }
            else if(num[i] == '.'){
                break;
            }
            else{
                break;
            }
        }
        if(num[a.length()-count-1] == '.'){
            for(int i = 0; i < a.length()-count-1; i++){
            System.out.print(num[i]);
        }
        }else{
            for(int i = 0; i < a.length()-count; i++){
                System.out.print(num[i]);
            }
        }
        System.out.println();
        
    }
}
