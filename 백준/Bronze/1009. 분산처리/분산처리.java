import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int ans = a % 10;

            for (int i = 1; i < b; i++)
                ans = ans * a % 10;

            if (ans == 0) ans = 10;
            sb.append(ans).append('\n');
        }

        System.out.println(sb);
    }
}
