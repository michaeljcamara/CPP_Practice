// Bob Roos
// "Unwinding" recursive functions
//
// This is the non-recursive version of program Binom.java.
// (There are much simpler non-recursive implementations of
// this that do not require a stack; however, the method shown
// here is a more general approach that can be applied to
// other recursive programs as well.)

import java.util.Stack;

// This class implements a "frame" or "activation record".
class Frame {
  private int n, k, t1,t2; // parameters and local variables
  private int ra;          // return address

  // Constructor:
  public Frame (int n, int k, int ra, int t1, int t2) {
    this.n = n; this.k = k; this.ra = ra;
    this.t1 = t1; this.t2 = t2;
  }

  // Accessor methods ("get" methods):
  public int n() {return n;}
  public int k() {return k;}
  public int ra() {return ra;}
  public int t1() {return t1;}
  public int t2() {return t2;}
}

// Main just calls binom2(n,k) for various values of n and k:
public class Binom2 {
  public static void main(String[] args) {
    for (int n = 0; n <= 8; n++) {
      for (int k = 0; k <= n; k++) {
        System.out.printf("%3d",binom2(n,k));
      }
      System.out.println();
    }
  }

  // binom2 -- computes the binomial coefficient defined as:
  //        binom2(n,k) = 1 if n == 0 or n == k (base case)
  //        binom2(n,k) = binom2(n-1,k-1) + binom2(n-1,k) otherwise
  // This is a nonrecursive implementation that illustrates how
  // the stack frame is used.

  public static int binom2(int n, int k) {
    int retvalue=0, ra=0, temp1=0, temp2=0;

    Stack<Frame> stack = new Stack<Frame>();

    // Main loop just picks one of the "return address" labels.
    // (If Java allowed "goto" statements we could eliminate the
    // loop and just use labels and "goto" statements.)

    while (true) {
      switch(ra) {
       case 0: // base case test: go here when first entering the function
              if (k == 0 || k == n) {
                retvalue = 1;
                ra = 4; // drop down to end of function
                continue;
              }
              else { // base case failed; move on to next part
                ra = 1;
                continue;
              }
       case 1: // First recursive call to binom.
               // Note that we push a "2" for the return address
               stack.push(new Frame(n,k,2,temp1,temp2));
               n=n-1; k=k-1;ra=0;
               continue;
       case 2: // Second recursive call to binom.
               // Note that we push a "3" for the return address
               temp1 = retvalue; // save result from first recursive call
               stack.push(new Frame(n,k,3,temp1,temp2));
               n=n-1; ra=0;
               continue;
       case 3: // We just returned from the second recursive call.
               temp2 = retvalue; // save result from second recursive call
               retvalue = temp1+temp2;
                      // "fall through" to case 4
       case 4:
               if (stack.empty()) // Is this a top-level call? Then return:
                 return retvalue;
               else { // Not a top-level call, so pop framestack and
                      // go back to the appropriate return address:
                 Frame s = stack.pop();
                 n = s.n();      // restore values of all parameters
                 k = s.k();      //  and local variables
                 ra = s.ra();    // We'll go here next
                 temp1 = s.t1();
                 temp2 = s.t2();
                 continue;
               }
      }
    }
  }
}
