import java.io.*;
import java.util.*;

public class Main {
	
	private static long MOD = 1000000007L;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine());
		
		long total = 0;
		
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			long N = Long.parseLong(st.nextToken()); 
            long S = Long.parseLong(st.nextToken());
            
            long powResult = pow(N, MOD - 2);
            long expectedResult = (S * powResult) % MOD;
            
            total = (total + expectedResult) % MOD;
		}	
		
		System.out.println(total);
	}
	
	private static long pow(long num, long exp) {
		long result = 1;
		num %= MOD;
		
		while (exp > 0) {
			if ((exp & 1) == 1)
				result = (result * num) % MOD;
			num = (num * num) % MOD; 
			exp >>= 1;
		}
		
		return result;
	}

}
