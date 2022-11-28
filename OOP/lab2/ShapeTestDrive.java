
class Object {
    protected String name;
}

abstract class Shape extends Object {
    protected double area;
    protected double volume;

    double calArea() {
        return area;
    }

    double calVolume() {
        return volume;
    }

    abstract String getName();
}

class Point extends Shape {
    protected int coor_x;
    protected int coor_y;

    String getName() {
        name = "Point";
        return name;
    }

}

class Circle extends Point {
    protected double r;

    public Circle(double newR) {
        r = newR;
    }

    double calArea() {
        return Math.PI * Math.pow(r, 2);
    }

    double calVolume() {
        return (4 / 3) * Math.PI * Math.pow(r, 3);
    }

    String getName() {
        name = "Circle";
        return name;
    }
}

class Cylinder extends Circle {
    private double h;

    public Cylinder(double newR, double newH) {
        super(newR);
        h = newH;
    }

    double calArea() {
        return 2 * r * h * Math.PI + 2 * Math.PI + Math.pow(r, 2);
    }

    double calVolume() {
        return Math.PI * Math.pow(r, 2) * h;
    }

    String getName() {
        name = "Cylinder";
        return name;
    }
}

public class ShapeTestDrive {
    public static void main(String[] args) {
        Shape point = new Point();
        Shape circle = new Circle(5);
        Shape cylinder = new Cylinder(3, 5);

        Shape[] objs = { point, circle, cylinder };

        for (int i = 0; i < 3; i++) {
            System.out.println("-----------");
            System.out.println("Name = " + objs[i].getName());
            System.out.println("Area = " + objs[i].calArea());
            System.out.println("Volume = " + objs[i].calVolume());
        }
    }

}