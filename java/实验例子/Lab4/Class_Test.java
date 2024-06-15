import java.util.ArrayList;

// 学生类
class Student {
    protected String studentID;
    protected String name;
    protected String className;

    public Student(String studentID, String name, String className) {
        this.studentID = studentID;
        this.name = name;
        this.className = className;
    }

    public void printInfo() {
        System.out.println("学号：" + studentID);
        System.out.println("姓名：" + name);
        System.out.println("班级：" + className);
    }
}

// 本科生类，继承自学生类
class Undergraduate extends Student {
    public Undergraduate(String studentID, String name, String className) {
        super(studentID, name, className);
    }
}

// 研究生类，继承自学生类
class Graduate extends Student {
    private String supervisor;

    public Graduate(String studentID, String name, String className, String supervisor) {
        super(studentID, name, className);
        this.supervisor = supervisor;
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("导师：" + supervisor);
    }
}

// 课程类
class Course {
    protected String courseID;
    protected String courseName;
    protected int credit;

    public Course(String courseID, String courseName, int credit) {
        this.courseID = courseID;
        this.courseName = courseName;
        this.credit = credit;
    }

    public void printInfo() {
        System.out.println("课程编号：" + courseID);
        System.out.println("课程名称：" + courseName);
        System.out.println("学分：" + credit);
    }
}

// 必修课程类，继承自课程类
class CompulsoryCourse extends Course {
    public CompulsoryCourse(String courseID, String courseName, int credit) {
        super(courseID, courseName, credit);
    }
}

// 选修课程类，继承自课程类
class ElectiveCourse extends Course {
    public ElectiveCourse(String courseID, String courseName, int credit) {
        super(courseID, courseName, credit);
    }
}

public class Class_Test {
    public static void main(String[] args) {
        // 创建学生信息
        ArrayList<Student> students = new ArrayList<>();
        students.add(new Undergraduate("1001", "张三", "本科班1"));
        students.add(new Undergraduate("1002", "李四", "本科班2"));
        students.add(new Graduate("2001", "王五", "研究生班1", "导师A"));
        students.add(new Graduate("2002", "赵六", "研究生班2", "导师B"));

        // 创建课程信息
        ArrayList<Course> courses = new ArrayList<>();
        courses.add(new CompulsoryCourse("C001", "必修课程1", 3));
        courses.add(new CompulsoryCourse("C002", "必修课程2", 4));
        courses.add(new ElectiveCourse("E001", "选修课程1", 2));
        courses.add(new ElectiveCourse("E002", "选修课程2", 3));

        // 自动选课部分：为每个学生自动选修所有必修课
        for (Student student : students) {
            System.out.println("为学生 " + student.name + " 自动选课中...");
            for (Course course : courses) {
                if (course instanceof CompulsoryCourse) {
                    System.out.println(student.name + " 选修了必修课：" + course.courseName);
                }
            }
        }

        // 秘书手动选课部分：为每个同学选修1-2门选修课
        for (Student student : students) {
            System.out.println("为学生 " + student.name + " 手动选课中...");
            int count = 0;
            for (Course course : courses) {
                if (course instanceof ElectiveCourse && count < 2) {
                    System.out.println(student.name + " 选修了选修课：" + course.courseName);
                    count++;
                }
            }
        }

        // 打印出每个学生的选课信息
        System.out.println("\n学生选课信息如下：");
        for (Student student : students) {
            System.out.println("\n学生信息：");
            student.printInfo();
            System.out.println("选修课程：");
            for (Course course : courses) {
                if (course instanceof ElectiveCourse) {
                    System.out.println(course.courseName);
                }
            }
        }
    }
}
