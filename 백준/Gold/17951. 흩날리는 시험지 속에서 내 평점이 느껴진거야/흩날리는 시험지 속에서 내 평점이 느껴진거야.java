import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, K, total;
	private static int[] test;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		test = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			test[i] = Integer.parseInt(st.nextToken());
			total += test[i];
		}
		
		System.out.println(solve());
	}
	
	private static int solve() {
		int left = 0;
		int right = total;
		int ans = 0;
		
		while (right >= left) {
			int mid = (left + right) / 2; 
			int sum = 0;
			int cnt = 0;
			
			for (int num : test) {
				sum += num;
				
				if (sum >= mid) {
					cnt++;
					sum = 0;
				}				
			}
			
			if (cnt >= K) {
				left = mid + 1;
				ans = mid;
			}
			else right = mid - 1;
		}
		
		return ans;
	}
	
}
