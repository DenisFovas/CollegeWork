package model.statement;


import model.ProgramState;
import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.Expression;
import model.interfaces.IDictionary;
import model.interfaces.IList;
import model.interfaces.Statement;

public class PrintStatement implements Statement {
    public PrintStatement(Expression _expression) {
        this._expression = _expression;
    }

    private Expression _expression;
    @Override
    public ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException {
        IDictionary<String, Integer> st = programState.get_symbolTable();
        try {
            int value = _expression.evaluate(st, programState.get_heap());

            IList<Integer> messageList = programState.get_messages();
            messageList.add(value);
            programState.set_messages(messageList);
        } catch (DivisionByZeroException exception) {
            throw new DivisionByZeroException(exception.getMessage());
        } catch (KeyNotInsertedException exception) {
            throw new KeyNotInsertedException(exception.getMessage());
        }
        // Maybe we don't need to set the symbol table.
//        programState.set_symbolTable(st);
        return programState;
    }

    @Override
    public String toString() {
        return "Print(" + _expression + ')';
    }
}
