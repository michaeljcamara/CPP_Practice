// Bob Roos
// Another example
public class JVMExample {
  public void f(int i, int j) {
    int x,y,rem;
    double avg;
    x = i*j;
    y = i+j;
    rem = x%y;
    avg = (x+y)/2.0;
  }
  public void g() {
    int a = 10, b = 20;
    f(a,b);
  }
}
