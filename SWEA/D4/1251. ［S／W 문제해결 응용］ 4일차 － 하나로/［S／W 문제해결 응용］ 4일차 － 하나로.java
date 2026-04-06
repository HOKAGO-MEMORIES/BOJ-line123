import java.io.*;
import java.util.*;

public class Solution {
	
	static class Node implements Comparable<Node> {
		int to;
		long weight;
		
		Node(int to, long weight) {
			this.to = to;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Node o) {
			return Long.compare(this.weight, o.weight);
		}
	}
	
	static int N;
	static double E;
	static long[][] nodes;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
         
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
        	N = Integer.parseInt(br.readLine());

        	nodes = new long[N][2];
        	st = new StringTokenizer(br.readLine());
        	for (int i = 0; i < N; i++) 
        		nodes[i][0] = Long.parseLong(st.nextToken());
        	
        	st = new StringTokenizer(br.readLine());
        	for (int i = 0; i < N; i++) 
        		nodes[i][1] = Long.parseLong(st.nextToken());

        	E = Double.parseDouble(br.readLine());
            sb.append("#").append(test_case).append(" ").append(solve()).append('\n');
        }
         
        System.out.println(sb);
    }
    
    static long solve() {
    	boolean[] visited = new boolean[N];
    	PriorityQueue<Node> pq = new PriorityQueue<>();
    	
    	pq.offer(new Node(0, 0));
    	
    	long sum = 0;
    	int cnt = 0;
    	
    	while (!pq.isEmpty()) {
    		Node cur = pq.poll();
    		if (visited[cur.to]) continue;
    		
    		visited[cur.to] = true;
    		sum += cur.weight;
    		
    		if (++cnt == N) break;
    		
    		for (int i = 0; i < N; i++) {
    			if (!visited[i]) {
                    long dist = getDistance(nodes[cur.to][0], nodes[i][0], nodes[cur.to][1], nodes[i][1]);
                    pq.offer(new Node(i, dist));
                }
    		}
    	}

    	return Math.round(sum * E);
    }
    
    static long getDistance(long x1, long x2, long y1, long y2) {
    	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
}
