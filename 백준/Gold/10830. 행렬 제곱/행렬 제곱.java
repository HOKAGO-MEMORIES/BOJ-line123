import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[][] origin;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        long B = Long.parseLong(st.nextToken());

        origin = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                origin[i][j] = Integer.parseInt(st.nextToken()) % 1000;
            }
        }

        int[][] result = solve(origin, B);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(result[i][j]).append(" ");
            }
            sb.append('\n');
        }

        System.out.println(sb);
    }

    private static int[][] solve(int[][] matrix, long exp) {
        if (exp == 1)
            return matrix;

        int[][] tmp = solve(matrix, exp / 2);
        tmp = multiply(tmp, tmp);

        if (exp % 2 == 1L) {
            tmp = multiply(tmp, origin);
        }

        return tmp;
    }

    private static int[][] multiply(int[][] m1, int[][] m2) {
        int[][] tmp = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    tmp[i][j] += m1[i][k] * m2[k][j];
                    tmp[i][j] %= 1000;
                }
            }
        }

        return tmp;
    }

}
