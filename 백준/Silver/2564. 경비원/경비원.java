import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<Integer> road;
    static int N, M, S, startPos, ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 북서쪽에서 끊어져서 일자로 이음, 서쪽 맨 위가 첫 번째 지점, 북쪽 맨 왼쪽이 마지막 지점
        road = new ArrayList<>();

        S = Integer.parseInt(br.readLine());
        for (int i = 0; i <= S; i++) {
            st = new StringTokenizer(br.readLine());
            int dir = Integer.parseInt(st.nextToken());
            int dis = Integer.parseInt(st.nextToken());
            int curPos = 0;

            // 1: 북, 2: 남, 3: 서, 4: 동
            switch (dir) {
                case 1:
                    curPos = N + (M * 2) + (N - dis);
                    break;
                case 2:
                    curPos = M + dis;
                    break;
                case 3:
                    curPos = dis;
                    break;
                case 4:
                    curPos = N + M + (M - dis);
                    break;
            }

            if (i == S)
                startPos = curPos;
            else
                road.add(curPos);

        }

        solve();
        System.out.println(ans);
    }

    static void solve() {
        int total = (N + M) * 2;
        int left = 0, right = 0;
        for (int store : road) {
            if (startPos > store) {
                left = startPos - store;
                right = (total - startPos) + store;
            } else {
                left = startPos + (total - store);
                right = store - startPos;
            }

            ans += Math.min(left, right);
        }
    }

}
