/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model.interfaces;

import model.exceptions.KeyNotInsertedException;

import java.util.Collection;

/**
 *
 * @author fovas
 */
public interface IDictionary <K, V> {
    boolean contains(K key);
    V get(K key) throws KeyNotInsertedException;
    void update(K key, V value);
    void add(K key, V value);
    Iterable<K> getAll();
    Collection<V> getValues();
}