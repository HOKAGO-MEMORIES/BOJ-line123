import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int time = 0;
        int min = m;

        if (m + T > M) {
            time = -1;
        } else {
            while (N > 0) {
                if (m + T <= M) {
                    m += T;
                    N--;
                } else {
                    m -= R;
                    if (m < min) {
                        m = min;
                    }
                }
                time++;
            }
        }

        System.out.println(time);
    }
}
