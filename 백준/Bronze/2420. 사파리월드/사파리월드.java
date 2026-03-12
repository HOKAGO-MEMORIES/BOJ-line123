import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long m = sc.nextLong();
		System.out.print(Math.abs(n - m));
        sc.close();
	}
}
