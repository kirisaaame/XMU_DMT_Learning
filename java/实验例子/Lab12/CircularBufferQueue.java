import java.util.Random;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class CircularBufferQueue {
    private static final int BUFFER_SIZE = 4;
    private final BlockingQueue<Integer> buffer = new ArrayBlockingQueue<>(BUFFER_SIZE);

    public static void main(String[] args) {
        CircularBufferQueue circularBuffer = new CircularBufferQueue();

        Thread producer = new Thread(circularBuffer.new Producer());
        Thread consumer = new Thread(circularBuffer.new Consumer());

        producer.start();
        consumer.start();
    }

    class Producer implements Runnable {
        private final Random random = new Random();

        @Override
        public void run() {
            try {
                while (true) {
                    int value = random.nextInt(10) + 1;
                    buffer.put(value);
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
                    int value = buffer.take();
                    System.out.println("Consumed: " + value);
                    Thread.sleep(500); // 暂停一段时间以便更清晰地看到线程的输出
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
