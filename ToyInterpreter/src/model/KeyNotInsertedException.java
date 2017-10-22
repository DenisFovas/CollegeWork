package model;

public class KeyNotInsertedException extends Exception {
    public KeyNotInsertedException() {
        super();
    }
    public KeyNotInsertedException(String message) {
        super(message);
    }
}
