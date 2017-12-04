package repository.interfaces;

import model.ProgramState;
import repository.ProgramStateRepository;
import repository.exceptions.InterpretorException;
import repository.exceptions.NoProgramException;

public interface IProgramStateRepository {
    void addProgramState(ProgramState p);
    ProgramState getCurrentProgram() throws NoProgramException;
    void logProgramStateExecution() throws InterpretorException;
}
