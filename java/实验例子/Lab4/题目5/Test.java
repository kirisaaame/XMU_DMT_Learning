public class Test {
    public static void main(String[] args) {
        for (TrafficLight light : TrafficLight.values()) {
            System.out.println(light.name() + " RGB值: (" + light.getRed() + ", " + light.getGreen() + ", " + light.getBlue() + ")");
        }
    }
}
