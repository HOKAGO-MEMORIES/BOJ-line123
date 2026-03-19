import java.io.*;
import java.util.*;

public class Main {

    static class Student implements Comparable<Student> {
        int room, idx, weight;
        Student(int room, int idx, int weight) {
            this.room = room;
            this.idx = idx;
            this.weight = weight;
        }

        @Override
        public int compareTo(Student o) {
            return o.weight - this.weight;
        }
    }

    static int N, M, minNum = Integer.MAX_VALUE;
    static Integer[][] arr;
    static PriorityQueue<Student> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new Integer[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr[i], Collections.reverseOrder());
        }

        for (int i = 0; i < N; i++) {
            pq.add(new Student(i, 0, arr[i][0]));
            minNum = Math.min(minNum, arr[i][0]);
        }

        System.out.println(solve());
    }

    static int solve() {
        int ans = Integer.MAX_VALUE;
        while (!pq.isEmpty()) {
            Student cur = pq.poll();
            ans = Math.min(ans, cur.weight - minNum);

            if (cur.idx == M - 1) break;
            int next = arr[cur.room][cur.idx + 1];
            minNum = Math.min(minNum, next);
            pq.add(new Student(cur.room, cur.idx + 1, next));
        }

        return ans;
    }
}
