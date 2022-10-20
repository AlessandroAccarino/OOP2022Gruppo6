/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.prodotti;

/**
 *
 * @author patap
 */
public abstract class Prodotto {
    private String codice, nome;
    // è possibile evitare di usare get e setter se si imposta l'attributo come protected per permettere la modifica del 
    // prezzo da parte di tutte le sottoclassi
    private static double prezzo;
    private static int numProdotti;
    private String materiale;
    private String DataScadenza;
    
    public Prodotto(String codice, String nome, double prezzo) {
        this(codice,nome);
        this.prezzo = prezzo;
    }

        public Prodotto(String codice, String nome) {
        this.codice = codice;
        this.nome = nome;
        
        numProdotti++;
    }      
        
    public String getCodice() {
        return codice;
    }

    public void setCodice(String codice) {
        this.codice = codice;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    public static int getNumProdotti() {
        return numProdotti;
    }

    public static void setNumProdotti(int numProdotti) {
        Prodotto.numProdotti = numProdotti;
    }

    @Override
    public String toString() {
        return "Prodotto codice=" + codice + ", nome=" + nome + ", prezzo=" + prezzo;
        
    }
    
    public abstract double applicaSconto(double prezzo);
            

}
