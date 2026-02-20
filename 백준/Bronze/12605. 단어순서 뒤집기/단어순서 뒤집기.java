import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; i++) {
            sb.append("Case #").append(i).append(": ");

            Deque<String> dq = new ArrayDeque<>();
            String[] input = br.readLine().split(" ");
            for (String s : input)
                dq.push(s);

            dq.forEach(s -> {
                sb.append(s).append(" ");
            });

            sb.append('\n');
        }

        System.out.println(sb);
    }
}
