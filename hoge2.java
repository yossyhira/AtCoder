import java.util.*;

class IntStringPair {
    int first;
    String second;

    IntStringPair(int first, String second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }
}

public class hoge2 {
    public static void main(String[] args) {
        List<IntStringPair> nb = new ArrayList<>();
        nb.add(new IntStringPair(2, "ABC"));
        nb.add(new IntStringPair(1, "DEF"));
        nb.add(new IntStringPair(2, "GHI"));
        nb.add(new IntStringPair(1, "JKL"));

        System.out.println("Original List:");
        System.out.println(nb);

        // 全ての第1引数（first）を取得
        for (IntStringPair pair : nb) {
            System.out.println(pair.first); //2 1 2 1
        }
        for (int i = 0; i < nb.size(); i++) {
            System.out.println(nb.get(i).first); //2 1 2 1
        }
        

        // 全ての第2引数（second）を取得
        for (int i = 0; i < nb.size(); i++) {
            System.out.println(nb.get(i).second);//300 200 100 100
        }

    }
}
