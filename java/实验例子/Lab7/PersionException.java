// 自定义非法姓名异常类
class IllegalNameException extends Exception {
    public IllegalNameException(String message) {
        super(message);
    }
}

// 自定义非法地址异常类
class IllegalAddressException extends Exception {
    public IllegalAddressException(String message) {
        super(message);
    }
}

// Student 类
class Student {
    private String name;
    private String address;

    public void setName(String name) throws IllegalNameException {
        if (name.length() < 1 || name.length() > 5) {
            throw new IllegalNameException("姓名长度必须在1到5之间");
        }
        this.name = name;
    }

    public void setAddress(String address) throws IllegalAddressException {
        if (!address.contains("省") || !address.contains("市")) {
            throw new IllegalAddressException("地址必须包含“省”和“市”关键字");
        }
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }
}

public class PersionException {
    public static void main(String[] args) {
        Student student = new Student();

        try {
            student.setName("John"); // 非法姓名，抛出 IllegalNameException
        } catch (IllegalNameException e) {
            System.out.println("捕获到非法姓名异常：" + e.getMessage());
        }

        try {
            student.setAddress("北京市海淀区"); // 非法地址，抛出 IllegalAddressException
        } catch (IllegalAddressException e) {
            System.out.println("捕获到非法地址异常：" + e.getMessage());
        }
    }
}
