import java.io.*;
import java.util.*;

public class Main {
		
	static class Edge implements Comparable<Edge>{
		int to, weight;
		Edge (int to, int weight) {
			this.to = to;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Edge o) {
			return this.weight - o.weight;
		}
	}
	
	static ArrayList<Edge>[] edges;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		edges = new ArrayList[N + 1];
		for (int i = 0; i <= N; i++)
			edges[i] = new ArrayList<>();
		
		while (M-- >= 0) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			
			C = (C == 0) ? 1 : 0;
			
			edges[A].add(new Edge(B, C));
			edges[B].add(new Edge(A, C));
		}

		PriorityQueue<Edge> pqMin = new PriorityQueue<>();
		int minCost = solve(pqMin, N);
		PriorityQueue<Edge> pqMax = new PriorityQueue<>(Collections.reverseOrder());
		int maxCost = solve(pqMax, N);
		
		System.out.println(maxCost - minCost);
	}
	
	static int solve(PriorityQueue<Edge> pq, int N) {	
		boolean[] visited = new boolean[N + 1];
		int result = 0;
		int cnt = 0;
		
		pq.add(new Edge(0, 0));
		
		while (!pq.isEmpty()) {
			Edge cur = pq.poll();
			
			if (visited[cur.to]) continue;
			
			visited[cur.to] = true;
			result += cur.weight;
		
			if (++cnt == N + 1) break; 
			
			for (Edge edge : edges[cur.to]) 
				if (!visited[edge.to])	pq.add(edge);
		}
		
		return result * result;
	}
	
}
