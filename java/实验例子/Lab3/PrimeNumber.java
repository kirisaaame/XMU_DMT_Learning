import java.util.Scanner;

public class PrimeNumber {
    public static boolean Isprimel(int x){
        boolean flag=true;
        for(int j=2;j<=Math.sqrt(x);j++){
          if(x%j==0)
          {
              flag=false;
              break;
          }
        }
        return flag;
    }
    public static void main(String[] args){
    Scanner scan=new Scanner(System.in);
    for(int i=1;i<10000;i++){
        if(Isprimel(i))
        {
            System.out.println(i);
        }
     }
    }
}
