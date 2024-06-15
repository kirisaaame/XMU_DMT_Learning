import java.util.*;

public class CountWords {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 读取输入的句子
        System.out.println("请输入一段英文句子：");
        String sentence = scanner.nextLine();

        //将除了字母之外的都用空格替换
        sentence = sentence.replaceAll("[^a-zA-Z ]", "");

        // 将句子拆分为单词数组
        String[] words = sentence.toLowerCase().split(" ");

        // 使用HashSet来存储单词，并统计重复单词的数量
        Set<String> wordSet = new HashSet<>();
        Set<String> SameWords = new HashSet<>();

        for (String word : words) {
            if (!wordSet.add(word)) { // 如果添加失败，说明该单词已经存在于集合中，是重复单词
                SameWords.add(word);
            }
        }

        // 输出重复单词数量及重复单词列表
        System.out.println("重复的单词数量为：" + SameWords.size());
        System.out.println("重复的单词列表为：" + SameWords);
    }
}
