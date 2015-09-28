public class Looping {
    public static void main(String[] args) {

OUTER:
        for(int i = 1; i <= 5; i++) {
            for(int j = 1; j <=5; j++) {

                System.out.println("i= " + i + ",\t j= " + j);

                if(i + j == 3) {
                    break;
                }
                if(i + j == 8) {
                    break OUTER;
                }
            }
        }
    }
}
