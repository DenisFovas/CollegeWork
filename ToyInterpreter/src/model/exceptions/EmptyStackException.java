package model.exceptions;

public class EmptyStackException extends Exception{
    public EmptyStackException () {
        super();
    }
    public EmptyStackException(String message) {
        super(message);
    }
}
