import java.util.Scanner;
class Main
{
  public static void main(String[] args)
  {
    int[] p = new int[1000], s = new int[1000], vote = new int[1000];
    int n, m, ans = 0;
    Scanner scan = new Scanner(System.in);
    n = Integer.parseInt(scan.next());
    m = Integer.parseInt(scan.next());
    for(int i = 0; i < n; i++)
      p[i] = Integer.parseInt(scan.next());  
    for(int i = 0; i < m; i++)
    {
      s[i] = Integer.parseInt(scan.next());
      for(int j = 0; j < n; j++)
      {
        if(p[j] <= s[i])
        {
          vote[j]++;
          if(vote[j] > vote[ans])
            ans = j;
          break;
        }
      }
    }
    System.out.println(ans + 1);
  }
}
