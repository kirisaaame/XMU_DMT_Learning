import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class ArrayWriter implements Runnable {
    private int[] array;
    private int start;
    private int end;
    private int increment;

    public ArrayWriter(int[] array, int start, int end, int increment) {
        this.array = array;
        this.start = start;
        this.end = end;
        this.increment = increment;
    }

    @Override
    public void run() {
        int value = start;
        for (int i = start; i <= end; i++) {
            array[i] = value;
            value += increment;
        }
    }

    public static void main(String[] args) {
        int[] array = new int[10000];

        ExecutorService executorService = Executors.newFixedThreadPool(4);

        executorService.execute(new ArrayWriter(array, 0, 9, 1));
        executorService.execute(new ArrayWriter(array, 100, 999, 1));
        executorService.execute(new ArrayWriter(array, 2000, 2999, 1));
        executorService.execute(new ArrayWriter(array, 4000, 4999, 1));

        executorService.shutdown();

        // 等待所有任务完成
        while (!executorService.isTerminated()) {}

        // 打印数组的部分内容来验证写入结果
        for (int i = 0; i < 10; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
        for (int i = 100; i < 1000; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
        for (int i = 2000; i < 3000; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
        for (int i = 4000; i < 5000; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
