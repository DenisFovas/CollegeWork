package model.base;

import model.interfaces.IHeap;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Heap<V> implements IHeap<Integer, V> {
    private Map<Integer, V> _map;
    private int _nextNewFree = 1;

    public Heap(){
        _map = new HashMap<>();
    }


    @Override
    public void set_map(Map<Integer, V> map) {
        _map = map;
    }

    @Override
    public Integer add(V v) {
        _map.put(_nextNewFree, v);
        return _nextNewFree++;
    }

    @Override
    public void remove(Integer k) {
        _map.remove(k);
    }

    @Override
    public V find(Integer k) {
        return _map.get(k);
    }

    @Override
    public void update(Integer integer, V v) {
        _map.put(integer, v);
    }

    @Override
    public boolean contains(V v) {
        return _map.containsValue(v);
    }

    @Override
    public Map<Integer, V> get_map() {
        return _map;
    }

    @Override
    public Collection<Integer> getAll() {
        return _map.keySet();
    }

    @Override
    public Collection<V> getValues() {
        return _map.values();
    }

    @Override
    public String toString() {
        StringBuffer bs = new StringBuffer();
        for (Integer k : _map.keySet()) {
            bs.append("Key: ").append(k).append("; Value: ");
            bs.append(_map.get(k));
        }
        return bs.toString();
    }
}
