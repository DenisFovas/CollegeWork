package model;

public class IfStatement implements Statement {
    private Expression _condition;
    private Statement _then;
    private Statement _else;

    public IfStatement(Expression _condition, Statement _then, Statement _else) {
        this._condition = _condition;
        this._then = _then;
        this._else = _else;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException {
        try {
            int conditionResult = _condition.evaluate(programState.get_symbolTable());
            if (conditionResult != 0) {
                programState.get_executionStack().push(_then);
            } else {
                programState.get_executionStack().push(_else);
            }
        } catch (DivisionByZeroException exception) {
            throw new DivisionByZeroException(exception.getMessage());
        } catch (KeyNotInsertedException exception) {
            throw new KeyNotInsertedException(exception.getMessage());
        }
        return programState;
    }
    @Override
    public String toString() {
        return "IF " + _condition + " THEN " + _then + " ELSE " + _else;
    }
}
