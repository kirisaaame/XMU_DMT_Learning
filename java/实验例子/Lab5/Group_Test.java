import java.util.Scanner;

// 基础图形类
abstract class Graph {
    public abstract double calculateArea();
}

// 三角形类，继承自基础图形类
class Triangle extends Graph {
    private double side1;
    private double side2;
    private double side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    @Override
    public double calculateArea() {
        // 使用海伦公式计算三角形面积
        double s = (side1 + side2 + side3) / 2;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
}

// 矩形类，继承自基础图形类
class Rectangle extends Graph {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double calculateArea() {
        // 矩形面积计算公式：宽 * 高
        return width * height;
    }
}

public class Group_Test {
    public static void main(String[] args) {
        // 读取输入
        Scanner scanner = new Scanner(System.in);

        System.out.println("请输入图形的个数：");
        int n = scanner.nextInt();
        scanner.nextLine(); // 消耗换行符

        Graph[] shapes = new Graph[n]; // 存储图形对象

        System.out.println("请依次输入每个图形的信息（三角形：边1 边2 边3，矩形：宽 高）：");
        for (int i = 0; i < n; i++) {
            System.out.print("请输入第 " + (i + 1) + " 个图形信息：");

            // 检查是否有输入
            if (!scanner.hasNextLine()) {//判断条件输入流中是否还有下一行待读取
                System.out.println("未输入图形信息，请重新输入。");
                i--; // 重新输入当前图形信息
                continue;
            }

            String input = scanner.nextLine().trim();//读取下一行的内容

            // 检查是否为空行
            if (input.isEmpty()) {
                System.out.println("未输入图形信息，请重新输入。");
                i--; // 重新输入当前图形信息
                continue;
            }

            // 解析图形信息
            String[] parts = input.split(" ");//将字符串按照空格分隔输入数组中
            if (parts.length == 3) {
                double side1 = Double.parseDouble(parts[0]);//将字符串转换为double类型
                double side2 = Double.parseDouble(parts[1]);
                double side3 = Double.parseDouble(parts[2]);
                if (side1 > 0 && side2 > 0 && side3 > 0 &&
                        side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
                    shapes[i] = new Triangle(side1, side2, side3);
                } else {
                    System.out.println("输入的三条边无法构成三角形，请重新输入。");
                    i--; // 重新输入当前图形信息
                }
            } else if (parts.length == 2) {
                double width = Double.parseDouble(parts[0]);
                double height = Double.parseDouble(parts[1]);
                if (width > 0 && height > 0) {
                    shapes[i] = new Rectangle(width, height);
                } else {
                    System.out.println("输入的宽度和高度必须为正数，请重新输入。");
                    i--; // 重新输入当前图形信息
                }
            } else {
                System.out.println("无法识别的图形信息，请重新输入。");
                i--; // 重新输入当前图形信息
            }
        }

        // 输出面积
        System.out.println("图形的面积分别为：");
        for (Graph shape : shapes) {//声明了一个 Graph 类型的变量 shape，用于存储数组 shapes 中的每个元素来作为循环条件
            if (shape != null) {
                System.out.println(shape.calculateArea());
            }
        }
    }
}
