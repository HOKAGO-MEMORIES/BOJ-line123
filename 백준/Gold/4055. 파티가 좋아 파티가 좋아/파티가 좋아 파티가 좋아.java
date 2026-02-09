import java.io.*;
import java.util.*;

public class Main {
	
	static class Party implements Comparable<Party> {
		int start, end;
		public Party (int start, int end) {
			this.start = start;
			this.end = end;
		}
		
		@Override
		public int compareTo(Party o) {
			if (this.end == o.end) return this.start - o.start;
			return this.end - o.end;
		}
	}
		
	static ArrayList<Party> parties;
	static String message = "On day %d Emma can attend as many as %d parties.\n";
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int cnt = 0;
		
		while (true) {
			int N = Integer.parseInt(br.readLine());
			
			if (N == 0) break;
		
			cnt++;
			parties = new ArrayList<>();
			
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				int start = Integer.parseInt(st.nextToken());
				int end = Integer.parseInt(st.nextToken());
				parties.add(new Party(start, end));
			}
			
			Collections.sort(parties);
			
			int ans = solve(N);
			sb.append(String.format(message, cnt, ans));
		}
				
		System.out.println(sb);
	}
	
	
//	static int solve(int N) {
//		int ans = 0;
//		for (int i = 8; i < 24; i++) {
//			for (int j = 0; j < 2; j++) {
//				for (int k = 0; k < parties.size(); k++) {
//					Party p = parties.get(k);
//					if (i >= p.start && i < p.end) {
//						ans++;
//						parties.remove(k);
//						break;
//					}
//				}
//				
//			}
//		}
//		
//		return ans;
//	}
	
	static int solve(int N) {
		int ans = 0;
		// 30분 단위로 기록
		boolean[] time = new boolean[32];
		
		for (Party p : parties) {
			int start = (p.start - 8) * 2;
			int end = (p.end - 8) * 2;
			
			for (int i = start; i < end; i++) {
				if (!time[i]) {
					time[i] = true;
					ans++;
					break;
				}
			}
		}
		
		return ans;
	}

}
