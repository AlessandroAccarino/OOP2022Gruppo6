/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package oop14102022ah;

import it.unisa.diem.oop22.figurageom2D.*;

/**
 *
 * @author patap
 */
public class TestFiguraGeom2D {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        
InterfaceFigura2D[] f = new Figura2D[3]; 
                
        f[0] = new Cerchio(5, 7, 1.0);
        f[1] = new Rettangolo(2, 4, 3.5, 1.0);
        f[2] = new Trapezio(6, 1, 1.5, 2.5, 4.0);
        
        for(int i=0; i<3; i++){
            f[i].stampaInfo();
            System.out.println("Area: " + f[i].calcolaArea());
            System.out.println("Figura2D: " + f[i]);
        
    }
    
    }
}
