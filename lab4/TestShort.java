// Use this to test the modified Lab4Short.class file to make sure
// the modified bytecode is still valid.
//
// Proper usage:
//      javac Lab4Short.java 
//      javac TestShort.java
//      jbe &
//        ... make changes to Lab4Short.class ...
//      java TestShort
//        ... should run without errors ...

// This will NOT tell you if you have correctly answered the question!
// All it does it tell you if your bytecode is legal.

public class TestShort {
  public static void main(String[] args) {
    Lab4Short x = new Lab4Short();
    System.out.println(x.f());
  }
}
