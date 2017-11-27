package model.expressions;

import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.IHeap;

public class ArithmeticExpression implements Expression {
    public ArithmeticExpression(char _operator, Expression _leftSide, Expression _rightSide) {
        this._operator = _operator;
        this._leftSide = _leftSide;
        this._rightSide = _rightSide;
    }

    private char _operator;
    private Expression _leftSide;
    private Expression _rightSide;

    @Override
    public int evaluate(IDictionary<String, Integer> st,  IHeap<Integer, Integer> heap) throws DivisionByZeroException, KeyNotInsertedException {
        try {
            int left = _leftSide.evaluate(st, heap);
            int right = _rightSide.evaluate(st, heap);

            switch (_operator) {
                case '+': {
                    return left + right;
                }
                case '-': {
                    return left - right;
                }
                case '*': {
                    return left * right;
                }
                case '/': {
                    if (right == 0) {
                        throw new DivisionByZeroException("Error: Can't divide by zero.");
                    }
                    return left / right;
                }
                default: {
                    throw new RuntimeException("Unknown operation");
                }

            }
        } catch (KeyNotInsertedException exception) {
            throw new KeyNotInsertedException(exception.getMessage());
        }
    }

    @Override
    public String toString() {
        return "" + _leftSide + " " + _operator + " " + _rightSide;
    }
}
