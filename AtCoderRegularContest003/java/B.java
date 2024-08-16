import java.util.*;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int wordCount = scanner.nextInt();
        String[] words = new String[wordCount];
        String[] reverseWord = new String[wordCount];
        for (int i = 0; i < wordCount; i++) {
            words[i] = scanner.next();
        }
        scanner.close();

        for (int i = 0; i < wordCount; i++) {
            reverseWord[i] = reverse(words[i]);
        }
        Arrays.sort(reverseWord);
        for (int i = 0; i < wordCount; i++) {
            System.out.println(reverse(reverseWord[i]));
        }

    }

    public static String reverse(String word){
        String reverseWord;
        reverseWord = new StringBuilder(word).reverse().toString();
        return reverseWord;
    }
}