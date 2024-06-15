import java.util.Scanner;

public class AgainException {
    public static void main(String[] args) {
        try {
            System.out.println("请输入一个自然数：");
            Scanner scanner = new Scanner(System.in);
            int a = scanner.nextInt();
            someMethod(a);
        } catch (RuntimeException e) {
            System.out.println("捕获到异常：" + e.getMessage());
            e.printStackTrace();//打印异常堆栈跟踪
        }
    }

    public static void someMethod(int a) {
        try {
            someMethod2(a);
        } catch (RuntimeException e) {
            throw new RuntimeException(e);
        }
    }

    public static void someMethod2(int a) {
        if (a < 0) {
            throw new RuntimeException("请输入大于或小于0的数");
        } else {
            System.out.println(a * a);
        }
    }
}
