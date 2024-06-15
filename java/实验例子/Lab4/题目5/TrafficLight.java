public enum TrafficLight {
    RED(255, 0, 0),
    YELLOW(255, 255, 0),
    GREEN(0, 255, 0);

    private final int red;
    private final int green;
    private final int blue;

    TrafficLight(int red, int green, int blue) {
        this.red = red;
        this.green = green;
        this.blue = blue;
    }

    public int getRed() {
        return red;
    }

    public int getGreen() {
        return green;
    }

    public int getBlue() {
        return blue;
    }
}
