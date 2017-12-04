package model.interfaces;

import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;

public interface Expression {
    int evaluate(IDictionary<String, Integer> st, IHeap<Integer, Integer> heap) throws DivisionByZeroException, KeyNotInsertedException;
}
