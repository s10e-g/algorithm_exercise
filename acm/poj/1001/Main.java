import java.util.*;
import java.math.BigDecimal;

public class Main {
    private static Scanner in;

	public static void main(String[] args) {
        in = new Scanner(System.in);
        while(in.hasNext()){
        	BigDecimal base = in.nextBigDecimal();
        	int exp = in.nextInt();
        	BigDecimal res = base.pow(exp).stripTrailingZeros();
        	System.out.println(res.toPlainString().replaceAll("^0", ""));
        }
    }
}
