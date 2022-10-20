/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package distributore;

import java.util.Arrays;

/**
 *
 * @author patap
 */
public class Distributore {
     
    private static int DEAFAULT_SIZE = 10;
    private Tessera tessere[];
    private Bibita bibite[];
    private int maxTessere, maxBibite;
    private int riempBibite, riempTessere;
    
    public Distributore(int maxTessere, int maxBibite) {
        this.maxTessere = maxTessere;
        this.maxBibite = maxBibite;

        this.riempBibite = 0;
        this.riempTessere = 0;
        
        tessere = new Tessera[maxTessere];
        bibite = new Bibita[maxBibite];
    }
    
    // Costruttore secondario
    public Distributore(){
        
        this(DEAFAULT_SIZE, DEAFAULT_SIZE);
        
    }
    
    public boolean distributorePieno(){        
        return riempBibite == maxBibite;
    }
    
    public boolean memoriaTesseraEsaurita(){
        return riempTessere == maxTessere;
    }
    
    public void registraBevanda(Bibita tipo){
        
        if(distributorePieno())
            return;
        
        bibite[riempBibite] = tipo;
        riempBibite++;
              
    }
    
    public void caricaBevanda(String codice, int num){
        
        for(int i=0; i<riempBibite; i++){
            
            if(bibite[i].getCodice().equals(codice)){
                
                bibite[i].setNumero(num);
                return;
            }
            
        }
        System.out.println("Tipo Bibita non trovato");
        
    }
    
    public void registraTessera(Tessera x){
        if(memoriaTesseraEsaurita())
            return;
           
        for(int i=0; i<riempTessere; i++){
            
            if(x.equals(tessere[i]))
                return;
            
        }
        
        tessere[riempTessere] = x;
        riempTessere++;
        
    }    
    
    public void caricaSoldiTessera(int codice, double soldi){
                
        for(int i=0; i<riempTessere; i++){
            
            if(tessere[i].equals(codice)){
                
                tessere[i].caricaSaldo(soldi);
                return;
            }
         
        }
        
        System.out.println("Tessera non trovata");
    }
    
    public double VisualizzaSaldoTessera(int codice){
        
            for(int i=0; i<riempTessere; i++){
            
            if(tessere[i].equals(codice)){
                
                
                return tessere[i].getSaldo();
            }
         
        }
        
        System.out.println("Tessera non trovata");
        
        return 0;
    }
    
        public int VisualizzaBibiteDisponibili(String codice){
        
            for(int i=0; i<riempBibite; i++){
            
            if(bibite[i].equals(codice)){              
                
                return bibite[i].getNumero();
            }

        }
        
        System.out.println("Il tipo della bibita non è stato trovato");
        
        return 0;
    }
    
}


