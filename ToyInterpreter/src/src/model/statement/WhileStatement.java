package model.statement;

import model.ProgramState;
import model.exceptions.DivisionByZeroException;
import model.exceptions.EmptyStackException;
import model.exceptions.InvalidAddressException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.IHeap;
import model.interfaces.Statement;
import repository.exceptions.InterpretorException;


public class WhileStatement implements Statement{
    private Expression _condition;
    private Statement _execution;

    public Expression get_condition() {
        return _condition;
    }

    public void set_condition(Expression _condition) {
        this._condition = _condition;
    }

    public Statement get_execution() {
        return _execution;
    }

    public void set_execution(Statement _execution) {
        this._execution = _execution;
    }

    public WhileStatement(Expression _condition, Statement _execution) {

        this._condition = _condition;
        this._execution = _execution;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException, InterpretorException, InvalidAddressException, EmptyStackException {
        IDictionary<String, Integer> symbolTable = programState.get_symbolTable();
        IHeap<Integer, Integer> heap = programState.get_heap();
        if (_condition.evaluate(symbolTable, heap) != 0) {
//            _execution.execute(programState);
//            programState.get_executionStack().push(new WhileStatement(_condition, _execution));
            programState.get_executionStack().push(new WhileStatement(_condition, _execution));
            programState.get_executionStack().push(_execution);
        }
        return programState;
    }

    public String toString() {
        return "While (" + _condition + ") {" + _execution + "} ";
    }
}
