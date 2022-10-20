/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.box;

import it.unisa.diem.oop22.veicoli.Veicolo;

/**
 *
 * @author patap
 */
public class Autorimessa extends Box {

    private Veicolo Veicoli[];
    private int testa;
    private int coda;
    private int riemp = 0;
    
    public Autorimessa(int maxPosti, String nome) {
        super(maxPosti, nome);
      
        this.testa = 0;
        this.coda = 0;
        this.riemp = 0;
        Veicoli = new Veicolo[maxPosti];
      
    }

    // Traccia chiede private
    private boolean autorimessaPiena(){
       
       return riemp == maxPosti;
    }
    
    // Traccia chiede private
    private boolean autorimessaVuota(){
       
       return riemp == 0;
    }
    
    @Override
    public void entra(Veicolo v) throws AutoRimessaPienaException, TargaNonValidaException {
    
        if (!v.controllaTarga())
             throw new TargaNonValidaException("Attenzione! Targa non valida");

        
        if(autorimessaPiena())
             throw new AutoRimessaPienaException("Attenzione! Autorimessa piena");


        Veicoli[coda] = v;
        riemp++;

        coda = (coda+1) % maxPosti;  
              
    }

    @Override
    public Veicolo esce() throws AutoRimessaVuotaException {

      
        if(autorimessaVuota())
            throw new AutoRimessaVuotaException("Attenzione! Autorimessa vuota");

        
        Veicolo v = Veicoli[testa];
        Veicoli[testa] = null;
        
        riemp--;
        testa = (testa+1) % maxPosti;
        
        
        return v;
    }
    
    @Override
    public String toString() {
         
    String s= super.toString();
        
        if(autorimessaVuota()){
            
            System.out.println("L'auto rimessa è vuota");
            return s;
        }
        
        s+= "\nVeicoli presenti:\n";
        for(int i=0; i<riemp; i++){
            
            s+= Veicoli[(testa+ i) % maxPosti];            
        }
        return s;
    
    }
    
}
