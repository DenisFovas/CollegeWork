package Services;

import java.util.List;

public class CoffeeInterpreter {

    /**
     *
     * @param data
     * @return
     */
    public List<Object> interpretCoffeeFromString(List<String> data) {
        if (data.isEmpty()) {
            throw new IllegalStateException("Invalid content received.");
        }

        return null;
    }
}
