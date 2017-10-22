package model;

public class ProgramState {
    private IExecutionStack<Statement> _executionStack;
    private IDictionary<String, Integer> _symbolTable;
    private IList<Integer> _messages;
    private Statement _rootProgram;

    public ProgramState(IExecutionStack<Statement> _executionStack, IDictionary<String, Integer> _symbolTable,
                        IList<Integer> _messages, Statement _rootProgram) {
        this._executionStack = _executionStack;
        this._symbolTable = _symbolTable;
        this._messages = _messages;
        this._rootProgram = _rootProgram;
    }

    public IExecutionStack<Statement> get_executionStack() {
        return _executionStack;
    }

    public void set_executionStack(IExecutionStack<Statement> _executionStack) {
        this._executionStack = _executionStack;
    }

    public IDictionary<String, Integer> get_symbolTable() {
        return _symbolTable;
    }

    public void set_symbolTable(IDictionary<String, Integer> _symbolTable) {
        this._symbolTable = _symbolTable;
    }

    public IList<Integer> get_messages() {
        return _messages;
    }

    public void set_messages(IList<Integer> _messages) {
        this._messages = _messages;
    }

    public Statement get_rootProgram() {
        return _rootProgram;
    }

    public void set_rootProgram(Statement _rootProgram) {
        this._rootProgram = _rootProgram;
    }



    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        buffer.append("Execution stack: \n { " + _executionStack.toString() + "};\n");
        buffer.append("Symbol table: \n" + _symbolTable.toString() + "\n");
        buffer.append("Messages: \n" + _messages.toString() + "\n");
        buffer.append("Root Program: \n" + _rootProgram.toString() + "\n");

        return buffer.toString();
    }
}
