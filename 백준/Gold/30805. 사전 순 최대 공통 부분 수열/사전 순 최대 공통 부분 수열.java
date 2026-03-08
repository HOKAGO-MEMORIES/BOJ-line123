import java.io.*;
import java.util.*;

public class Main {
	
	private static int N, M;
	private static int[] A, B;
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		A = input();
		N = A.length;
		B = input();
		M = B.length;
		
		Queue<Integer> q = solve();
		sb.append(q.size()).append('\n');
		for (int num : q) 
			sb.append(num).append(" ");
		System.out.println(sb);
	}
	
	private static int[] input() throws IOException {
		int N = Integer.parseInt(br.readLine());
		int [] arr = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) 
			arr[i] = Integer.parseInt(st.nextToken());
		
		return arr;
	}
	
	private static Queue<Integer> solve() {
		int idxA = 0, idxB = 0;
		Queue<Integer> q = new ArrayDeque<>();
		
		while (idxA <= N && idxB <= M) {
			int maxInt = 0;
			
			for (int i = idxA ; i < N; i++) {
				for (int j = idxB; j < M; j++) {
					if (A[i] == B[j]) maxInt = Math.max(maxInt, A[i]);
				}
			}
			
			if (maxInt == 0)
				break;
			
			q.offer(maxInt);
			while(A[idxA] != maxInt) idxA++;
			while(B[idxB] != maxInt) idxB++;
			idxA++; idxB++;
		}
		
		return q;
	}
}
