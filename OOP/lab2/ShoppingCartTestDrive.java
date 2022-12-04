package OOP.lab2;

import java.util.LinkedList;

class ShoppingCart {
    private LinkedList<String> cartContents = new LinkedList<String>();

    // Add an item to the cart
    public void addToCart(String newContent) {
        cartContents.add(newContent);
    }

    // Remove an item from the cart
    public void removeFromCart(String content) {
        cartContents.remove(content);
    }

    public void checkOut() {
        System.out.println("Cart's content: ");
        for (int i = 0; i < cartContents.size(); i++) {
            System.out.println(cartContents.get(i));
        }
    }
}

public class ShoppingCartTestDrive {
    public static void main(String[] args) {
        ShoppingCart theCart = new ShoppingCart();

        theCart.addToCart("cookies");
        theCart.addToCart("bread");
        theCart.addToCart("rice");

        theCart.checkOut();

        theCart.removeFromCart("cookies");

        theCart.checkOut();
    }

}
