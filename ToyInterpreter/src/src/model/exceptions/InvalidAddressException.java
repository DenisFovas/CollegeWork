package model.exceptions;

public class InvalidAddressException extends Exception {
    public InvalidAddressException() {
    }

    public InvalidAddressException(String message) {
        super(message);
    }
}
