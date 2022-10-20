/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.veicoli;

/**
 *
 * @author patap
 */
public abstract class Veicolo{
    
    private String numTelaio;
    private String modello;
    private String alimentazione;
    private String targa;

    public Veicolo(String numTelaio, String modello, String alimentazione, String targa) {
        this.numTelaio = numTelaio;
        this.modello = modello;
        this.alimentazione = alimentazione;
        this.targa = targa;
      
    }

    public String getNumTelaio() {
        return numTelaio;
    }

    public String getModello() {
        return modello;
    }

    public String getAlimentazione() {
        return alimentazione;
    }

    public String getTarga() {
        return targa;
    }

    public void setTarga(String targa) {
        this.targa = targa;
    }
    
   public abstract boolean controllaTarga();
    
    @Override
    public String toString() {
        return "###" + "\nnumTelaio: " + numTelaio + "\nmodello: " + modello + "\nalimentazione: " + alimentazione+ "\ntarga: " + targa +"\n";
    }
   
}
