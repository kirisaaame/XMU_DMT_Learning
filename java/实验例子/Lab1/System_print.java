import java.io.*;
public class System_print {
    public static void main(String[] args) throws IOException {

        char c;
        System.out.print("请输入一个字母");
        c = (char) System.in.read();
        //从标准输入读入u一个字节的信息，并返回一盒字符型变量
        System.out.println("接收到的字母是" + c);
    }
}
