// Bob Roos
// Demonstration of iterators (the ":" operator)

import java.util.*;
public class Iterate {
  public static void main(String[] args) {
    LinkedList<String> list = new LinkedList<String>();
    list.addFirst("one");
    list.addLast("two");
    list.addFirst("three");
    list.addLast("four");
    list.addFirst("five");
    list.addLast("six");
    for (String s : list) {
      System.out.println(s);
    }

    String[] t = {"ONE", "TWO", "THREE", "FOUR"};
    for (String s : t) {
      System.out.println(s);
    }

    HashSet<Integer> set = new HashSet<Integer>();
    set.add(1000);
    set.add(2000);
    set.add(3000);
    set.add(4000);
    for (int i : set) {
      System.out.println(i);
    }
  }
}
