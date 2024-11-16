import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String text = sc.next();
        sc.close();

        List<Integer> index = new ArrayList<>();
        List<Integer> len = new ArrayList<>(); 

        char[] s = text.toCharArray();
        int count = 0;
        for (int i = 0; i <text.length(); i++) {
            if(s[i] == '1'){
                if(count == 0){
                    index.add(i);
                }
                count ++;
            }else{
                if(count != 0){
                    len.add(count);
                    count = 0;
                }
            }
        }

        if(index.size() != len.size()){
            len.add(count);
        }
        StringBuilder sb = new StringBuilder(text);
        int start = index.get(k - 1);
        int end = start + len.get(k - 1);
        sb.delete(start, end);

        int countOne = len.get(k - 1);
        String one = "1".repeat(countOne);

        int size = index.size();
        int position = index.get(k - 2)+len.get(k - 2);
        sb.insert(position, one);

        String result = sb.toString();
        System.out.println(result);
    }
}