package model.interfaces;

public interface IList<T> {
    void add(T element);
    Iterable<T> getAll();
}
