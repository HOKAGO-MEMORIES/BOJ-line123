import java.io.*;
import java.util.*;

public class Main {

    static class Ballon implements Comparable<Ballon> {
        int amount, disA, disB;
        Ballon(int amount, int disA, int disB) {
            this.amount = amount;
            this.disA = disA;
            this.disB = disB;
        }

        @Override
        public int compareTo(Ballon o) {
            int diff1 = Math.abs(this.disA - this.disB);
            int diff2 = Math.abs(o.disA - o.disB);
            return diff2 - diff1;
        }
    }

    static List<Ballon> ballons;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            if (A == 0 && B == 0 && N == 0) break;

            ballons = new ArrayList<>();
            while (N-- > 0) {
                st = new StringTokenizer(br.readLine());
                int K = Integer.parseInt(st.nextToken());
                int DA = Integer.parseInt(st.nextToken());
                int DB = Integer.parseInt(st.nextToken());
                ballons.add(new Ballon(K, DA, DB));
            }

            // A와 B의 거리차가 큰 순서대로 정렬
            Collections.sort(ballons);
            sb.append(solve(A, B)).append('\n');
        }

        System.out.println(sb);
    }

    static long solve(int A, int B) {
        long ans = 0;
        for (Ballon ballon : ballons) {
            if (ballon.disA < ballon.disB) {
                int takeA = Math.min(A, ballon.amount); // A애서 가져갈 풍선
                int takeB = ballon.amount - takeA;      // 모자란 만큼은 B에서 가져감

                ans += (takeA * ballon.disA) + (takeB * ballon.disB);
                A -= takeA;
                B -= takeB;
            } else {
                int takeB = Math.min(B, ballon.amount);
                int takeA = ballon.amount - takeB;

                ans += (takeA * ballon.disA) + (takeB * ballon.disB);
                A -= takeA;
                B -= takeB;
            }
        }

        return ans;
    }

}
