import java.util.Scanner;

public class Product {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numA = sc.nextInt();
        int numB = sc.nextInt();
        sc.close();

        if ((numA * numB) % 2 == 0){
            System.out.println("Even");
        }else{
            System.out.println("Odd");
        }
    }
}