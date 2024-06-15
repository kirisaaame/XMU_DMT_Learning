import java.util.Random;

public class CircularBufferSync {
    private static final int BUFFER_SIZE = 4;
    private final int[] buffer = new int[BUFFER_SIZE];
    private int count = 0; // 当前缓冲区中的元素数量
    private int in = 0;    // 写入位置
    private int out = 0;   // 读取位置

    public static void main(String[] args) {
        CircularBufferSync circularBuffer = new CircularBufferSync();

        Thread producer = new Thread(circularBuffer.new Producer());
        Thread consumer = new Thread(circularBuffer.new Consumer());

        producer.start();
        consumer.start();
    }

    private synchronized void put(int value) throws InterruptedException {
        while (count == BUFFER_SIZE) {
            wait();
        }
        buffer[in] = value;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        notifyAll();
    }

    private synchronized int get() throws InterruptedException {
        while (count == 0) {
            wait();
        }
        int value = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        notifyAll();
        return value;
    }

    class Producer implements Runnable {
        private final Random random = new Random();

        @Override
        public void run() {
            try {
                while (true) {
                    int value = random.nextInt(10) + 1;
                    put(value);
                    System.out.println("Produced: " + value);
                    Thread.sleep(500); // 暂停一段时间以便更清晰地看到线程的输出
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    class Consumer implements Runnable {
        @Override
        public void run() {
            try {
                while (true) {
                    int value = get();
                    System.out.println("Consumed: " + value);
                    Thread.sleep(500); // 暂停一段时间以便更清晰地看到线程的输出
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
