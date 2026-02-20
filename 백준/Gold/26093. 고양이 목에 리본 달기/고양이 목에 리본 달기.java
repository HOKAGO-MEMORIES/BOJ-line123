import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] graph;
	static int N, K;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		graph = new int[N][K];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < K; j++) 
				graph[i][j] = Integer.parseInt(st.nextToken());
		}
		
		int ans = solve();
		System.out.println(ans);
	}
	
	static int solve() {
		int[][] dp = new int[N][K];
		
		// 첫 번째 고양이
		for (int j = 0; j < K; j++) 
			dp[0][j] = graph[0][j];
		
		// 두 번째 고양이 부터..
		for (int i = 1; i < N; i++) {
			int first = 0;
			int firstIdx = 0;
			int second = 0;
			
			// 1등, 2등 구하기
			for (int j = 0; j < K; j++) {
				int value = dp[i - 1][j];
				
				if (value > first) {
					second = first;
					first = value;
					firstIdx = j;
				} else if (value > second) {
					second = value;
				}
			}
			
			// 1등 인덱스와 같다면 2등의 값으로, 아니라면 1등 값으로
			// 2등 인덱스는 연산 시 필요하지 않음
			for (int j = 0; j < K; j++) {
				if (firstIdx == j) 	dp[i][j] = graph[i][j] + second;
				else	dp[i][j] = graph[i][j] + first;
			}
		}
		
		int ans = Integer.MIN_VALUE;
		for (int j = 0; j < K; j++) 
			ans = Math.max(ans, dp[N - 1][j]);
		return ans;
	}

}
