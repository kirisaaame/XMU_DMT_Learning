import java.util.*;

public class Prime {
   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      System.out.print("请输入一个整数：");
      int number = scanner.nextInt();

      if (isPrime(number)) {
         System.out.println(number + " 是质数。");
      } else {
         Set<Integer> primeFactors = findPrimeFactors(number);
         System.out.println(number + " 不是质数，其质因子为：" + primeFactors);
      }
   }

   // 判断一个整数是否为质数
   private static boolean isPrime(int number) {
      if (number <= 1) {
         return false;
      }
      for (int i = 2; i <= Math.sqrt(number); i++) {
         if (number % i == 0) {
            return false;
         }
      }
      return true;
   }

   // 寻找一个整数的全部质因子
   private static Set<Integer> findPrimeFactors(int number) {
      Set<Integer> primeFactors = new HashSet<>();//HashSet除去重复的字母
      int n = number;

      for (int i = 2; i <= Math.sqrt(n); i++) {
         while (n % i == 0) {
            primeFactors.add(i);
            n /= i;
         }
      }

      // 若循环后得到的数不为1， n 也是一个质因子
      if (n > 1) {
         primeFactors.add(n);
      }

      return primeFactors;
   }
}
