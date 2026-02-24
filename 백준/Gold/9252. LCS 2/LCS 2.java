import java.io.*;

public class Main {

    static int[][] LCS;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();

        String ans = solve(s1, s2);
        System.out.println(ans);
    }

    static String solve(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        LCS = new int[len1 + 1][len2 + 1];

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = Math.max(LCS[i - 1][j], LCS[i][j - 1]);

            }
        }

        StringBuilder sb = new StringBuilder();
        int i = len1;
        int j = len2;
        while (i > 0 && j > 0) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                sb.append(s1.charAt(i - 1));
                i--;
                j--;
            } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return String.valueOf(LCS[len1][len2]) + '\n' + sb.reverse().toString();
    }
}
