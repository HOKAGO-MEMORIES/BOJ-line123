import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] input = new int[2][3];
        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++)
                input[i][j] = Integer.parseInt(st.nextToken());
        }

        int distance = (int)Math.sqrt(Math.pow(input[0][0] - input[1][0], 2) + Math.pow(input[0][1] - input[1][1], 2));
        int radiusSum = input[0][2] + input[1][2];

        if (radiusSum > distance) System.out.println("YES");
        else System.out.println("NO");
    }
}
