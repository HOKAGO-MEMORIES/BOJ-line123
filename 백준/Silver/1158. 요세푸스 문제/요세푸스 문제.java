import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        ArrayDeque<Integer> q = new ArrayDeque<>();

        for (int i = 1; i <= N; i++)
            q.add(i);

        StringBuilder sb = new StringBuilder();
        sb.append("<");

        while (!q.isEmpty()) {
            for (int i = 1; i < K; i++)
                q.add(q.pop());

            sb.append(q.pop());

            if (!q.isEmpty())
                sb.append(", ");
        }

        sb.append(">");

        System.out.println(sb);
    }
}
