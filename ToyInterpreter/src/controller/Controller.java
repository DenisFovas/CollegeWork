package controller;

import model.*;
import repository.NoProgramException;
import repository.ProgramStateRepository;


public class Controller {
    private ProgramStateRepository _repository;
    public Controller(ProgramStateRepository _repository) {
        this._repository = _repository;
    }

    public void executeOneStep() throws DivisionByZeroException, EmptyStackException, KeyNotInsertedException, NoProgramException {
        try {
            ProgramState oneStep = _repository.getCurrentProgram();
            IExecutionStack<Statement> executionStack = oneStep.get_executionStack();
            try {
                Statement statement = executionStack.pop();
                try {
                    statement.execute(oneStep);
                } catch (DivisionByZeroException exception) {
                    throw new DivisionByZeroException(exception.getMessage());
                } catch (KeyNotInsertedException exception) {
                    throw new KeyNotInsertedException(exception.getMessage());
                }
            } catch (EmptyStackException exception) {
                throw new EmptyStackException(exception.getMessage());
            }
        } catch (NoProgramException exception) {
            throw new NoProgramException(exception.getMessage());
        }
    }

    public ProgramStateRepository get_repository() {
        return _repository;
    }

    public void executeAll() throws DivisionByZeroException, EmptyStackException, KeyNotInsertedException, NoProgramException {
        try {
            ProgramState programState = _repository.getCurrentProgram();
            while (!programState.get_executionStack().isEmpty()) {
                try {
                    Statement statement = programState.get_executionStack().pop();
                    try {
                        statement.execute(programState);
                    } catch (DivisionByZeroException exception) {
                        throw new DivisionByZeroException(exception.getMessage());
                    } catch (KeyNotInsertedException exception) {
                        throw new KeyNotInsertedException(exception.getMessage());
                    }
                } catch (EmptyStackException exception) {
                    throw new EmptyStackException(exception.getMessage());
                }
            }
        } catch (NoProgramException e) {
            throw new NoProgramException(e.getMessage());
        }
    }

    public ProgramState getCurrentState() throws NoProgramException {
        try {
            return _repository.getCurrentProgram();
        } catch (NoProgramException e) {
            throw new NoProgramException(e.getMessage());
        }
    }

    @Override
    public String toString() {
        return _repository.toString();
    }
}
