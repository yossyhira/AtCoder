import java.util.Scanner;

public class GluttonTakahashi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        String[] text;
        text = new String[Idx];
        for(int i = 0; i < Idx; i++){
            text[i] = sc.next();
        }
        sc.close();

        int notEat = 0;
        for(int i = 0; i < Idx-2; i++){
            if(text[i].equals(text[i+1]) && text[i].equals("sweet") ){
                notEat = 1;
                break;
            }
        }

        if(notEat == 0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}