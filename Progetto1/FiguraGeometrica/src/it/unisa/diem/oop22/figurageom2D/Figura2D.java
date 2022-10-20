/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.figurageom2D;

/**
 *
 * @author patap
 */
public abstract class Figura2D implements InterfaceFigura2D {
    
    private Punto2D p;

    public Figura2D(int x, int y) {
        this.p = new Punto2D(x,y);
        
    }
    
    @Override
    public void setPosizione(int x, int y){
        
       p.setX(x);
       p.setY(y);
    }

    @Override
    public Punto2D getPosizione(){
        
        return new Punto2D(p.getX(), p.getY());
                      
    }
    
    @Override
    public void stampaInfo(){       
        
       System.out.println("\nPosizione: "+ p.toString());
        
    }   
        
}
