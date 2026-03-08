import java.io.*;
import java.util.*;

public class Main {
	
	private static int[] parent;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int A = 0;
		int B = 0;
		
		parent = new int[N + 1];
		for (int i = 1; i <= N; i++)
			parent[i] = i;
		
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			
			if (i == K) {
				A = u;
				B = v;
				continue;
			}
			
			union(u, v);
		}
		
		A = find(A);
		B = find(B);
		Long ans = 0L;
		
		if (A != B) {
			Long aCnt = 0L;
			Long bCnt = 0L;
			for (int i = 1; i <= N; i++) {
				int p = find(parent[i]);
				if (p == A) aCnt++;
				else bCnt++;
			}
			
			ans = aCnt * bCnt;
		}
		
		System.out.println(ans);
	}
	
	private static void union(int u, int v) {
		u = find(u);
		v = find(v);
		if (u != v) 
			if (u < v) parent[v] = u;
			else parent[u] = v;
	}
	
	private static int find(int n) {
		if (parent[n] == n) return n;
		return parent[n] = find(parent[n]);
	}
}
