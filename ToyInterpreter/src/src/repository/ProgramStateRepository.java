package repository;

import model.ProgramState;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.IDictionary;
import model.interfaces.Statement;
import repository.exceptions.InterpretorException;
import repository.exceptions.NoProgramException;
import repository.interfaces.IProgramStateRepository;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class ProgramStateRepository implements IProgramStateRepository {
    private ArrayList<ProgramState> _programStatesArray = new ArrayList<>();
    private ProgramState _programState;
    private String _fileName;

    public ProgramStateRepository(String fileName) {
        _fileName = fileName;
        _programState = null;
    }
    public ProgramStateRepository(ProgramState programState) {
        _programState = programState;
        _programStatesArray.add(_programState);
        _fileName = "";
    }
    public ProgramStateRepository(ProgramState programState, String _fileName) {
        _programState = programState;
        this._programStatesArray = new ArrayList<>();
        _programStatesArray.add(_programState);
        this._fileName = _fileName;
    }

    @Override
    public void addProgramState(ProgramState p) {
        _programStatesArray.add(p);
    }

    @Override
    public ProgramState getCurrentProgram() throws NoProgramException {
        if (_programStatesArray.size() > 0) {
            return _programStatesArray.get(_programStatesArray.size() - 1);
        } else {
            throw new NoProgramException("No program in the stack. Please insert a program in the stack.");
        }
    }

    @Override
    public void logProgramStateExecution() throws InterpretorException {
        try {
            // We get the current program
            ProgramState p = getCurrentProgram();
            try (PrintWriter f = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter(
                                    _fileName, true
                            )
                    )
            )) {
                // Print the execution stack
                f.println("Execution Stack");
                for (Statement s : p.get_executionStack().getAll()) {
                    f.println(s);
                }
                // Print the symbol table
                f.println("Symbol Table");
                IDictionary<String, Integer> tmp = p.get_symbolTable();
                for (String s : tmp.getAll()) {
                    f.println(s + " + " + tmp.get(s));
                }
                // Print the Message list
                f.println("Message List");
                for (Integer s : p.get_messages().getAll()) {
                    f.println(s);
                }
                f.println("Heap");
                for (Integer s : p.get_heap().getAll()) {
                    f.println(s);
                }
                f.println("#######################################");
                f.close();
            } catch (IOException | KeyNotInsertedException e) {
                throw new InterpretorException();
            }
        } catch (NoProgramException e) {
            throw new InterpretorException();
        }
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (ProgramState a_programStatesArray : _programStatesArray) {
            buffer.append(a_programStatesArray.toString());
        }
        return buffer.toString();
    }
}
