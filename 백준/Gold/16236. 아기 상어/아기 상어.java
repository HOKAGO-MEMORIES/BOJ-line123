import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int x, y, dist;
        Node(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }

        @Override
        public int compareTo(Node o) {
            if (this.dist != o.dist) return this.dist - o.dist;
            if (this.x != o.x) return this.x - o.x;
            return this.y - o.y;
        }
    }

    static int N, ans, sharkX, sharkY, sharkSize = 2, eatCnt;
    static int[][] graph;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        graph = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
                if (graph[i][j] == 9) {
                    sharkX = i;
                    sharkY = j;
                    graph[i][j] = 0;
                }
            }
        }

        solve();
        System.out.println(ans);
    }

    static void solve() {
        while (true) {
            Node fish = bfs();

            if (fish == null)
                break;

            eatCnt++;
            graph[fish.x][fish.y] = 0;
            ans += fish.dist;

            sharkX = fish.x;
            sharkY = fish.y;

            if (eatCnt == sharkSize) {
                sharkSize++;
                eatCnt = 0;
            }
        }

    }

    static Node bfs() {
        boolean[][] visited = new boolean[N][N];
        visited[sharkX][sharkY] = true;
        PriorityQueue<Node> q = new PriorityQueue<>();
        q.offer(new Node(sharkX, sharkY, 0));

        while (!q.isEmpty()) {
            Node cur = q.poll();

            if (graph[cur.x][cur.y] != 0 && graph[cur.x][cur.y] < sharkSize)
                return cur;

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    if (!visited[nx][ny] && graph[nx][ny] <= sharkSize) {
                        visited[nx][ny] = true;
                        q.offer(new Node(nx, ny, cur.dist + 1));
                    }
                }
            }
        }

        return null;
    }

}
