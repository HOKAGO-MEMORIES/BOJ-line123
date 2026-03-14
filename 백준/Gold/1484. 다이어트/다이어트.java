import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int G = Integer.parseInt(br.readLine());
        System.out.println(solve(G));
    }

    static String solve(int G) {
        ArrayList<Long> result = new ArrayList<>();

        long A = 1, B = 1;
        while (true) {
            if (A * A - B * B == G) result.add(A);

            if (A * A - B * B > G) {
                if (A - B == 1) break;
                else B++;
            }
            else A++;
        }

        if (result.isEmpty()) return "-1";
        else return result.stream()
                .map(String::valueOf)
                .collect(Collectors.joining("\n"));
    }
}
