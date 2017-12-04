package model;

import java.io.BufferedReader;

public class FileData {
    private java.lang.String _filename;
    private BufferedReader _bufferedReader;

    public java.lang.String get_filename() {
        return _filename;
    }

    public void set_filename(java.lang.String _filename) {
        this._filename = _filename;
    }

    public BufferedReader get_bufferedReader() {
        return _bufferedReader;
    }

    public void set_bufferedReader(BufferedReader _bufferedReader) {
        this._bufferedReader = _bufferedReader;
    }

    public FileData(String filename, BufferedReader bufferedReader) {
        _filename = filename;
        _bufferedReader = bufferedReader;
    }
    public String toString() {
        return _filename;
    }
}
