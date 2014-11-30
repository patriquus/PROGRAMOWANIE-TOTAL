/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication5;

/**
 *
 * @author Patriquus
 */
public class JavaApplication5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        char tab[] = {'p', 'r', 'o', 'g', 'r', 'a', 'm', 'o', 'w', 'a', 'n', 'i', 'e'};
        System.out.println("Rozmiar tablicy to " + tab.length);
        System.out.println(tab);
        
        char pom;
        int n = tab.length;
        
        for (int i=0; i<n/2; i++) {
            pom = tab[i];
            tab[i] = tab[n];
            n--;            
        }
        
        System.out.println(tab);
        
    }
}
