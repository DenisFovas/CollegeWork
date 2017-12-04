package model.interfaces;

public interface IFileTable<K, V> {
    void add(K k, V v);
    void remove(K k);
    V find(K k);
    boolean contains(K k);
    Iterable<K> getAll();
    Iterable<V> getValues();
}
