package model.expressions;

import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.IHeap;

public class ReadExpression implements Expression {
    private String _varName;

    public ReadExpression(String _varName) {
        this._varName = _varName;
    }

    @Override
    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer, Integer> heap) throws DivisionByZeroException, KeyNotInsertedException {
        return heap.find(st.get(_varName));
    }

    @Override
    public String toString() {
        return "ReadExpression{" +
                "_varName='" + _varName + '\'' +
                '}';
    }
}
