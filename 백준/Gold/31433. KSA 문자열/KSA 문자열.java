import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String X = br.readLine();
        System.out.println(solve(X));
    }

    static int solve(String X) {
        int ans = Math.max(Math.max(findString(X, "KSA"), findString(X, "SAK") - 1), findString(X, "AKS") - 2);
        return (X.length() - ans) * 2;
    }

    static int findString(String a, String b) {
        int cnt = 0;
        for (char c : a.toCharArray())
            if (c == b.charAt(cnt % 3)) cnt++;

        return cnt;
    }
}
