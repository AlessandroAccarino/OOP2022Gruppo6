/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.veicoli;

/**
 *
 * @author patap
 */
public class Moto extends Veicolo{
    private boolean guidaLibera;
            
    public Moto(String numTelaio, String modello, String alimentazione, String targa, boolean guidaLibera){
        super(numTelaio, modello, alimentazione, targa);
                this.guidaLibera = guidaLibera;
    }
           
    public boolean getGuidaLibera(){
        guidaLibera = false;
        return guidaLibera;
    }
    
    @Override
    public boolean controllaTarga(){

        if (getTarga().length() != 7){
            
            return false;
        }
                    
       for(int i=0; i < 2; i++){
          
             char c = getTarga().charAt(i);  
              if(!(c >= 'A' && c <='Z')){
                  
                  return false;
              } 
           
       }
       
       for(int i=2; i < 7; i++){
           
              char c = getTarga().charAt(i);  
              if(!(c >= '0' && c <='9')){
                  
                  return false;
              }  
           
       }
          
        return true;
    }
    
    
    @Override
    public String toString() {
        return "\nMoto: \n" + super.toString()+"Guida libera: " +guidaLibera+"\n";
    }
   
    
}
