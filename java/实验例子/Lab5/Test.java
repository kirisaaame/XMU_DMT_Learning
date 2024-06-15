class Vehicle {
    public void run() {
        System.out.println("这是交通工具的run方法");
    }
}

class Motor extends Vehicle {
    @Override
    public void run() {
        System.out.println("这是汽车的run方法");
    }
}

class Ship extends Vehicle {
    @Override
    public void run() {
        System.out.println("这是船的run方法");
    }
}

class Aeroplane extends Vehicle {
    @Override
    public void run() {
        System.out.println("这是飞机的run方法");
    }
}

class Bus extends Motor {
    @Override
    public void run() {
        System.out.println("这是公共汽车的run方法");
    }
}

class Car extends Motor {
    @Override
    public void run() {
        System.out.println("这是轿车的run方法");
    }
}

public class Test {
    public static void main(String[] args) {
        Vehicle v1 = new Motor();
        Vehicle v2 = new Ship();
        Vehicle v3 = new Aeroplane();
        Motor v4 = new Bus();
        Motor v5 = new Car();
        v1.run();
        v2.run();
        v3.run();
        v4.run();
        v5.run();
    }
}
