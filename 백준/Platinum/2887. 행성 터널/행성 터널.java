import java.io.*;
import java.util.*;

public class Main {
	
	static class Planet {
		int id, x, y, z;
		Planet(int id, int x, int y, int z) {
			this.id = id;
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
	
	static class Edge implements Comparable<Edge> {
		int u, v, weight;
		Edge(int u, int v, int weight) {
			this.u = u;
			this.v = v;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Edge o) {
			return this.weight - o.weight;
		}
	}
	
	static ArrayList<Edge> edges = new ArrayList<>();
	static Planet[] planets;
	static int[] parents;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		planets = new Planet[N];
		
		parents = new int[N];
		for (int i = 0; i < N; i++)
			parents[i] = i;

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			planets[i] = new Planet(i, x, y, z);
		}
		
		System.out.println(solve(N));
	}
	
	static int solve(int N) {
		
		Arrays.sort(planets, (a, b) -> a.x - b.x);
		for (int i = 0; i < N - 1; i++) 
			edges.add(new Edge(planets[i].id, planets[i + 1].id, Math.abs(planets[i].x - planets[i + 1].x)));
		
		Arrays.sort(planets, (a, b) -> a.y - b.y);
		for (int i = 0; i < N - 1; i++) 
			edges.add(new Edge(planets[i].id, planets[i + 1].id, Math.abs(planets[i].y - planets[i + 1].y)));

		Arrays.sort(planets, (a, b) -> a.z - b.z);
		for (int i = 0; i < N - 1; i++) 
			edges.add(new Edge(planets[i].id, planets[i + 1].id, Math.abs(planets[i].z - planets[i + 1].z)));

		int ans = 0;
		Collections.sort(edges);
		for (Edge edge : edges) 
			if (union(edge.u, edge.v))	ans += edge.weight;
		
		return ans;
	}
	
	static boolean union(int a, int b) {
		a = find(a);
		b = find(b);
		
		if (a == b) return false;
		
		parents[b] = a;
		return true;
	}
	
	static int find(int x) {
		if (parents[x] == x) return x;
		return parents[x] = find(parents[x]);
	}
}