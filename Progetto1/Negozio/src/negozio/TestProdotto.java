/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package negozio;

import it.unisa.diem.oop.carrello.Carrello;
import it.unisa.diem.oop.prodotti.*;
import java.time.LocalDate;

/**
 *
 * @author patap
 */
public class TestProdotto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Prodotto p1 = new ProdottoAlimentare("A1", "pane", 2, LocalDate.of(2022, 10, 31));
        Prodotto p2 = new ProdottoAlimentare("A2", "latte", 2, LocalDate.of(2022, 10, 18));
        Prodotto p3 = new ProdottoNonAlimentare("N3", "piatti", 2, "plastica", false);
        Prodotto p4 = new ProdottoNonAlimentare("N4", "bicchieri", 2, "carta", true);

        Carrello c = new Carrello();

        c.aggiungi(p1);
        c.aggiungi(p2);
        c.aggiungi(p3);
        c.aggiungi(p4);

        System.out.println(c);

        System.out.println("Il totale scontato è: " + c.calcolaTotaleScontato()); 
        
        
    }
    
}
