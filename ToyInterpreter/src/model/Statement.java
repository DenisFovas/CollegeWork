package model;

public interface Statement {
    ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException;
}
