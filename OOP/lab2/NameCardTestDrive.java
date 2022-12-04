package OOP.lab2;

class NameCard {
    private String name;
    private String phoneNum;
    private String email;

    public void setEmail(String newEmail) {
        email = newEmail;
    }

    public void setName(String newName) {
        name = newName;
    }

    public void setPhoneNum(String newNum) {
        phoneNum = newNum;
    }

    public String getEmail() {
        return email;
    }

    public String getPhone() {
        return phoneNum;
    }

    public String getName() {
        return name;
    }

}

public class NameCardTestDrive {
    public static void main(String[] args) {
        NameCard card = new NameCard();

        card.setName("Polly Morfism");
        card.setEmail("testmail123@hotmail.com");
        card.setPhoneNum("555-69420");

        System.out.println("Name: " + card.getName());
        System.out.println("PhoneNumber: " + card.getPhone());
        System.out.println("eMail: " + card.getEmail());
    }
}
