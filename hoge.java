import java.util.*;

public class hoge {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
 
        list.add("a");
        list.add("b");
        list.add("c");

        // forEachメソッド　listの全ての要素を出力
        list.forEach(System.out::println);//printlnで各文字ごとに改行, printでつなげて出力
                                          // ::はメソッド参照
        //ラムダ(->)を使いbを飛ばして出力                                  
        list.forEach(s -> { // forEachメソッド
            if (s.equals("b")){ 
                return; // continueだとエラーが出るので代わりにreturnを使う(bを飛ばす)
            }
            System.out.println(s);
        });
        
        //addAllメソッド　listの末尾に別のリストを追加
        List<Integer> list1 = new ArrayList<>();
 
        list1.add(1);
        list1.add(2);
        list1.add(3);
        list1.add(4);
         
        List<Integer> list2 = new ArrayList<>();
         
        list2.add(5);
        list2.add(6);
        list2.add(7);
        list2.add(8);
         
        list1.addAll(list2); //list1にlist2を追加
        
        System.out.println(list1); //[1, 2, 3, 4, 5, 6, 7, 8]
        list1.forEach(s -> System.out.print(s + " "));//[]を無くして出力　1 2 3 4 5 6 7 8
        System.out.println(); 

        //getメソッド　要素0に何があるのか調べる
        System.out.println(list1.get(0)); // 1

        //indexOfメソッド　1がどの要素にあるのか調べる
        System.out.println(list1.indexOf(1)); // 1

        //setメソッド　listの値を書き換え
        list1.set(0, 3); //list1の要素0を３に書き換え
        
        System.out.println(list1); //[3, 2, 3, 4, 5, 6, 7, 8]

        
        //subListメソッド　部分的に配列を抜き出し
        List<Integer> sbList = list1.subList(1, 3); //要素1から3未満まで(1~2)を抜き出し
        System.out.println(sbList);//[2, 3]

        //subListを使い指定範囲削除
        list1.subList(1, 3).clear();
        System.out.println(list1); //[2, 3]を削除して[3, 4, 5, 6, 7, 8]

        //removeメソッド　指定した要素を削除
        list1.remove(0); 
        System.out.println(list1);//[4, 5, 6, 7, 8]

        //addメソッド　先頭に追加
        //list1.add(追加したい場所, 追加するもの);　追加したい場所を指定しないと末尾に追加
        list1.add(0, 3);
        System.out.println(list1);//[3, 4, 5, 6, 7, 8]

        // 配列からListへの変換
        String[] array1 = {"s", "a", "m", "u", "r", "a", "i"};
        List<String> list3 = Arrays.asList(array1);
         
        System.out.println(list3);
        
        // Listから配列への変換
        List<String> list4 = new ArrayList<>(Arrays.asList("s", "a", "m", "u", "r", "a", "i"));
        String[] array2 = list4.toArray(new String[list4.size()]);
        
        for(String s: array2) {
            System.out.println(s);
        }


    }
}


/*public class hoge {
    public static void main(String[] args) {
        String str3 = "apple orange melon";
        str3 = str3.replaceAll(" ", ""); // 半角スペース削除
        int splitLength = 3; // 任意の区切り文字数を指定

        String[] fruits2 = splitString(str3, splitLength);

        for (String fruit : fruits2) {
            System.out.println(fruit);
        }
        for (String fruit : fruits2) {
            if(fruit.length() == splitLength){
                fruit = fruit.substring(splitLength - 1);
                System.out.println(fruit);
            }
        }
    }

    public static String[] splitString(String str, int length) {
        int arraySize = (int) Math.ceil((double) str.length() / length);
        String[] result = new String[arraySize];

        for (int i = 0; i < arraySize; i++) {
            int start = i * length;
            int end = Math.min(start + length, str.length());
            result[i] = str.substring(start, end);
        }

        return result;
    }
}*/

/*import java.util.Scanner;

public class hige {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        sc.close();
        int n = 0, ans = 0, mode = 0, mode1 = 0;
        int[] ans1=new int[101];

        if(s.length() == 1){
            if(s.charAt(0) == t.charAt(0)){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        }
        else if(t.length() == 1){
            System.out.println("No");
        }else{
        for(int i = 0; i < 2; i++ ){
            n = ans;
            ans = stringCount(s, n, t.charAt(i));
            if(ans != -1){
             ans1[i] = ans;
             //System.out.println(ans);
             ans ++;
             mode ++;
            }else{
                System.out.println("No");
                break;
            }
        }
        }

        if(mode != 0){

            if(ans1[0] == 0){
                System.out.println("No");
            }

            int x = ans1[1] - ans1[0];
            int count = 0;
            for(int i = ans1[0]; i < s.length(); i += x ){
                
                if(s.charAt(i) != t.charAt(count)){
                    System.out.println("No");
                    mode1 ++;
                }else{
                    if(count != t.length())count ++;
                }
            }
            if(mode1 == 0 && count == t.length()){
                System.out.println("Yes");
            }
            else if (mode1 == 0 && count != t.length()){
                System.out.println("No");
            }
        }

    }

   public static int stringCount(String s, int n, char c) {
    int ans = -1;
    for (int i = n; i < s.length(); i++) {
        if (s.charAt(i) == c) {
            ans = i;
            break;
        }
    }
    return ans;
 }
}
/*ans=0
n=ans
n番目みる*/

