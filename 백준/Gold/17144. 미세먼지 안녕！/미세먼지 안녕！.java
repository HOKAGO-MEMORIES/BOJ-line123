import java.io.*;
import java.util.*;

public class Main {

    private static int R, C, upper, lower;
    private static int[][] room;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        room = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                room[i][j] = Integer.parseInt(st.nextToken());
                if (room[i][j] == -1)
                    if (upper == 0) upper = i;
                    else lower = i;
            }
        }

        while (T-- > 0) {
            spreadVirus();
            cleanAir();
        }

        int ans = 2;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans += room[i][j];

        System.out.println(ans);
    }

    private static void spreadVirus() {
        int [][] virus = new int[R][C];
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (room[i][j] > 0) {
                    int v = room[i][j] / 5;
                    int cnt = 0;

                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx >= 0 && ny >= 0 && nx < R && ny < C && room[nx][ny] != -1) {
                            virus[nx][ny] += v;
                            cnt++;
                        }
                    }

                    if (cnt > 0)
                        room[i][j] = room[i][j] - (room[i][j] / 5) * cnt;
                }
            }
        }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (room[i][j] != -1)   room[i][j] += virus[i][j];
    }

    private static void cleanAir() {
        for (int i = upper - 1; i > 0; i--)
            room[i][0] = room[i - 1][0];

        for (int j = 0; j < C - 1; j++)
            room[0][j] = room[0][j + 1];

        for (int i = 0; i < upper; i++)
            room[i][C - 1] = room[i + 1][C - 1];

        for (int j = C - 1; j > 1; j--)
            room[upper][j] = room[upper][j - 1];

        for (int i = lower + 1; i < R - 1; i++)
            room[i][0] = room[i + 1][0];

        for (int j = 0; j < C - 1; j++)
            room[R - 1][j] = room[R - 1][j + 1];

        for (int i = R - 1; i > lower; i--)
            room[i][C - 1] = room[i - 1][C - 1];

        for (int j = C - 1; j > 0; j--)
            room[lower][j] = room[lower][j - 1];

        room[upper][1] = room[lower][1] = 0;
    }
}
