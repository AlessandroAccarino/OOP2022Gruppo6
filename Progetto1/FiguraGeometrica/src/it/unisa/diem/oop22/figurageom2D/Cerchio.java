/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.figurageom2D;

/**
 *
 * @author patap
 */
public class Cerchio extends Figura2D {
   
    private double raggio;

    public Cerchio(int x, int y, double raggio) {
        super(x, y);
        this.raggio = raggio;
    }

    @Override
    public double calcolaArea() {
        
        // Math.PI dovrebbe chiamare pi greco
        return raggio*raggio*Math.PI;
        
    }
    
    @Override
    public void stampaInfo(){
        
        super.stampaInfo();
        System.out.println("Raggio: "+ raggio);
        
    }    
    
}
