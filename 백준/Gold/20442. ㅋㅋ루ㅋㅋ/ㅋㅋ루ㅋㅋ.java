import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int ans = solve(input);
        System.out.println(ans);
    }

    static int solve(String input) {
        int rCnt = getRCnt(input);
        List<Integer> leftK = checkLeftK(input);
        List<Integer> rightK = checkRightK(input);

        int ans = 0;
        int cnt = rCnt;
        int left = 0;
        int right = rCnt - 1;

        while (left <= right) {
            if (leftK.get(left) < rightK.get(right)) {
                ans = Math.max(ans, leftK.get(left) * 2 + cnt);
                left++;
            } else {
                ans = Math.max(ans, rightK.get(right) * 2 + cnt);
                right--;
            }
            cnt--;
        }

        return Math.max(ans, rCnt);
    }

    // R 개수 구하기
    static int getRCnt(String input) {
        int rCnt = 0;

        for (int i = 0; i < input.length(); i++)
            if (input.charAt(i) == 'R')
                rCnt++;

        return rCnt;
    }

    // R 기준 왼쪽에 있는 누적 K개수 구하기
    static List<Integer> checkLeftK(String input) {
        List<Integer> leftK = new ArrayList<>();

        int kCnt = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == 'R')
                leftK.add(kCnt);
            else
                kCnt++;
        }

        return leftK;
    }

    // R 기준 오른쪽에 있는 누적 K개수 구하기
    static List<Integer> checkRightK(String input) {
        List<Integer> rightK = new ArrayList<>();

        int kCnt = 0;
        for (int i = input.length() - 1; i >= 0; i--) {
            if (input.charAt(i) == 'R')
                rightK.add(kCnt);
            else
                kCnt++;
        }

        Collections.reverse(rightK);
        return rightK;
    }
}
