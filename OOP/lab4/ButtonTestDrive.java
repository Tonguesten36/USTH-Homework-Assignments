
class Button {
    private String label;
    private String colour;

    public void setColour(String newColour) {
        colour = newColour;
    }

    public void setLabel(String newLabel) {
        label = newLabel;
    }

    // push the button
    public void dePress() {
        setColour("green");
        setLabel("on");

        System.out.println("colour: " + colour + ", label: " + label);
    }

    // release the button
    public void unDepress() {
        setColour("red");
        setLabel("off");

        System.out.println("colour: " + colour + ", label: " + label);
    }
}

public class ButtonTestDrive {
    public static void main(String[] args) {
        Button b = new Button();
        b.dePress();
        b.unDepress();
    }
}
