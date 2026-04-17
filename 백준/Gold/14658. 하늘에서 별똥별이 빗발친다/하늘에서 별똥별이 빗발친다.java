import java.io.*;
import java.util.*;

public class Main {
	
	static class Star {
		int x, y;
		Star(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static Star[] stars;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		stars = new Star[K];

		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			stars[i] = new Star(X, Y);
		}
		
		System.out.println(solve(N, M, L, K));
	}
	
	static int solve(int N, int M, int L, int K) {
		int ans = 0;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				ans = Math.max(ans, countStar(stars[i].x, stars[j].y, stars[i].x + L, stars[j].y + L));
			}
		}
		return K - ans;
	}
	
	static int countStar(int startX, int startY, int endX, int endY) {
		int sum = 0;
		for(Star star : stars) {
			if (star.x >= startX && star.x <= endX 
					&& star.y >= startY && star.y <= endY)
				sum++;
		}
		return sum;
	}
	
}
