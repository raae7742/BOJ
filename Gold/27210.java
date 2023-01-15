import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int n;
		n = sc.nextInt();

        int dir[] = new int[n];
		int dp1[] = new int[n];
		int dp2[] = new int[n];
		int dp1Max = 1, dp2Max = 1;
		
        for (int i = 0; i < n; i++) {
            dir[i] = sc.nextInt();
        }
        
        if (dir[0] == 1) {
        	dp1[0] = 1;
        	dp2[0] = 0;
        }
        else {
        	dp1[0] = 0;
        	dp2[0] = 1;
        }
        
        for (int i = 1; i < n; i++) {
        	if (dir[i] == 1) {
        		dp1[i] = (dp1[i-1] + 1 > 1) ? dp1[i-1] + 1 : 1;
        		dp2[i] = dp2[i-1] - 1;
        		
        		if (dp1[i] > dp1Max) dp1Max = dp1[i];
        	}
        	else {
        		dp1[i] = dp1[i-1] - 1;
        		dp2[i] = (dp2[i-1] + 1 > 1) ? dp2[i-1] + 1 : 1;
        		
        		if (dp2[i] > dp2Max) dp2Max = dp2[i];
        	}
        }
        
        if (dp1Max > dp2Max) System.out.println(dp1Max);
        else System.out.println(dp2Max);
	}
}
