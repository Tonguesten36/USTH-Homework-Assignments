// The Automobile program after being fixed

class Automobile {
    private double fuel;
    private double speed;
    private String license;

    public void init(double f, double s, String l) {
        fuel = f;
        speed = s;
        license = l;
    }

    public double getSpeed() {
        return speed;
    }

    public void accelerate(double v) {
        if (fuel > 0) {
            speed += v;
        }
    }

    public void decelerate(double v) {
        if (fuel > 0) {
            speed -= v;
        }
    }
}

public class AutomobileTestDrive {
    public static void main(String[] args) {
        Automobile car = new Automobile();

        car.init(4.5, 34, "29JAD");
        System.out.println(car.getSpeed());

        car.accelerate(4);
        System.out.println(car.getSpeed());

        car.decelerate(5);
        System.out.println(car.getSpeed());
    }
}
