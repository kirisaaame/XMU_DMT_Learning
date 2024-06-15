public class IsEqualTo {
    public static <T> boolean isEqualTo(T obj1, T obj2) {
        if (obj1 == null && obj2 == null) {
            return true;
        }
        if (obj1 == null || obj2 == null) {
            return false;
        }
        return obj1.equals(obj2);
    }

    public static void main(String[] args) {
        // 测试不同类型的对象
        System.out.println(isEqualTo(5, 5)); // 输出 true
        System.out.println(isEqualTo("Hello", "World")); // 输出 false
        System.out.println(isEqualTo(10.5, 10.5)); // 输出 true

    }
}
