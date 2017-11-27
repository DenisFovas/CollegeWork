package model;

import model.interfaces.IFileTable;

import java.util.HashMap;

public class FileTable<K, V> implements IFileTable<K, V> {
    private HashMap<K, V> _dictionary;
    public FileTable() {
        _dictionary = new HashMap<>();
    }
    @Override
    public void add(K key, V value) {
        _dictionary.put(key, value);
    }

    @Override
    public void remove(K k) {
        _dictionary.remove(k);
    }

    @Override
    public V find(K k) {
        return _dictionary.get(k);
    }

    @Override
    public boolean contains(K k) {
        return _dictionary.containsKey(k);
    }

    @Override
    public Iterable<K> getAll() {
        return _dictionary.keySet();
    }

    @Override
    public Iterable<V> getValues() {
        return _dictionary.values();
    }
}
