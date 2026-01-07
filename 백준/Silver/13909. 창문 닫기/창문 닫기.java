import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        long N = Integer.parseInt(br.readLine());
        long result = (long) Math.sqrt(N);
        System.out.println(result);
    }
}
