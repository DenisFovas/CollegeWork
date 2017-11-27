package model.expressions;

import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.IHeap;

public class ConstantExpression implements Expression {
    public ConstantExpression(int _value) {
        this._value = _value;
    }

    private int _value;

    @Override
    public int evaluate(IDictionary<String, Integer> st,  IHeap<Integer, Integer> heap) {
        return _value;
    }

    @Override
    public String toString () {
        return "" + _value;
    }
}
