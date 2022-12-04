package OOP.lab2;

class Vector {
    private int x;
    private int y;

    public void setXY(int newX, int newY) {
        x = newX;
        y = newY;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    // Add 2 vectors together
    public Vector add(Vector otherVector) {
        Vector finalVector = new Vector();

        int finalX = this.x + otherVector.x;
        int finalY = this.y + otherVector.y;

        finalVector.setXY(finalX, finalY);

        return finalVector;
    }

    // Subtract 2 vectors
    public Vector subtract(Vector otherVector) {
        Vector finalVector = new Vector();

        int finalX = this.x - otherVector.x;
        int finalY = this.y - otherVector.y;

        finalVector.setXY(finalX, finalY);

        return finalVector;
    }

    // Multiply 2 vectors using Dot Product
    public int multiply(Vector otherVector, Vector unitVector) {
        int finalResult;

        finalResult = (this.x * otherVector.x) * unitVector.x + (this.y * otherVector.y) * unitVector.y;

        return finalResult;
    }

}

public class VectorTestDrive {
    public static void main(String[] args) {

        Vector v1 = new Vector();
        Vector v2 = new Vector();
        Vector unit = new Vector();

        v1.setXY(1, 2);
        v2.setXY(3, 4);
        unit.setXY(1, 1);

        // Add 2 vectors together
        Vector addition = v1.add(v2);
        System.out.println("Addition of v1 and v2 = (x = " + addition.getX() + ", y = " + addition.getY() + ")");

        // Subtract 2 vectors
        Vector subtraction = v1.subtract(v2);
        System.out
                .println("Subtraction of v1 and v2 = (x = " + subtraction.getX() + ", y = " + subtraction.getY() + ")");

        // Multiply 2 vectors using Dot Product
        int multiplication = v1.multiply(v2, unit);
        System.out.println("Multiplication of v1 and v2 = " + multiplication);
    }
}
