import java.util.Scanner;

public class hakutyumu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();
        String[] T = {"dreamer", "dream","eraser","erase"};
        
        boolean end = true;
        while(text.length() >= 1){
            end = true;
            if(text.endsWith("dream") || text.endsWith("erase")){
                text = text.substring(0,text.length() - 5);
                end = false;
            }
            else if(text.endsWith("eraser")){
                text = text.substring(0,text.length() - 6);
                end = false;
            }
            else if(text.endsWith("dreamer")){
                text = text.substring(0,text.length() - 7);
                end = false;
            }

            if(end){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}