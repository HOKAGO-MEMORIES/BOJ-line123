import java.io.*;
import java.util.*;

public class Main {
	
	static int N, ans;
	static int[] graph;
	static boolean[] visited, selected;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			N = Integer.parseInt(br.readLine());
			graph = new int[N + 1];
			visited = new boolean[N + 1];
			selected = new boolean[N + 1];
						
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= N; i++) 
				graph[i] = Integer.parseInt(st.nextToken());
						
			ans = 0;
			for (int i = 1; i <= N; i++)
				if(!visited[i])	solve(i);

			sb.append(N - ans).append('\n');
		}
		
		System.out.println(sb);
	}
	
	static void solve(int cur) {
		visited[cur] = true;
		int next = graph[cur];
		
		if (!visited[next])
			solve(next);
		else if (!selected[next]) {
			for (int i = next; i != cur; i = graph[i])
				ans++;
			ans++;	
		}
		selected[cur] = true;

	}
}
