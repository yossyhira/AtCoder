import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public class Cut {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx, draw;
        Idx = sc.nextInt();
        draw = sc.nextInt();
        sc.nextLine();
        String input = sc.nextLine();
        List<Integer> list = Stream.of(input.split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        sc.close();

        List<Integer> list1 = new ArrayList<>(list.subList(list.size() - draw, list.size()));
        list.subList(list.size() - draw, list.size()).clear();
        list1.addAll(list);
        list1.forEach(s -> System.out.print(s + " "));
        System.out.println();
    }
}