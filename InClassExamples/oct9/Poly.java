// Bob Roos
// Overriding instance variables in subclasses is not allowed.
// Overriding methods, on the other hand, is allowd.

class A {
  public int x;
  public void p() { System.out.println("in class A");}
}

class B extends A {
  public String x; // Does this override the x in the parent class?
  
  B(){super();}
  
  public void p() { System.out.println("in class B");}
}

public class Poly {
  public static void main(String[] args) {
    A first = new A();
    first.x = 10;

    B second = new B();
    second.x = "hello";

    A third = new B(); // this is legal, since B is a subclass of A

    third.x = 20;
//    third.x = "goodbye";  // this is not legal
    System.out.println(first.x);
    System.out.println(second.x);
    System.out.println(third.x);
    first.p();
    second.p();
    third.p();

    int x = 1;
    double y = 2.2;
    String z;
    z = x + y;
  }
}
