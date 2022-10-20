/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Exception.java to edit this template
 */
package it.unisa.diem.oop22.box;

/**
 *
 * @author patap
 */
public class BoxException extends Exception  {

    /**
     * Creates a new instance of <code>BoxException</code> without detail
     * message.
     */
    public BoxException() {
    }

    /**
     * Constructs an instance of <code>BoxException</code> with the specified
     * detail message.
     *
     * @param msg the detail message.
     */
    public BoxException(String msg) {
        super(msg);
    }
}
