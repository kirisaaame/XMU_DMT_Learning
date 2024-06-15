import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Vehicle {
    String Logo;
    String Colour;
    int Year;

    public Vehicle(String Logo, String Colour, int Year) {
        this.Colour = Colour;
        this.Logo = Logo;
        this.Year = Year;
    }

    public void PrintInfo() {
        // 默认实现为空，具体实现由子类完成
    }
}

class Car extends Vehicle {
    int People;
    String CarNumber;

    public Car(int People, String CarNumber, String Logo, String Colour, int Year) {
        super(Logo, Colour, Year);
        this.CarNumber = CarNumber;
        this.People = People;
    }

    @Override
    public void PrintInfo() {
        System.out.println("小汽车，" + "品牌：" + Logo + " 颜色：" + Colour + " 出厂年份：" + Year + " 载客量" + People + "人 " + "箱数" + CarNumber);
    }
}

class Truck extends Vehicle {
    float Weight;

    public Truck(String Logo, String Colour, float Weight, int Year) {
        super(Logo, Colour, Year);
        this.Weight = Weight;
    }

    @Override
    public void PrintInfo() {
        System.out.println("卡车，" + "品牌：" + Logo + " 颜色：" + Colour + " 出厂年份：" + Year + " 载重量" + Weight+"吨");
    }
}

public class Menu {
    static List<Vehicle> vehicles = new ArrayList<>();

    public static void main(String[] args) {
        CarSystem();
    }

    public static void CarSystem() {
        Scanner scanner = new Scanner(System.in);
        PrintMenu();
        String count = scanner.next();
        switch (count) {
            case "1":
                scanner.nextLine();
                NewCar(scanner);
                CarSystem();
                break;
            case "2":
                scanner.nextLine();
                FindCar(scanner);
                CarSystem();
                break;
            case "3":
                scanner.nextLine();
                PrintCar();
                CarSystem();
                break;
            case "4":
                System.out.println("结束程序");
                return;
            default:
                System.out.println("请输入1-4的整数");
                CarSystem();
        }
    }

    public static void PrintMenu() {
        System.out.println("请输入对应输入进行相应菜单操作：");
        System.out.println("1.    新增车辆");
        System.out.println("2.    查询车辆");
        System.out.println("3.    列出所有车辆");
        System.out.println("4.    结束程序");
    }

    public static void NewCar(Scanner scanner) {
        while (true) {
            System.out.println("请输入车辆信息，示例：");
            System.out.println("  小汽车 丰田 红色 4 2007 2厢");
            System.out.println("  卡车 雷诺 红色 3.5 2008");
            System.out.println("结束新增，请输入end");

            try {
                String input = scanner.nextLine();
                if (input.equals("end")) {
                    break;
                }
                String[] parts = input.split(" ");
                if (parts.length < 5) {
                    throw new IllegalArgumentException("输入数据短于要求，请重新输入或输入end结束：\n创建不成功");
                }
                String vehicleType = parts[0];
                String Logo = parts[1];
                String Colour = parts[2];
                int Year = Integer.parseInt(parts[4]);
                if (vehicleType.equals("小汽车")) {
                    int People = Integer.parseInt(parts[3]);
                    String CarNumber = parts[5];
                    vehicles.add(new Car(People, CarNumber, Logo, Colour, Year));
                } else if (vehicleType.equals("卡车")) {
                    float Weight = Float.parseFloat(parts[3]);
                    vehicles.add(new Truck(Logo, Colour, Weight, Year));
                } else {
                    System.out.println("第一个应为小汽车或者卡车");
                    System.out.println("创建不成功");
                    continue;
                }
                System.out.println("创建成功");
                vehicles.get(vehicles.size() - 1).PrintInfo();
            } catch (NumberFormatException | ArrayIndexOutOfBoundsException e) {
                System.out.println("输入数据格式错误，请重新输入");
            }catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void FindCar(Scanner scanner) {
        while (true) {
            try {
                System.out.println("请按照“类型 商标 颜色 出厂年”的顺序输入条件，若条件为空用“null”代替，2个示例");
                System.out.println("  小汽车 丰田 红色 2007");
                System.out.println("  null 丰田 null null");
                System.out.println("输入end返回上级菜单");
                String input = scanner.nextLine();
                if (input.equals("end")) {
                    break;
                }
                String[] parts = input.split(" ");// 分割输入到数组中
                if (parts.length < 4) {
                    throw new IllegalArgumentException("输入格式不正确，请按照指定格式输入");
                }
                String vehicleType = parts[0];
                String Logo = parts[1];
                String Colour = parts[2];
                int Year;// 针对“null 丰田 null null”中年份不是数字
                if (parts[3].equals("null")) {
                    Year = 0; // 如果年份为 "null"，则将其设为 0
                } else {
                    try {
                        Year = Integer.parseInt(parts[3]); // 否则解析年份
                    } catch (NumberFormatException e) {
                        throw new IllegalArgumentException("年份必须是整数", e);
                    }
                }

                int count = 0; // 符合条件的车辆数量
                List<Vehicle> matching = new ArrayList<>(); // 符合条件的车辆列表
                for (Vehicle vehicle : vehicles) {
                    if (vehicleType.equals("小汽车") && vehicle instanceof Car car) { // 检查是否是小汽车
                        if ((Logo.equals("null") || car.Logo.equals(Logo)) &&
                                (Colour.equals("null") || car.Colour.equals(Colour)) &&
                                (Year == 0 || car.Year == Year)) {
                            matching.add(car);
                            count++; // 符合条件的车辆数量加1
                        }
                    } else if (vehicleType.equals("卡车") && vehicle instanceof Truck truck) { // 检查是否是卡车
                        if ((Logo.equals("null") || truck.Logo.equals(Logo)) &&
                                (Colour.equals("null") || truck.Colour.equals(Colour)) &&
                                (Year == 0 || truck.Year == Year)) {
                            matching.add(truck);
                            count++; // 符合条件的车辆数量加1
                        }
                    }
                }
                if (count == 0) {
                    System.out.println("没有搜索到相应的交通工具");
                } else {
                    System.out.println("搜索到" + count + "辆车，信息如下：");
                    for (Vehicle vehicle : matching) {
                        vehicle.PrintInfo();
                    }
                }
            } catch (IllegalArgumentException e) {
                System.out.println( e.getMessage());
            }
        }
    }

    public static void PrintCar() {
        System.out.println("目前有" + vehicles.size() + "辆车信息如下：");
        for (Vehicle vehicle1 : vehicles) {
            vehicle1.PrintInfo();
        }
    }
}

