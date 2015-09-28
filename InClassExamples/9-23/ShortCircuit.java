public class ShortCircuit {
    public static void main(String[] args) {

        int i = 10, j = 1;

        if(i > 10 && 10/(++j) < 3) {
            System.out.println("then");
        }
        else {
            System.out.println("else");
        }

        System.out.println("j = " + j);
    }
}
