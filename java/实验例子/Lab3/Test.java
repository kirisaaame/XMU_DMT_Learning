import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

// 学生类
class Student {
    // 学号、姓名、班级、电话
    String studentID;
    String name;
    String className;
    String phoneNumber;

    // 构造函数
    public Student(String studentID, String name, String className, String phoneNumber) {
        this.studentID = studentID;
        this.name = name;
        this.className = className;
        this.phoneNumber = phoneNumber;
    }

    // 重载构造函数，处理电话为空的情况
    public Student(String studentID, String name, String className) {
        this(studentID, name, className, "");
    }
}

// 课程类
class Course {
    // 课程编号、课程名称
    String courseID;
    String courseName;

    // 构造函数
    public Course(String courseID, String courseName) {
        this.courseID = courseID;
        this.courseName = courseName;
    }
}

// 测试类
public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入课程信息并创建课程对象
        Map<String, Course> courses = new HashMap<>();
        for (int i = 0; i < 2; i++) {
            System.out.println("请输入第" + (i + 1) + "门课程的信息：");
            System.out.print("课程编号：");
            String courseID = scanner.nextLine();
            System.out.print("课程名称：");
            String courseName = scanner.nextLine();
            courses.put(courseID, new Course(courseID, courseName));
        }

        // 输入学生信息并选课
        System.out.println("请输入学生的选课信息：");
        for (int i = 0; i < 2; i++) {
            System.out.println("请输入第" + (i + 1) + "个学生的信息：");
            System.out.print("学号：");
            String studentID = scanner.nextLine();
            System.out.print("姓名：");
            String name = scanner.nextLine();
            System.out.print("班级：");
            String className = scanner.nextLine();
            System.out.print("电话（可为空）：");
            String phoneNumber = scanner.nextLine();
            Student student;
            if (phoneNumber.isEmpty()) {
                student = new Student(studentID, name, className);
            } else {
                student = new Student(studentID, name, className, phoneNumber);
            }

            System.out.print("请选择课程编号：");
            String courseID = scanner.nextLine();
            Course selectedCourse = courses.get(courseID);
            if (selectedCourse != null) {
                System.out.println(student.name + " 选了 " + selectedCourse.courseName);
            } else {
                System.out.println("课程编号不存在，请重新输入。");
                i--; // 重新输入学生信息
            }
        }

        scanner.close();
    }
}
