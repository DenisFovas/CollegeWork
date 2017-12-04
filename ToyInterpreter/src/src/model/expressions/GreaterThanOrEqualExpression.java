package model.expressions;

import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.IHeap;

public class GreaterThanOrEqualExpression implements Expression{
    private Expression _expr1;

    public Expression get_expr1() {
        return _expr1;
    }

    public void set_expr1(Expression _expr1) {
        this._expr1 = _expr1;
    }

    public Expression get_expr2() {
        return _expr2;
    }

    public void set_expr2(Expression _expr2) {
        this._expr2 = _expr2;
    }

    public GreaterThanOrEqualExpression(Expression _expr1, Expression _expr2) {

        this._expr1 = _expr1;
        this._expr2 = _expr2;
    }

    private Expression _expr2;

    @Override
    public String toString() {
        return _expr1.toString() + " >= " + _expr2.toString();
    }

    @Override
    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer, Integer> heap) throws DivisionByZeroException, KeyNotInsertedException {
        int a = _expr1.evaluate(st, heap);
        int b = _expr2.evaluate(st, heap);
        if (a >= b)
            return 1;
        else
            return 0;
    }
}
