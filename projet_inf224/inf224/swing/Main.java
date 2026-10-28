import UserInterface.GeneralWindow;
import UserInterface.Client;

public class Main {
    public static void main(String[] args) {
        GeneralWindow principalWindow = new GeneralWindow();
        principalWindow.createWindow();
        Client client1 = new Client(principalWindow);
        principalWindow.setClient(client1);
        client1.startClient();
       }
}
