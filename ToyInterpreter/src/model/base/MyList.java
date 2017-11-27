package model.base;

import model.interfaces.IList;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements IList<T> {
    private List<T> _list = new ArrayList<T>();
    @Override
    public void add(T element) {
        _list.add(element);
    }
    @Override
    public Iterable<T> getAll() {
        return _list;
    }
    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (T element : _list) {
            buffer.append("\t" + element.toString() + "\n");
        }
        return buffer.toString();
    }
}
