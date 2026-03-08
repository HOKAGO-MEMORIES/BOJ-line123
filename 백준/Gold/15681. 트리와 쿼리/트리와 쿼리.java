import java.io.*;
import java.util.*;

public class Main {
		
	private static ArrayList<Integer>[] list;
	private static int[] dp;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		
		dp = new int[N + 1];
		list = new ArrayList[N + 1];
		for(int i = 1; i < N + 1; i++) {
			list[i] = new ArrayList<>();
		}
		Arrays.fill(dp, 1);
		
		for (int i = 0; i < N - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int U = Integer.parseInt(st.nextToken());
			int V = Integer.parseInt(st.nextToken());
			
			list[U].add(V);
			list[V].add(U);
		}
		
		solve(R, -1);
		
		for (int i = 0; i < Q; i++) {
			int U = Integer.parseInt(br.readLine());
			sb.append(dp[U]).append('\n');
		}
		
		System.out.println(sb);
	}

	private static void solve(int idx, int parent) {
		for (int n : list[idx])
			if (parent != n)
				solve(n, idx);
		
		if (parent != -1)
			dp[parent] += dp[idx];			
	}
	
}
