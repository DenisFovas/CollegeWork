/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 *
 * @author fovas
 */
public class ExecutionStack<T> implements IExecutionStack<T> {

    private Deque<T> _stack = new ArrayDeque<T>();
    
    @Override
    public void push(T element) {
        _stack.push(element);
    }

    @Override
    public T pop() throws EmptyStackException {
        if (_stack.size() != 0) {
            return _stack.pop();
        } else {
            throw new EmptyStackException("Error: the stack is empty.");
        }
    }

    @Override
    public boolean isEmpty() {
        return (_stack.size() == 0);
    }
    
    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (T element : _stack) {
            buffer.append("\t" + element + "\n");
        }
        return buffer.toString();
    }
}
