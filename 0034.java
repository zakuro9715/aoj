import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
	Scanner sc = new Scanner(System.in);
	while(sc.hasNext())
	{
	    String line = sc.next();
	    String[] s = line.split(",");
	    int sum = 0;
	    for(String v : s)
		sum += Integer.parseInt(v);
	    int l = 0;
	    for(int i = 0; i < s.length; i++)
	    {
		l += Integer.parseInt(s[i]);
		if(l >= sum /)
		{
		    System.out.println(i + 1);
		    break;
		}
	    }
	}
    }
}
