import java.io.*;
import java.util.*;

public class Main {
		
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		double[][] arr = new double[N][2];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Double.parseDouble(st.nextToken());
			arr[i][1] = Double.parseDouble(st.nextToken());
			
		}
		
		double sum = 0;
		
		for (int i = 0; i < N; i++) {
			sum += arr[i][0] * arr[(i + 1) % N][1];
			sum -= arr[i][1] * arr[(i + 1) % N][0];
		}
		
		System.out.printf("%.1f", Math.abs(sum / 2));
	}
	
}
