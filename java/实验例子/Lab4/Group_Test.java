import java.util.Scanner;

// 基础图形类
class Graph {
    public double calculateArea() {
        return 0.0;
    }
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
        double[][] inputs = new double[n][3]; // 存储输入的边长

        System.out.println("请依次输入每个图形的信息（三角形：边1 边2 边3，矩形：宽 高）：");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                inputs[i][j] = scanner.nextDouble();
            }
        }

        // 创建图形对象并计算面积
        Graph[] shapes = new Graph[n];
        for (int i = 0; i < n; i++) {
            if (inputs[i].length == 3) {
                shapes[i] = new Triangle(inputs[i][0], inputs[i][1], inputs[i][2]);
            } else if (inputs[i].length == 2) {
                shapes[i] = new Rectangle(inputs[i][0], inputs[i][1]);
            }
        }

        // 输出面积
        System.out.println("图形的面积分别为：");
        for (Graph shape : shapes) {
            System.out.println(shape.calculateArea());
        }
    }
}
