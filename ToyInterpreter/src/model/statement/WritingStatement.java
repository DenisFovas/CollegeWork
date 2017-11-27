package model.statement;

import model.ProgramState;
import model.exceptions.DivisionByZeroException;
import model.exceptions.InvalidAddressException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IHeap;
import model.interfaces.Statement;
import repository.exceptions.InterpretorException;

public class WritingStatement implements Statement{
    private String _varName;
    private Expression expression;

    public WritingStatement(String _varName, Expression expression) {
        this._varName = _varName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException, InterpretorException, InvalidAddressException {
        IHeap<Integer, Integer> heap = programState.get_heap();

        if (heap.contains(programState.get_symbolTable().get(_varName))) {
            heap.update(programState.get_symbolTable().get(_varName), expression.evaluate(
                    programState.get_symbolTable(), heap
            ));
        } else {
            throw new InvalidAddressException();
        }
        return programState;
    }
}
