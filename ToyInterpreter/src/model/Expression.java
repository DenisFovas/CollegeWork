package model;

public interface Expression {
    int evaluate(IDictionary<String, Integer> st) throws DivisionByZeroException, KeyNotInsertedException;
}
