package model.interfaces;

import model.exceptions.DivisionByZeroException;
import model.exceptions.EmptyStackException;
import model.exceptions.InvalidAddressException;
import model.exceptions.KeyNotInsertedException;
import model.ProgramState;
import repository.exceptions.InterpretorException;

public interface Statement {
    ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException, InterpretorException, InvalidAddressException, EmptyStackException;
}
