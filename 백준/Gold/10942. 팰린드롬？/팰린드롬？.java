import java.util.*;
import java.io.*;

public class Main {

    static int[][] isPalindrome;
    static int[] numbers;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        numbers = new int[N + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            numbers[i] = Integer.parseInt(st.nextToken());

        checkPalindrome(N);

        int M = Integer.parseInt(br.readLine());
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            sb.append(isPalindrome[S][E]).append('\n');
        }

        System.out.println(sb);
    }

    static void checkPalindrome(int N) {
        isPalindrome = new int[N + 1][N + 1];

        // 길이 1
        for (int i = 1; i <= N; i++)
            isPalindrome[i][i] = 1;

        // 길이 2
        for (int i = 1; i <= N - 1; i++)
            if(numbers[i] == numbers[i + 1])
                isPalindrome[i][i + 1] = 1;

        // 길이 3+
        for (int i = N - 2; i >= 1; i--)
            for (int j = i + 2; j <= N; j++)
                if (numbers[i] == numbers[j] && isPalindrome[i + 1][j - 1] == 1)
                    isPalindrome[i][j] = 1;
    }
}
