import java.util.Scanner;

public class Input {
   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);

      // 输入用户名
      System.out.println("请输入用户名：");
      String username = scanner.nextLine();
      Username(username);

      // 输入密码
      System.out.println("请输入密码：");
      String password = scanner.nextLine();
      Password(password);

      // 输入邮箱
      System.out.println("请输入邮箱：");
      String email = scanner.nextLine();
      Email(email);

      scanner.close();
   }

   // 验证用户名格式
   public static void Username(String username) {
      if(username.isEmpty()) {
         System.out.println("输入不能为空");
      } else if (username.matches("[0-9].*")) {
         System.out.println("第一个不能是数字");
      } else if (!username.matches("[a-zA-Z0-9_]+")) {
         System.out.println("用户名只能包含字母、数字和下划线");
      } else {
         System.out.println("输入格式正确");
      }
   }

   // 验证密码格式
   public static void Password(String password) {
      if(password.isEmpty()) {
         System.out.println("输入不能为空");
      } else if (password.length() < 8) {
         System.out.println("密码长度不能小于8");
      } else if (!password.matches("[a-zA-Z0-9_]+")) {
         System.out.println("密码只能包含字母、数字和下划线");
      } else {
         System.out.println("输入格式正确");
      }
   }

   // 验证邮箱格式
   public static void Email(String email) {
      if(email.isEmpty()) {
         System.out.println("输入不能为空");
      } else if (!email.matches(".+@.+\\..+")) {
         System.out.println("邮箱格式不正确");
      } else {
         System.out.println("输入格式正确");
      }

   }
}
