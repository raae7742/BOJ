import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		Character[] result = new Character[n];
		for(int i=0; i<n; i++)
			result[i] = '?';
		int h = s.nextInt();
		int w = s.nextInt();
		
		String[] input = new String[h];
		for(int i=0; i<h; i++)
			input[i] = s.next();
		
		
		for(int i=0; i<h; i++) {
			for(int j=0; j<n; j++) {
				for(int k=0; k<w; k++) {
					if(input[i].charAt(j*w+k) != '?') result[j] =input[i].charAt(j*w+k);
				}
			}
		}
		
		for(int i=0; i<result.length; i++)
			System.out.print(result[i] + "");
	}

}
