import java.io.*;
import java.util.*;

public class Main {

	private static final int INF = Integer.MAX_VALUE;
	private static int n, m, r;
	private static int[][] graph;
	private static int[] items;
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws IOException {
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		graph = new int[n + 1][n + 1];
		items = new int[n + 1];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			int item = Integer.parseInt(st.nextToken()); 
			items[i] = item;
			
			for (int j = 1; j <= n; j++) {
				if (i == j) graph[i][j]= 0;
				else graph[i][j] = INF;
			}		
		}
				
		settingGraph();
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = Math.max(ans, solve(i));
		
		System.out.println(ans);
	}
	
	private static void settingGraph() throws IOException {
		for (int i = 0; i < r; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			
			graph[a][b] = graph[b][a] = l;
		}
		
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (graph[i][k] == INF || graph[k][j] == INF) continue;
					graph[i][j] = Math.min(graph[i][j], 
							graph[i][k] + graph[k][j]);
				}
			}
		}
	}
	
	private static int solve(int start) {
		int result = 0;
		
		for (int end = 1; end <= n; end++) 
			if (graph[start][end] <= m) result += items[end]; 
					
		return result;
	}
}
