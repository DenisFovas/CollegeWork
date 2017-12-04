package model.statement;

import model.ProgramState;
import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IHeap;
import model.interfaces.Statement;
import repository.exceptions.InterpretorException;

public class NewStatement implements Statement {
    private String _varName;
    private Expression _expr;

    public NewStatement(String var, Expression e) {
        _varName = var;
        _expr = e;
    }

    @Override
    public String toString() {
        return "NewStatement{" +
                "_varName='" + _varName + '\'' +
                ", _expr=" + _expr +
                '}';
    }

    @Override
    public ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException, InterpretorException {
        IHeap<Integer, Integer> heap = programState.get_heap();
        int position = heap.add(_expr.evaluate(programState.get_symbolTable(), heap));
        if (programState.get_symbolTable().contains(_varName)) {
            programState.get_symbolTable().update(_varName, position);
        }
        programState.get_symbolTable().add(_varName, position);
        return programState;
    }
}
