/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.prodotti;

/**
 *
 * @author Portatile
 */
public class ProdottoNonAlimentare extends Prodotto{
    
    private String materiale;
    private boolean riciclabile;

    public ProdottoNonAlimentare(String codice, String nome, double prezzo, String materiale, boolean riciclabile) {
        super(codice, nome, prezzo);
        this.riciclabile = riciclabile;
        this.materiale = materiale;
    }


    
    @Override
    public double applicaSconto(double prezzo){
        if(riciclabile){
                prezzo = prezzo - ((prezzo*10)/100);
        }
        return prezzo;
    }
    
    @Override
    public String toString() {  
        return super.toString() + ", materiale=" + materiale + ", riciclabile="+ riciclabile +'\n';   
    }
    
}
