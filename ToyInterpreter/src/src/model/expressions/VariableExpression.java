package model.expressions;

import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.IHeap;

public class VariableExpression implements Expression {
    public VariableExpression(String _variableName) {
        this._variableName = _variableName;
    }

    private String _variableName;

    @Override
    public int evaluate(IDictionary<String, Integer> st, IHeap<Integer, Integer> heap) throws KeyNotInsertedException {
        try {
            if (st.contains(_variableName)) {
                return st.get(_variableName);
            }
        } catch (KeyNotInsertedException exception) {
            throw new KeyNotInsertedException(exception.getMessage());
        }
        return -1;
    }

    @Override
    public String toString() {
        return _variableName;
    }
}
