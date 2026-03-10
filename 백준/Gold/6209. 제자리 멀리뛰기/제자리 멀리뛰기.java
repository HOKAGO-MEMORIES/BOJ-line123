import java.io.*;
import java.util.*;

public class Main {
	
	static int d, n, m;
	static int[] rocks;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		d = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		rocks = new int[n + 1];
		for (int i = 1; i <= n; i++) 
			rocks[i] = Integer.parseInt(br.readLine());
		Arrays.sort(rocks);
				
		System.out.println(solve());
	}
	
	static int solve() {	
		int ans = 0;
		int left = 0;
		int right = d;
		
		while (left <= right) {
			int mid = (left + right) / 2;
			int idx = 0;
			int cnt = 0;
			
			// 최소거리 찾기
			for (int i = 1; i <= n; i++) {
				// 돌섬 제거하면서 계산
				if (mid <= rocks[i] - rocks[idx])
					idx = i;
				else 
					cnt++;
			}
			
			// cnt가 m을 넘어서면 최소거리가 아님
			if (cnt > m)
				right = mid - 1;
			else {
				ans = mid;
				left = mid + 1;
			}
		}
		
		return ans;
	}
	
}
