/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package prodotti;

import prodotti.exceptions.*;

/**
 *
 * @author patap
 */
public class ProdottoStack {
    
    // In caso nel main non venga specificato
    private final static int DEFAUT_SIZE=5;
    private int maxDim, riemp;
    private Prodotto prodotti[];
    
    public ProdottoStack(int maxDim) {
        this.maxDim = maxDim;
        this.riemp = 0;
        prodotti = new Prodotto[maxDim];
        
    }
    
    // Costruttore secondario
    // Viene usato in caso nel main non vengono specificati il numero di posti
    // è importante che venga usato la definizione "static" a DEFAUT_SIZE
    public ProdottoStack(){
        this(DEFAUT_SIZE);
    }
    
    public int size(){
        
        return riemp;
    }
    
    public boolean isEmpty(){
        
        return riemp == 0;
    }
    
    public boolean isFull(){
        
        return riemp == maxDim;
    }
    
    public Prodotto top() throws StackIsEmptyExceptions{
        
    if(isEmpty()){        
            throw new StackIsEmptyExceptions();
    } 
    
       return prodotti[riemp];
         
    }    
    
    public void push(Prodotto s) throws StackIsFullExceptions {
           
    if(isFull()){        
            throw new StackIsFullExceptions();
    }  
        
    prodotti[riemp] = s;    
    riemp++;
    
    }
    
    public Prodotto pop() throws StackIsEmptyExceptions{
    
        if(isEmpty()){            
            throw new StackIsEmptyExceptions();
        }
    
    riemp--;    
        
    Prodotto s = prodotti[riemp] ;    
    prodotti[riemp] = null;    
      
        return s;  
        
    }
}


