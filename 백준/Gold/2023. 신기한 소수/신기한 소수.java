import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        int[] primeNumber = {2, 3, 5, 7};
        for (int n : primeNumber)
            solve(1, n);

        System.out.println(sb);
    }

    static void solve(int cnt, int num) {
        if (cnt == N) {
            sb.append(num).append('\n');
            return;
        }

        for (int i = 1; i < 10; i += 2)
            if (isPrime(num * 10 + i)) solve(cnt + 1, num * 10 + i);
    }

    static boolean isPrime(int num) {
        int sqrt = (int)Math.sqrt(num);
        for (int i = 2; i <= sqrt; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

}
