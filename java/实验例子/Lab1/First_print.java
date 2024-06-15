import java.util.Scanner; // 导入java.util.Scanner

public class First_print {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); //生成scanner对象
        System.out.print("请输入你的姓名:");
        String name = sc.nextLine();//输入字符串
        System.out.print("请输入你的年龄:");
        int age = sc.nextInt();//输入整数
        System.out.println("姓名:" + name +"\n" +"年龄:" + age);
    }
}