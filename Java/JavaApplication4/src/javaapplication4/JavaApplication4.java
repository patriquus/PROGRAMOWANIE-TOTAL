/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication4;

/**
 *
 * @author Patriquus
 */
public class JavaApplication4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        char tab[] = {'I','n','f','o','r','m','a','t','y','k','a'};
        for (int i = 0; i<11; i++) {
           System.out.println(tab[i]); 
        }
        
        for (int i = 0; i<11; i++) {
           System.out.print(tab[i] + " "); 
        }
     
        for (int i = 0; i<11; i++) {
           System.out.print(Character.toUpperCase(tab[i])); 
        }
        
        for (int i = 0; i<11; i++) {
           System.out.print(Character.toLowerCase(tab[i])); 
        }       
    }
}
