import java.util.*;

public class News {
   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);

      // 从用户输入获取新闻内容，直到输入结束
      System.out.println("请输入新闻内容（ 输入Ctrl+Z结束输入）:");
      StringBuilder newsBuilder = new StringBuilder();
      while (scanner.hasNextLine()) {
         String line = scanner.nextLine();
         if (line.isEmpty()) {
            break; // 如果输入为空行，则结束
         }
         newsBuilder.append(line);//将不为空行的段添加到StringBuilder中
      }
      String news = newsBuilder.toString();

      // 将除了字母之外的都用空格替换
       String Countnews = news.replaceAll("[^a-zA-Z ]", "");

      // 将句子拆分为单词数组
      String[] words = Countnews.toLowerCase().split(" ");

      Set<String> wordSet = new HashSet<>();
      Collections.addAll(wordSet, words);

      System.out.println("出现的单词有：");
      for (String word : wordSet) {
         System.out.println(word);
      }

      // 输出包含“the”的句子
      String[] sentences = news.split("\\.");
      System.out.println("\n包含the的句子：");
      for (String sentence : sentences) {
         if (sentence.contains("the")) {
            System.out.println(sentence);
         }
      }

      scanner.close();
   }
}
