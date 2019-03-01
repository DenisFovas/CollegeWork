package Services;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class FileReader {
    private String fileName;

    public FileReader(String fileName) {
        this.fileName = fileName;
    }

    public List<String> readFile() throws IOException {
        File file = new File(this.fileName);

        if (!file.exists()) {
            throw new IOException("Invalid file path given.");
        }

    }
}
