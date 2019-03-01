import Services.FileReader;

import java.io.IOException;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        FileReader f = new FileReader("content.txt");
        try {
            List<String> fileContent = f.readFile();
        } catch (IOException e) {
            System.out.println("Invalid content in the file. Please try again.");
        }
    }
}
