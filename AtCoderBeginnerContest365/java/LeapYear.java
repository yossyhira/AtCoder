import java.util.Scanner;

public class  LeapYear{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Year = sc.nextInt();
        sc.close();

        if(!(Year % 4 == 0 ) || ((Year % 100 == 0) && !(Year % 400 == 0))){
            System.out.println(365);
        }
        else if((Year % 400 == 0 ) || ((Year % 4 == 0) && !(Year % 100 == 0))){
            System.out.println(366);
        }
    }
}