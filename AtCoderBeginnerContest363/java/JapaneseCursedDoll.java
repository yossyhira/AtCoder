import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class JapaneseCursedDoll {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int hair = sc.nextInt();
        int maxPerson = sc.nextInt();
        Integer[] person = new Integer[Idx];
        int day = 0;
        
        for(int i = 0; i < Idx; i++){
            person[i] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(person, Comparator.reverseOrder());
        for(int i = person[maxPerson - 1]; i < hair; i++)day++;
        System.out.println(day);
    }
}