// Bob Roos
// Demonstration of lambda expressions in Java.
// This tabulates the values of two different polynomial for arguments 
// 0, 1, ..., 9.
// However, the polynomials are not ordinary Java functions but 
// lambda expressions.

import java.util.*;
import java.util.function.*;

public class Lab7Part4 {
  public static void main(String[] args) {
    // For each value of i, call the "poly" function with a lambda
    // expression.
    for (int i = 0; i < 10; i++) {
      double y = poly(i,(Double x)->3+2*x-4*x*x); // lambda expression
      System.out.println("i="+i+" y="+y);
    }
    for (int i = 0; i < 10; i++) {
      double y = poly(i,(Double x)->-3+4.5*x+.01*x*x); // lambda expression
      System.out.println("i="+i+" y="+y);
    }

    //String s = rotate("aest", (String x)-> x.charAt(x.length()-1) + x.substring(1, x.length()-1) + x.charAt(0));
    //String s = rotate("aest", (String x, Integer pos)-> x.substring(pos, x.length()-1) + x.substring(1, x.length()-1) + x.charAt(0));
    //System.out.println(s);
    
//    String s = rotate(
//

    // Try to create random name generator based on a starting name...maybe plus another var
    BiFunction<Integer,String,String> rotateThis = (num, name)->name.substring(num) + name.substring(0, num);


    String startName = "Michael";
    int rotateAmt = 3;

    for(int i = 0; i < startName.length(); i++ ) {

        String endName = rotate(i, "Michael", rotateThis);
        System.out.println(endName);
    }

    Function<String,Boolean> isLetter = letter->letter.toLowerCase().matches("[a-z]");
    Function<String,Boolean> isVowel = letter->letter.toLowerCase().matches("[aeiou]");

    System.out.println(isVowel.apply("p"));
        System.out.println(isLetter.apply("1"));



  }

  // Given a function f and a value x, apply f to x and return the result:
  public static double poly(double x, Function<Double,Double> f) {
    return f.apply(x);
  }

//  public static String rotate(int x, Function<String,String> f) {
//    return f.apply(x);
//  }

  public static String rotate(int num, String name, BiFunction<Integer,String,String> f) {
      return f.apply(num, name);
  }
} 
