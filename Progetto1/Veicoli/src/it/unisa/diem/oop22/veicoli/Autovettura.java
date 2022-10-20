/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.veicoli;

/**
 *
 * @author patap
 */
public class Autovettura extends Veicolo {
   
    private int numeroPosti;

    public Autovettura(String numTelaio, String modello, String alimentazione, String targa, int numeroPosti) {
        super(numTelaio, modello, alimentazione, targa);
        this.numeroPosti = numeroPosti;
    }

    public int getNumeroPosti() {
        return numeroPosti;
    }
 
    @Override
    public boolean controllaTarga() {
                 
        if (getTarga().length() != 7){
            
            return false;
        } 
        
        for(int i=0; i < 2; i++){
          
             char c = getTarga().charAt(i);  
              if(!(c >= 'A' && c <='Z')){
                  
                  return false;
              } 
           
       }
       
       for(int i=2; i < 5; i++){
           
              char c = getTarga().charAt(i);  
              if(!(c >= '0' && c <='9')){
                  
                  return false;
              }  
           
       }
   
        for(int i=5; i < 7; i++){
           
              char c = getTarga().charAt(i);  
              if(!(c >= 'A' && c <='Z')){
                  
                  return false;
              }  
           
       }
       
       return true; 
    }
    
    @Override
    public String toString() {
        return "\nAutoVettura:\n" + super.toString()+"Numero posti: " +numeroPosti +"\n";

    
    }
    
}
