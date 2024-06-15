import java.util.*;

public class Remove {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Set<String> namesSet = new HashSet<>();

        // 读取名字序列
        System.out.println("请输入名字序列（每个名字一行，输入\"done\"结束）：");
        String name = scanner.nextLine().trim();
        while (!name.equalsIgnoreCase("done")) {
            namesSet.add(name);
            name = scanner.nextLine().trim();
        }

        // 打印结果
        System.out.println("删除重复名字后的结果：");
        for (String Name : namesSet) {
            System.out.println(Name);
        }
    }
}
