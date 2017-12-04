package model.interfaces;

import java.util.Collection;
import java.util.Map;

public interface IHeap<K, V> {
    K add(V v);
    void remove(K k);
    V find(K k);
    void update(K k, V v);
    boolean contains(V v);
    Collection<K> getAll();
    Collection<V> getValues();
    void set_map(Map<K, V> map);
    Map<K, V> get_map();
}
