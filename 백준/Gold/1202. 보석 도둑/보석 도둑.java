import java.io.*;
import java.util.*;

public class Main {

    static class Jewel implements Comparable<Jewel> {
        int weight, price;
        Jewel(int weight, int price) {
            this.weight = weight;
            this.price = price;
        }

        @Override
        public int compareTo(Jewel o) {
            if (this.weight == o.weight) return o.price - this.price;
            return this.weight - o.weight;
        }
    }

    static class Bag implements Comparable<Bag> {
        int maxWeight;
        Bag(int maxWeight) {
            this.maxWeight = maxWeight;
        }

        @Override
        public int compareTo(Bag o) {
            return this.maxWeight - o.maxWeight;
        }
    }

    static int N, K;
    static List<Jewel> jewels = new ArrayList<>();
    static List<Bag> bags = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            jewels.add(new Jewel(m, v));
        }
        Collections.sort(jewels);

        for (int i = 0; i < K; i++) {
            int c = Integer.parseInt(br.readLine());
            bags.add(new Bag(c));
        }
        Collections.sort(bags);

        System.out.println(solve());
    }

    static long solve() {
        long ans = 0;
        int idx = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (Bag bag : bags) {
            while (idx < N && jewels.get(idx).weight <= bag.maxWeight) {
                pq.offer(jewels.get(idx).price);
                idx++;
            }

            if (!pq.isEmpty())
                ans += pq.poll();
        }

        return ans;
    }
}
