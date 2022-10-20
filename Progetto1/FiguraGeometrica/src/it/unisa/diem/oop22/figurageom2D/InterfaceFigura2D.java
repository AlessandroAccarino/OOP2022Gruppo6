/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.figurageom2D;

/**
 *
 * @author patap
 */
public interface InterfaceFigura2D {
    
    public void setPosizione(int x, int y);
    
    public Punto2D getPosizione();
    
    public double calcolaArea();
   
    public void stampaInfo();
    
}
