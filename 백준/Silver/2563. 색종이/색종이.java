import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int ans = 0;
        boolean[][] visited = new boolean[101][101];

        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());

            for (int i = X; i < X + 10; i++) {
                for (int j = Y; j < Y + 10; j++) {
                    if (!visited[i][j]) {
                        visited[i][j] = true;
                        ans++;
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
