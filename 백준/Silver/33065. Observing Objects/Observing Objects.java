import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    private static final StringBuilder sb = new StringBuilder();
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static class Color {
        int R, G, B;

        Color (int R, int G, int B) {
            this.R = R;
            this.G = G;
            this.B = B;
        }

        public boolean isSame(Color color) {
            if (color == null) return false;
            return this.R == color.R && this.G == color.G && this.B == color.B;
        }
    }

    public static class Node {
        int X, Y;

        Node (int X, int Y) {
            this.X = X;
            this.Y = Y;
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Color[][] map = new Color[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < M; j++) {
                int R = Integer.parseInt(st.nextToken());
                int G = Integer.parseInt(st.nextToken());
                int B = Integer.parseInt(st.nextToken());

                map[i][j] = new Color(R, G, B);
            }
        }

        solve(N, M, map);
        System.out.println(sb);
        br.close();
    }

    public static void solve(int N, int M, Color[][] map) throws IOException {
        boolean[][] visited = new boolean[N][M];
        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j]) {
                    bfs(i, j, N, M, map, visited);
                    count++;
                }
            }
        }

        sb.append(count);
    }

    public static void bfs(int x, int y, int N, int M, Color[][] map, boolean[][] visited) {
        Deque<Node> deq = new ArrayDeque<>();
        deq.add(new Node(x, y));
        visited[x][y] = true;

        int[] dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        int[] dy = {0, -1, -1, -1, 0, 1, 1, 1};

        while (!deq.isEmpty()) {
            Node now = deq.poll();

            for (int i = 0; i < 8; i++) {
                int nx = now.X + dx[i];
                int ny = now.Y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (!visited[nx][ny] && map[now.X][now.Y].isSame(map[nx][ny])) {
                    visited[nx][ny] = true;
                    deq.push(new Node(nx, ny));
                }
            }

        }
    }
}
