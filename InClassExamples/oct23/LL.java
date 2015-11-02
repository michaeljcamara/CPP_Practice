// Bob Roos
// Primitive linked list implementation with reference variable "next"

class Node {
  private String value;
  private Node next;     // reference data type (= "pointer")

  public Node(String v, Node n) {
    value = v;
    next = n;
  }

  public String value() { return value;}
  public Node next() { return next;}
}

public class LL {
  public static void main(String[] args) {
   // Build a simple linked list of four nodes:
    Node first = new Node("first",null);
    Node second = new Node("second",first);
    Node third = new Node("third",second);
    Node fourth = new Node("fourth",third);

    Node n = fourth;
    while (n != null) {
      System.out.println(n.value());
      n = n.next();
    }
  }
}
