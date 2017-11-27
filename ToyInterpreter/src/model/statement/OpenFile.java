package model.statement;

import model.FileData;
import model.IDGenerator;
import model.ProgramState;
import model.exceptions.DivisionByZeroException;
import model.exceptions.KeyNotInsertedException;
import model.interfaces.IFileTable;
import model.interfaces.Statement;
import repository.exceptions.InterpretorException;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class OpenFile implements Statement{
    private java.lang.String _varName;
    private java.lang.String _fileId;
    public OpenFile(java.lang.String u, java.lang.String id) {
        _varName = u;
        _fileId = id;
    }
    @Override
    public ProgramState execute(ProgramState programState) throws DivisionByZeroException, KeyNotInsertedException, InterpretorException {
        if (_isOpen(programState)) {
            throw new InterpretorException("File already opened.");
        }
        try {
            BufferedReader r = new BufferedReader(new FileReader(_varName));
            FileData fileData = new FileData(_varName, r);
            int id = IDGenerator.generateID();
            programState.get_fileTable().add(id, fileData);
            if (programState.get_symbolTable().contains(_fileId)) {
                programState.get_symbolTable().update(_fileId, id);
            } else {
                programState.get_symbolTable().add(_fileId, id);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
         return programState;
    }
    private boolean _isOpen(ProgramState ps) {
//        IFileTable fileTable = ps.get_fileTable();
//         TODO: Not Gud. Rework this.
//        for (Object fd : fileTable.getValues()) {
////            if (fd.get_filename().equals(_varName)) {
////                return true;
////            }
//        }
        return false;
    }
}
