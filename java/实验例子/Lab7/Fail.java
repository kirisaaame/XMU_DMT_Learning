import java.util.Scanner;
class SomeClass {
    int a;

    public SomeClass(int a) {
        this.a = a;
        if (a < 0)
            throw new RuntimeException("请输入大于0的数");
    }

    public void printfIfo() {
        System.out.println("你输入的数是" + a);
    }
}

public class Fail {
    public static void main(String[] args) {
        try {
            System.out.println("请输入一个自然数：");
            Scanner scanner = new Scanner(System.in);
            int a = scanner.nextInt();
            SomeClass someClass = new SomeClass(a);
            someClass.printfIfo();
        } catch (RuntimeException e) {
            System.out.println("构造方法失败: " + e.getMessage());
        }
    }
}
