/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model.interfaces;

import model.exceptions.EmptyStackException;

/**
 *
 * @author fovas
 */
public interface IExecutionStack<T> {
    void push(T element);
    T pop() throws EmptyStackException;
    boolean isEmpty();
    Iterable<T> getAll();
}
