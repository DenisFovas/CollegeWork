package repository;

import model.ProgramState;

public interface IProgramStateRepository {
    void addProgramState(ProgramState p);
    ProgramState getCurrentProgram() throws NoProgramException;
}
