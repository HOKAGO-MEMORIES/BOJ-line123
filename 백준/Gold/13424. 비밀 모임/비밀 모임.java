import java.io.*;
import java.util.*;

public class Main {
	
	static int[] person;
	static int[][] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			graph = new int[N + 1][N + 1];
			for (int i = 1; i <= N; i++) 
				for (int j = 1; j <= N; j++)
					if(i != j) graph[i][j] = 1000000;
				
			
			while (M-- > 0) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				graph[a][b] = c;
				graph[b][a] = c;
			}
			
			int K = Integer.parseInt(br.readLine());
			person = new int[K];
			
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < K; i++)
				person[i] = Integer.parseInt(st.nextToken());
			
			sb.append(solve(N)).append('\n');
		}
		
		System.out.println(sb);
	}
	
	static int solve(int N) {	
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
		
		int ans = 0;
		int minSum = Integer.MAX_VALUE;
		
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int p : person) 
				sum += graph[p][i];
			
			if (sum < minSum) {
				minSum = sum;
				ans = i;
			}
		}
		
		return ans;
	}
	
}
