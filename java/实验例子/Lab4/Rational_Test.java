// 有理数类
class Rational extends Number implements Comparable<Rational> {
    private int numerator; // 分子
    private int denominator; // 分母

    public Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw new IllegalArgumentException("分母不能为0");
        }
        int gcd = gcd(Math.abs(numerator), Math.abs(denominator));
        this.numerator = numerator / gcd;
        this.denominator = denominator / gcd;
    }

    // 获取分子
    public int getNumerator() {
        return numerator;
    }

    // 获取分母
    public int getDenominator() {
        return denominator;
    }

    // 求最大公约数
    private int gcd(int m, int n) {
        while (n != 0) {
            int rem = m % n;
            m = n;
            n = rem;
        }
        return m;
    }

    // 加法
    public Rational add(Rational other) {
        int newNumerator = this.numerator * other.denominator + other.numerator * this.denominator;
        int newDenominator = this.denominator * other.denominator;
        return new Rational(newNumerator, newDenominator);
    }

    // 减法
    public Rational subtract(Rational other) {
        int newNumerator = this.numerator * other.denominator - other.numerator * this.denominator;
        int newDenominator = this.denominator * other.denominator;
        return new Rational(newNumerator, newDenominator);
    }

    // 乘法
    public Rational multiply(Rational other) {
        int newNumerator = this.numerator * other.numerator;
        int newDenominator = this.denominator * other.denominator;
        return new Rational(newNumerator, newDenominator);
    }

    // 除法
    public Rational divide(Rational other) {
        int newNumerator = this.numerator * other.denominator;
        int newDenominator = this.denominator * other.numerator;
        return new Rational(newNumerator, newDenominator);
    }

    @Override
    public int intValue() {
        return numerator / denominator;
    }

    @Override
    public long longValue() {
        return numerator / denominator;
    }

    @Override
    public float floatValue() {
        return (float) numerator / denominator;
    }

    @Override
    public double doubleValue() {
        return (double) numerator / denominator;
    }

    @Override
    public int compareTo(Rational other) {
        double diff = this.doubleValue() - other.doubleValue();
        if (diff > 0) {
            return 1;
        } else if (diff < 0) {
            return -1;
        } else {
            return 0;
        }
    }

    @Override
    public String toString() {
        return numerator + "/" + denominator;
    }
}

// 测试类
public class Rational_Test {
    public static void main(String[] args) {
        Rational rational1 = new Rational(1, 3);
        Rational rational2 = new Rational(2, 5);

        // 输出两个有理数对象
        System.out.println("有理数1：" + rational1);
        System.out.println("有理数2：" + rational2);

        // 输出两个有理数的加、减、乘、除结果
        System.out.println("两个有理数的加法结果：" + rational1.add(rational2));
        System.out.println("两个有理数的减法结果：" + rational1.subtract(rational2));
        System.out.println("两个有理数的乘法结果：" + rational1.multiply(rational2));
        System.out.println("两个有理数的除法结果：" + rational1.divide(rational2));
    }
}
