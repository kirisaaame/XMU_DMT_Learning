package javalec9;
/*
 * 3年　15　96番　ゾウジファン
 * （実は、Comparatorを使わなくてもいい）
 * 出力：
 * <辞書順ソート>
00030
0042
10003
109
119
19
9
<数としてソート>
9
19
00030
0042
109
119
10003
 * 
 * 
 */
import java.util.Arrays;
public class ArrayTest {
    public static void main(String[] args) {
        String[] numstrings = ArrayDat.numstrings;

        // 辞書順ソート
        Arrays.sort(numstrings);
        System.out.println("<辞書順ソート>");
        for (String str : numstrings) {
            System.out.println(str);
        }

        // 数としてソート
        Arrays.sort(numstrings, (a, b) -> Integer.parseInt(a) - Integer.parseInt(b));
        System.out.println("<数としてソート>");
        for (String str : numstrings) {
            System.out.println(str);
        }
    }
}
