/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package prodotti;

import prodotti.exceptions.*;

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
        
                Prodotto p1, p2;
        System.out.println("Numero prodotti: " + Prodotto.getNumProdotti());

        p1 = new Prodotto("HW03F", "Patatine", 1.0);
        System.out.println("Numero prodotti: " + Prodotto.getNumProdotti());

        p2 = new Prodotto("MK98T", "Coca Cola");
        System.out.println("Numero prodotti: " + Prodotto.getNumProdotti());

        p1.stampa();
        p2.stampa();

        ProdottoStack s = new ProdottoStack(2);

        System.out.println("Vuoto: " + s.isEmpty());
        System.out.println("Pieno: " + s.isFull());
        System.out.println("Elementi: " + s.size());

       
        try {
            s.top().stampa();
            s.push(p1);
            s.push(p2);
            s.push(p1);
            s.pop().stampa();
            s.pop().stampa();
        } catch (StackIsFullExceptions ex) {
            System.out.println("--------- ERRORE STACK PIENO --------");
        } catch (StackIsEmptyExceptions ex){
            System.out.println("--------- ERRORE STACK VUOTO --------");
        }
        
        System.out.println("Vuoto: " + s.isEmpty());
        System.out.println("Pieno: " + s.isFull());
        System.out.println("Elementi: " + s.size());
       
    }
    
}
