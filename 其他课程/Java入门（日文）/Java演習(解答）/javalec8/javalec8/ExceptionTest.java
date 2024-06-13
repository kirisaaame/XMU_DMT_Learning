/*
 * 3年 15組　96番　ゾウジファン
 * 出力：
 * Error in: 17
Error in: 19
Avg: 45515.20
 */

package javalec8;
public class ExceptionTest {
    public static void main(String[] args) {
        String[] persons = PersonData.persons;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < persons.length; i++) {
            try {
                int num = Integer.parseInt(persons[i]);
                sum += num;
                count++;
            } catch (NumberFormatException e) {
                System.out.println("Error in: " + i);
            }
        }
        double average = (double) sum / count;
        System.out.printf("Avg: %.2f\n", average);
    }
}
