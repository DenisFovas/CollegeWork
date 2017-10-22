/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author fovas
 */
public class Dictionary<K, V> implements IDictionary<K, V> {
    private Map<K, V> _dictionary = new HashMap<K, V>();
        
    @Override
    public boolean contains(K key) {
        return _dictionary.containsKey(key);
    }

    @Override
    public V get(K key) throws KeyNotInsertedException {
        if (_dictionary.containsKey(key)) {
            return _dictionary.get(key);
        } else {
            throw new KeyNotInsertedException("Error: The key does not exist in the Dictionary");
        }
    }

    @Override
    public void update(K key, V value) {
        _dictionary.put(key, value);
    }

    @Override
    public void add(K key, V value) {
        _dictionary.put(key, value);
    }
    
    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (Map.Entry<K, V> p : _dictionary.entrySet()) {
            buffer.append("\t" + p.getKey() + " -> " + p.getValue() + "\n");
        }
        return buffer.toString();
    }
}
