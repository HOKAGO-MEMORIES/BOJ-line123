import java.io.*;
import java.util.*;

public class Main {
		
	static int[] arr;
	static int N;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		System.out.println(solve());
	}
	
	static String solve() {
		int sum = 0;
		int cntOne = 0, cntTwo = 0;
		
		for (int num : arr) {
			sum += num;
			cntOne += num % 2;
			cntTwo += num / 2;
		}
		
		if (sum % 3 != 0) return "NO";
		else if (cntOne > cntTwo) return "NO";
		return "YES";
	}
	
}
