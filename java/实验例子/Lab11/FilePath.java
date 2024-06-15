import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class FilePath {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入文件路径:");
        String path = scanner.nextLine();

        File file = new File(path);
        if (file.exists()) {
            if (file.isDirectory()) {
                File[] contents = file.listFiles();
                int fileCount = 0;
                int directoryCount = 0;
                if (contents != null) {
                    for (File f : contents) {
                        if (f.isFile()) {
                            fileCount++;
                        } else if (f.isDirectory()) {
                            directoryCount++;
                        }
                    }
                }
                System.out.println("该文件夹包含的文件数: " + fileCount);
                System.out.println("该文件夹包含的文件夹数: " + directoryCount);
            } else if (file.isFile()) {
                long fileSize = file.length();
                Date lastModified = new Date(file.lastModified());
                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                System.out.println("该文件的大小: " + fileSize + " 字节");
                System.out.println("该文件的最后修改日期: " + sdf.format(lastModified));
            } else {
                System.out.println("输入的路径不是文件也不是文件夹.");
            }
        } else {
            System.out.println("输入的路径不存在.");
        }

        scanner.close();
    }
}
