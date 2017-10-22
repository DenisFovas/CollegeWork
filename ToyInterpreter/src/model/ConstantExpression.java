package model;

public class ConstantExpression implements Expression {
    public ConstantExpression(int _value) {
        this._value = _value;
    }

    private int _value;

    @Override
    public int evaluate(IDictionary<String, Integer> st) {
        return _value;
    }

    @Override
    public String toString () {
        return "" + _value;
    }
}
