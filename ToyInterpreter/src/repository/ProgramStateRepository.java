package repository;

import model.ProgramState;

import java.util.ArrayList;

public class ProgramStateRepository implements IProgramStateRepository {
    private ArrayList<ProgramState> _programStatesArray = new ArrayList<>();

    @Override
    public void addProgramState(ProgramState p) {
        _programStatesArray.add(p);
    }

    @Override
    public ProgramState getCurrentProgram() throws NoProgramException {
        if (_programStatesArray.size() > 0) {
            return _programStatesArray.get(0);
        } else {
            throw new NoProgramException("No program in the stack. Please insert a program in the stack.");
        }
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < _programStatesArray.size(); i++) {
            buffer.append(_programStatesArray.get(i).toString());
        }
        return buffer.toString();
    }
}
