// Bob Roos
// Demonstration of enumerated types in Java.
// Unlike the "enum" type in C, Java enum types can not be used
// interchangeably with int values. In particular, you can't
// compare enum values or perform arithmetic on them.
enum Weekday {
  MON,TUE,WED,THU,FRI,SAT,SUN
}

public class Enumerate {
  public static void main(String[] args) {
    Weekday a,b,c;
    a = Weekday.MON;
    b = Weekday.FRI;
    System.out.println("a = "+a+", b = " + b);
// THESE ARE ILLEGAL:
//  if (a < b) ...
//  a = a+1;
  }
}
