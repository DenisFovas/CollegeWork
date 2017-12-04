package controller;

import model.*;
import model.exceptions.DivisionByZeroException;
import model.exceptions.EmptyStackException;
import model.exceptions.InvalidAddressException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.IExecutionStack;
import model.interfaces.Statement;
import repository.exceptions.InterpretorException;
import repository.exceptions.NoProgramException;
import repository.ProgramStateRepository;

import java.util.Collection;
import java.util.Map;
import java.util.stream.Collectors;


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
                } catch (InterpretorException | InvalidAddressException e) {
                    e.printStackTrace();
                }
            } catch (EmptyStackException exception) {
                throw new EmptyStackException(exception.getMessage());
            }
        } catch (NoProgramException exception) {
            throw new NoProgramException(exception.getMessage());
        }
    }
    private Map<Integer, Integer> garbageCollector(Collection<Integer> symTableValues, Map<Integer, Integer> heap) {
        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }


    public ProgramStateRepository get_repository() {
        return _repository;
    }

    public void executeAll() throws DivisionByZeroException, EmptyStackException, KeyNotInsertedException, NoProgramException, InvalidAddressException, InterpretorException {
        try {
            ProgramState programState = _repository.getCurrentProgram();
            while (!programState.get_executionStack().isEmpty()) {
                try {
                    Statement statement = programState.get_executionStack().pop();
                    try {
                        programState.get_heap().set_map(garbageCollector(
                                programState.get_symbolTable().getValues(),
                                programState.get_heap().get_map()
                        ));
                        _repository.logProgramStateExecution();
                        statement.execute(programState);
                    } catch (DivisionByZeroException exception) {
                        throw new DivisionByZeroException(exception.getMessage());
                    } catch (KeyNotInsertedException exception) {
                        throw new KeyNotInsertedException(exception.getMessage());
                    } catch (InterpretorException e) {
                        throw new InterpretorException();
                    } catch (InvalidAddressException e) {
                        throw new InvalidAddressException();
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
