import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class MyRunnable2 implements Runnable {
    private String threadName;

    public MyRunnable2(String threadName) {
        this.threadName = threadName;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println(threadName + "-" + i);
            try {
                Thread.sleep(100); // 暂停一段时间以便更清晰地看到线程的输出
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(2);

        executorService.execute(new MyRunnable2("Thread1"));
        executorService.execute(new MyRunnable2("Thread2"));

        executorService.shutdown();
    }
}

