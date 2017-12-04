package model.statement;

import model.ProgramState;
import model.interfaces.Statement;

public class ComposedStatement implements Statement {
    private Statement _first;
    private Statement _second;

    public ComposedStatement(Statement _first, Statement _second) {
        this._first = _first;
        this._second = _second;
    }


    @Override
    public ProgramState execute(ProgramState programState) {
        programState.get_executionStack().push(_second);
        programState.get_executionStack().push(_first);
        return programState;
    }

    @Override
    public String toString() {
        return "(" + _first + "; " + _second + ");";
    }
}
