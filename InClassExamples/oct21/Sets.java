// Bob Roos
// Demonstration of the HashSet class

import java.util.*;

public class Sets {
  public static void main(String[] args) {
    HashSet<Integer> s1, s2;

    s1 = new HashSet<Integer>();
    s2 = new HashSet<Integer>();

    s1.add(1); s1.add(32); s1.add(88); s1.add(-1);
    s2.add(3); s2.add(3); s2.add(3); s2.add(32); s2.add(0);

    for(Integer i : s1) {
       System.out.print(i+" ");
    }
    System.out.println();

    for(Integer i : s2) {
       System.out.print(i+" ");
    }
    System.out.println();
  }
}
