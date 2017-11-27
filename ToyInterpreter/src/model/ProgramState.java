package model;

import model.interfaces.*;


public class ProgramState {
    private IExecutionStack<Statement> _executionStack;
    private IDictionary<java.lang.String, Integer> _symbolTable;
    private IList<Integer> _messages;
    private Statement _rootProgram;
    private FileTable<Integer, FileData> _fileTable;
    private IHeap<Integer, Integer> _heap;



    public ProgramState(IExecutionStack<Statement> _executionStack, IDictionary<java.lang.String, Integer> _symbolTable,
                        IList<Integer> _messages, Statement _rootProgram,
                        IHeap<Integer, Integer> heap) {
        this._executionStack = _executionStack;
        this._symbolTable = _symbolTable;
        this._messages = _messages;
        this._rootProgram = _rootProgram;
        this._heap = heap;
    }

    public IHeap<Integer, Integer> get_heap() {
        return _heap;
    }

    public void set_heap(IHeap<Integer, Integer> _heap) {
        this._heap = _heap;
    }


    public IExecutionStack<Statement> get_executionStack() {
        return _executionStack;
    }

    public void set_executionStack(IExecutionStack<Statement> _executionStack) {
        this._executionStack = _executionStack;
    }

    public FileTable<Integer, FileData> get_fileTable() {
        return _fileTable;
    }

    public void set_fileTable(FileTable<Integer, FileData> _fileTable) {
        this._fileTable = _fileTable;
    }

    public IDictionary<java.lang.String, Integer> get_symbolTable() {
        return _symbolTable;
    }

    public void set_symbolTable(IDictionary<java.lang.String, Integer> _symbolTable) {
        this._symbolTable = _symbolTable;
    }

    public IList<Integer> get_messages() {
        return _messages;
    }

    public void set_messages(IList<Integer> _messages) {
        this._messages = _messages;
    }

    public void set_rootProgram(Statement _rootProgram) {
        this._rootProgram = _rootProgram;
    }

    public Statement get_rootProgram() {
        return _rootProgram;
    }


    @Override
    public java.lang.String toString() {
        StringBuffer buffer = new StringBuffer();
        buffer.append("Execution stack: \n { " + _executionStack.toString() + "};\n");
        buffer.append("Symbol table: \n" + _symbolTable.toString() + "\n");
        buffer.append("Messages: \n" + _messages.toString() + "\n");
        buffer.append("Root Program: \n" + _rootProgram.toString() + "\n");
        buffer.append("Heap: \n" + _heap.toString());

        return buffer.toString();
    }
}
