/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package veicoli;

import it.unisa.diem.oop22.veicoli.*;

/**
 *
 * @author patap
 */
public class TestVeicoli {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]){

        Veicolo v;
        System.out.println("Test 1: camion con targa valida");
        v = new Camion("sdf244", "Fiat CX45", "Gasolio", "TT656671", 4);
        System.out.println(v);
        System.out.println("Targa valida? " + v.controllaTarga() + "\n\n");

        System.out.println("Test 2: camion con targa non valida");
        v = new Camion("spl265", "Volvo PTG", "Gasolio", "YH96671", 6);
        System.out.println(v);
        System.out.println("Targa valida? " + v.controllaTarga() + "\n\n");

        System.out.println("Test 3: autovettura con targa  valida");
        v = new Autovettura("mk23t", "Fiat Punto", "Metano", "EA566FM", 5);
        System.out.println(v);
        System.out.println("Targa valida? " + v.controllaTarga() + "\n\n");

        System.out.println("Test 4: autovettura con targa non valida");
        v = new Autovettura("cgt612", "Fiat Idea", "Gasolio", "AQ9Y7UUU", 5);
        System.out.println(v);
        System.out.println("Targa valida? " + v.controllaTarga() + "\n\n");

        System.out.println("Test 5: moto con targa  valida");
        v = new Moto("das7896", "Honda Hornet", "Benzina", "AT51233", false);
        System.out.println(v);
        System.out.println("Targa valida? " + v.controllaTarga() + "\n\n");

        System.out.println("Test 6: moto con targa non valida");
        v = new Moto("gdt7896", "Suzuki Bandit", "Benzina", "AT5123N", false);
        System.out.println(v);
        System.out.println("Targa valida? " + v.controllaTarga() + "\n\n");

    }
}
