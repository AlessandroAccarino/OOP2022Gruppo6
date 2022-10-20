/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Exception.java to edit this template
 */
package it.unisa.diem.oop22.box;

/**
 *
 * @author patap
 */
public class TargaNonValidaException extends BoxException {

    /**
     * Creates a new instance of <code>TargaNonValidaException</code> without
     * detail message.
     */
    public TargaNonValidaException() {
    }

    /**
     * Constructs an instance of <code>TargaNonValidaException</code> with the
     * specified detail message.
     *
     * @param msg the detail message.
     */
    public TargaNonValidaException(String msg) {
        super(msg);
    }
}
