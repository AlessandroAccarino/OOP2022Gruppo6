/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.figurageom2D;

/**
 *
 * @author patap
 */
public class Trapezio extends Figura2D {

    private double baseMinore, baseMaggiore, altezza;

    public Trapezio( int x, int y, double baseMinore, double baseMaggiore, double altezza) {
        super(x, y);
        this.baseMinore = baseMinore;
        this.baseMaggiore = baseMaggiore;
        this.altezza = altezza;
    }
    


    @Override
    public double calcolaArea() {

        return (baseMinore+baseMaggiore)*altezza/2;
    }
    
    @Override
    public void stampaInfo(){
        
        super.stampaInfo();
        System.out.println("Base Maggiore: "+ baseMaggiore +"\nBase Minore: " + baseMinore + "\nAltezza: " + altezza);
        
    }    
    
    
}
