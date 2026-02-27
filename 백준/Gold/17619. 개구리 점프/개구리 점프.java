import java.io.*;
import java.util.*;

public class Main {
	
	static class Node implements Comparable<Node> {
		int idx, x1, x2, y;
		Node (int idx, int x1, int x2, int y) {
			this.idx = idx;
			this.x1 = x1;
			this.x2 = x2;
			this.y = y;
		}
		
		@Override
		public int compareTo(Node o) {
			if (this.x1 == o.x1) {
				if (this.x2 == o.x2)
					return this.y - o.y;
				return o.x2 - this.x2;
			}
			return this.x1 - o.x1;
		}
	}
	
	static List<Node> list;
	static int[] parent;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		list = new ArrayList<>();

		parent = new int[N + 1];
		for (int i = 1; i <= N; i++)
			parent[i] = i;
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			list.add(new Node(i, x1, x2, y));
		}
		
		Collections.sort(list);		
		System.out.println(solve(N, Q));
	}
	
	static String solve(int N, int Q) throws IOException {
		StringBuilder sb = new StringBuilder();
		
		Node cur = list.remove(0);
		int maxX2 = cur.x2;
		int maxIdx = cur.idx;
		
		for (Node node : list) {
			if (maxX2 >= node.x1) {
				union(maxIdx, node.idx);
				maxX2 = Math.max(maxX2, node.x2);
			} else {
				maxX2 = node.x2;
				maxIdx = node.idx;
			}
		}
		
		while(Q-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			
			int ans = 0;
			if (find(start) == find(end))
				ans = 1;

			sb.append(ans).append('\n');
		}
		
		return sb.toString();
	}
	
	static int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	
	static void union(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			if (a < b) parent[b] = a;
			else parent[a] = b;
		}
	}
}
