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
    private String _fileName;

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
    public void logProgramStateExecution(ProgramStateRepository a) throws InterpretorException {
        try {
            ProgramState p = a.getCurrentProgram();
            try (PrintWriter f = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter(
                                    _fileName
                            )
                    )
            )) {
                f.println("Execution Stack");
                for (Statement s : p.get_executionStack().getAll()) {
                    f.println(s);
                }
                f.println("Symbol Table");
                IDictionary<String, Integer> tmp = p.get_symbolTable();
                for (String s : tmp.getAll()) {
                    //TODO: Catch tmp.get exception
                    f.println(s + " + " + tmp.get(s));
                }
                f.println("List");
                for (Integer s : p.get_messages().getAll()) {
                    f.println(s);
                }
            } catch (IOException | KeyNotInsertedException e) {
                throw new InterpretorException();
            }
        } catch (NoProgramException e) {
            throw new InterpretorException();
        }
        ;    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < _programStatesArray.size(); i++) {
            buffer.append(_programStatesArray.get(i).toString());
        }
        return buffer.toString();
    }
}
