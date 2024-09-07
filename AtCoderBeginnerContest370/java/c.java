import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        sc.close();

        ArrayList<String> hoge = new ArrayList<>();
        ArrayList<String> ans = new ArrayList<>();

        while(!S.equals(T)){
            char[] s = S.toCharArray();
            char[] t = T.toCharArray();
            for(int i = 0; i < S.length(); i++){
                if(s[i] != t[i]){
                    char x = s[i];
                    s[i] = t[i];
                    String A = new String(s);
                    hoge.add(A);
                    s[i] = x;
                }
            }
            Collections.sort(hoge);
            S = hoge.get(0);
            ans.add(hoge.get(0));
            hoge.clear();
        }

        System.out.println(ans.size());

        for (int i = 0; i < ans.size(); i++) {
            System.out.println(ans.get(i));
        }
    }
}
