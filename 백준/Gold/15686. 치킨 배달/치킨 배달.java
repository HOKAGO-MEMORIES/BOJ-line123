import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int result = Integer.MAX_VALUE;
    static ArrayList<Point> homes = new ArrayList<>();
    static ArrayList<Point> chickens = new ArrayList<>();
    static boolean[] open;

    static class Point {
        int r, c;
        Point(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                int value = Integer.parseInt(st.nextToken());
                if (value == 1) {
                    homes.add(new Point(i, j));
                } else if (value == 2) {
                    chickens.add(new Point(i, j));
                }
            }
        }

        open = new boolean[chickens.size()];
        dfs(0, 0);

        System.out.println(result);
    }

    static void dfs(int start, int count)  {
        if (count == M) {
            calculateDistance();
            return;
        }

        for (int i = start; i < chickens.size(); i++) {
            open[i] = true;
            dfs(i + 1, count + 1);
            open[i] = false;
        }
    }

    static void calculateDistance() {
        int distance = 0;

        for (Point home : homes) {
            int minDistance = Integer.MAX_VALUE;

            for (int i = 0; i < chickens.size(); i++) {
                if (open[i]) {
                    int dist = Math.abs(home.r - chickens.get(i).r) + Math.abs(home.c - chickens.get(i).c);
                    minDistance = Math.min(minDistance, dist);
                }
            }

            distance += minDistance;
        }

        result = Math.min(result, distance);
    }
}
