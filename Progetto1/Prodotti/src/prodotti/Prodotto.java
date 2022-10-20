/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package prodotti;

/**
 *
 * @author patap
 */
public class Prodotto {
    
    private String codice, nome;
    private double prezzo;
    private static int numProdotti;

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

    public void stampa() {
        System.out.println("Prodotto: " + "\ncodice: " + codice + "\nnome: " + nome + "\nprezzo: " + prezzo + '\n');
        
    }
            

    
}
