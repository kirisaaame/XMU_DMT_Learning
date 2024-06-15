import java.security.SecureRandom;
import java.util.Scanner;

public class CAITest {

    private static final SecureRandom randomNumbers = new SecureRandom();
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            int num1 = generateRandomNumber();
            int num2 = generateRandomNumber();

            askQuestion(num1, num2);
            int answer = getStudentAnswer();

            while (answer != num1 * num2) {
                displayIncorrectResponse();
                answer = getStudentAnswer();
            }

            displayCorrectResponse();
        }
    }

    // 生成随机一位正整数
    private static int generateRandomNumber() {
        return randomNumbers.nextInt(9) + 1;
    }

    // 提问问题
    private static void askQuestion(int num1, int num2) {
        System.out.printf("%d 乘 %d的结果是多少?%n", num1, num2);
    }

    // 获取学生答案
    private static int getStudentAnswer() {
        System.out.print("请输入你的答案: ");
        return scanner.nextInt();
    }

    // 显示回答错误的提示
    private static void displayIncorrectResponse() {
        System.out.println("No. Please try again.");
    }

    // 显示回答正确的提示
    private static void displayCorrectResponse() {
        System.out.println("Very good!");
    }
}
