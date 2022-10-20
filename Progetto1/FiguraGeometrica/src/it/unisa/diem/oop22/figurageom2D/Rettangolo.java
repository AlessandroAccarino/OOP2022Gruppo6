/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.figurageom2D;

/**
 *
 * @author patap
 */
public class Rettangolo extends Figura2D {

    private double base, altezza;
    
    public Rettangolo(int x, int y, double base, double altezza) {
        super(x, y);
        
        this.base = base;
        this.altezza = altezza;
        
    }

    @Override
    public double calcolaArea() {

        return base*altezza;

    }
    
    @Override
    public void stampaInfo(){
        
        super.stampaInfo();
        System.out.println("Base: "+ base +"\naltezza: " + altezza);
        
    }
    
    
}
