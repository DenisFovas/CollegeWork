package model.statement;

import model.ProgramState;
import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.Statement;

public class AssignStatement implements Statement {
    public AssignStatement(String _variableName, Expression _expr) {
        this._variableName = _variableName;
        this._expr = _expr;
    }

    private String _variableName;
    private Expression _expr;

    @Override
    public ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException {
        IDictionary<String, Integer> st = programState.get_symbolTable();
        try {
            int element = _expr.evaluate(st, programState.get_heap());
            if (st.contains(_variableName)) {
                st.update(_variableName, element);
            } else {
                st.add(_variableName, element);
            }
        } catch (DivisionByZeroException exception) {
            throw new DivisionByZeroException(exception.getMessage());
        }

        programState.set_symbolTable(st);
        return programState;
    }

    @Override
    public String toString() {
        return "" + _variableName + " = " + _expr;
    }
}
