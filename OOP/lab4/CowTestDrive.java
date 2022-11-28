
class Cow {
    private String name;
    private String breed;
    private int age;

    public void moo() {
        System.out.println("Moo...!");
    }

    public void setName(String newName) {
        name = newName;
    }

    public void setBreed(String newBreed) {
        breed = newBreed;
    }

    public void setAge(int newAge) {
        age = newAge;
    }
}

public class CowTestDrive {
    public static void main(String[] args) {
        Cow newCow = new Cow();
        newCow.setName("name");
        newCow.setBreed("brown");
        newCow.setAge(4);
        newCow.moo();
    }
}
