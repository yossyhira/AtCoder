import java.util.*;
/*import java.util.HashSet;
import java.util.Set;
*/


class CardEater {
    public static void main(String[] args) {
       //String型の要素を格納するHashSetのインスタンスを作成する場合
       //Set<型> 変数名 = new HashSet<型>();
      Set<String> set = new HashSet<String>();
      
      Scanner sc = new Scanner(System.in);
      int num = sc.nextInt(); 
      for(int i = 0; i < num; i++){
        set.add(sc.next());
      }
      System.out.println(set.size()%2 == 0?set.size()-1:set.size());
    }
}