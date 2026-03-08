import java.io.*;
import java.util.*;

public class Main {
		
	private static int N;
	private static int[] arr;
	private static int[][] dp;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		while (T-- > 0) {
			N = Integer.parseInt(br.readLine());
			arr = new int[N];
			dp = new int[N][N];
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
				arr[i] = Integer.parseInt(st.nextToken());
			
			solve(0, 0, N - 1);
			
			sb.append(dp[0][N - 1]).append('\n');
		}
		
		System.out.println(sb);
	}
	
	private static int solve(int cnt, int left, int right) {
		if (cnt == N)	return 0;
		if (dp[left][right] != 0) return dp[left][right];
		
		if (cnt % 2 == 0) 
			return dp[left][right] = Math.max(arr[left] + solve(cnt + 1, left + 1, right), 
					arr[right] + solve(cnt + 1, left, right - 1));
		else
			return dp[left][right] = Math.min(solve(cnt + 1, left + 1, right), 
					solve(cnt + 1, left, right - 1));
		
		
	}
	
}
