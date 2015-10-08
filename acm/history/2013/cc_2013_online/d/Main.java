import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int t, tn;

        t = cin.nextInt();

        for(int i = 0; i < t; i++){
            BigInteger m = new BigInteger(String.valueOf(cin.nextInt()));

            tn = cin.nextInt();
            BigInteger n = new BigInteger(String.valueOf(tn));

            m = m.pow(tn-1);

            BigInteger gcd = m.gcd(n);
            m = m.divide(gcd);
            n = n.divide(gcd);

            System.out.print(n);
            System.out.print('/');
            System.out.println(m);
        }
    }
}
