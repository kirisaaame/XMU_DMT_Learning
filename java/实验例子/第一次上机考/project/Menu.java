import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import java.util.Random;

class Vehicle {
    int Number;
    String MaxElectric;
    String Voltage;
    Boolean UsingCondition;
    String Position;
    Float Price;
    Float UsedPrice;
    int Degrees;

    public Vehicle(int Degrees,Float UsedPrice,Float Price,int Number,String MaxElectric,String Voltage,Boolean UsingCondition,String Position) {
        this.Number=Number;
        this.MaxElectric=MaxElectric;
        this.Voltage=Voltage;
        this.UsingCondition=UsingCondition;
        this.Position=Position;
        this.Price=Price;
        this.UsedPrice=UsedPrice;
        this.Degrees=Degrees;
    }

    public void Charge() {
        // 默认实现为空，具体实现由子类完成
    }
    public void PrintfInfo(){
    }
    public void PrintfPrice(){
    }
}

class HighCar extends Vehicle {
    int Time;
    Float TimePrice;

    public HighCar(int Degrees,Float UsedPrice,Float Price,int Number,String MaxElectric,String Voltage,Boolean UsingCondition,String Position,int Time,Float TimePrice) {
        super(Degrees,UsedPrice,Price,Number,MaxElectric,Voltage,UsingCondition,Position);
        this.Time=Time;
        this.TimePrice=TimePrice;
    }

    @Override
    public void Charge() {
        UsedPrice=Price*Degrees+TimePrice*Time;
    }
    @Override
    public void PrintfInfo(){
        System.out.println("类型：快充"+" 编号："+Number+" 位置："+Position+" 最大电流："+MaxElectric+" 电压："+Voltage+" 是否在充电："+UsingCondition);
    }
    @Override
    public void PrintfPrice(){
        System.out.println("编号"+Number+"已充电费用:"+UsedPrice);
    }
}

class LowCar extends Vehicle {
    public LowCar(int Degrees, Float UsedPrice, Float Price, int Number, String MaxElectric, String Voltage, Boolean UsingCondition, String Position) {
        super(Degrees,UsedPrice,Price,Number,MaxElectric,Voltage,UsingCondition,Position);
    }

    @Override
    public void Charge() {
        UsedPrice=Price*Degrees;
    }
    @Override
    public void PrintfInfo(){
        System.out.println("类型：慢充"+" 编号："+Number+" 位置："+Position+" 最大电流"+MaxElectric+" 电压："+Voltage+" 是否在充电："+UsingCondition);
    }
    @Override
    public void PrintfPrice(){
        System.out.println("编号"+Number+"已充电费用:"+UsedPrice);
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
                NewCharge(scanner);
                CarSystem();
                break;
            case "2":
                scanner.nextLine();
                Charge();
                CarSystem();
                break;
            case "3":
                scanner.nextLine();
                PrintCar();
                CarSystem();
                break;
            case "4":
                scanner.nextLine();
                PrintfPrice();
                CarSystem();
            case "5":
                scanner.nextLine();
                Change();
                CarSystem();
            case "6":
                System.out.println("结束程序");
                return;
            default:
                System.out.println("请输入1-6的整数");
                CarSystem();
        }
    }

    public static void PrintMenu() {
        System.out.println("请输入命令编号");
        System.out.println("1.  新增充电桩");
        System.out.println("2.  充电桩充电");
        System.out.println("3.  列出所有充电桩信息");
        System.out.println("4.  列出每台充电桩已充电费用");
        System.out.println("5.  将慢速充电桩收费标准上涨5%");
        System.out.println("6.  退出");
    }

    public static void NewCharge(Scanner scanner) {
        while (true) {
            System.out.println("请按照以下格式输入");
            System.out.println("编号、位置、最大电流、电压");
            System.out.println("如：");
            System.out.println("快充 111 西部片区 400A 220V");
            System.out.println("慢充 222 主校区 100A 220V");
            System.out.println("其中“编号”为1-9999的整数");

            String input = scanner.nextLine();
            if (input.equals("Y")) {
                break;
            }
            String[] parts = input.split(" ");//分割输入到数组中
            if (parts.length < 5) {
                System.out.println("输入数据短于要求，请重新输入或输入Y结束：");
                System.out.println("创建不成功");
                continue;
            }
            String vehicleType = parts[0];
            int Number = Integer.parseInt(parts[1]);
            String Position=parts[2];
            String MaxElectric=parts[3];
            String Voltage=parts[4];
            if (vehicleType.equals("快充")) {
                vehicles.add(new HighCar(0,0.0f,1.2f,Number,MaxElectric,Voltage,false,Position,0,0.05f));
            } else if (vehicleType.equals("慢充")) {
                vehicles.add(new LowCar(0,0.0f,1.1f,Number,MaxElectric,Voltage,false,Position));
            } else {
                System.out.println("第一个应为快充或者慢充");
                System.out.println("创建不成功");
                continue;
            }
            System.out.println("创建成功");
            vehicles.get(vehicles.size() - 1).PrintfInfo();
            System.out.println("是否结束新增，若结束输入请输入Y,反之请输入其他内容");
            String ainput = scanner.nextLine();
            if (ainput.equals("Y")) {
                break;
            }
        }
    }

    public static void Charge() {

        for (Vehicle vehicle : vehicles) {
            if (vehicle instanceof HighCar highcar) { // 检查是否是快充
              Random rand=new Random();
              highcar.UsingCondition=true;
              highcar.Degrees=rand.nextInt(80)+10;
              highcar.Time=rand.nextInt(240)+20;
              highcar.Charge();
            } else if (vehicle instanceof LowCar lowcar) { // 检查是否是慢充
                Random rand=new Random();
                lowcar.UsingCondition=true;
                lowcar.Degrees=rand.nextInt(80)+10;
                lowcar.Charge();
            }
        }
        System.out.println("充电完成");
    }

    public static void PrintCar() {

        for (Vehicle vehicle1 : vehicles) {
            vehicle1.PrintfInfo();
        }
    }
    public static void PrintfPrice(){
        for (Vehicle vehicle1 : vehicles) {
            vehicle1.PrintfPrice();
        }
    }
    public static void Change(){
        for (Vehicle vehicle1 : vehicles) {//循环找出慢充
            if (vehicle1 instanceof LowCar lowcar) {
                lowcar.Price= lowcar.Price*1.05f;
            }
        }
        System.out.println("已改变");
    }
}
