package model;

public class IDGenerator {
    private static int currentID = 0;
    public static int generateID() {
        return currentID++;
    }
}
