/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop22.box;

import it.unisa.diem.oop22.veicoli.Veicolo;

/**
 *
 * @author nostro
 */
public abstract class Box {
    
    public int maxPosti;
    private String nome;

    public Box(int maxPosti, String nome) {
        this.maxPosti = maxPosti;
        this.nome = nome;
    }

    public abstract void entra(Veicolo v) throws AutoRimessaPienaException, TargaNonValidaException;
    public abstract Veicolo esce() throws AutoRimessaVuotaException;

    @Override
    public String toString() {
        return "\nNome Box: " + nome + "\nCapienza: " + maxPosti + '\n';
    }
    
}
