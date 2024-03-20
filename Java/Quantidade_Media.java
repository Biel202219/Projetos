import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Locale.setDefault(Locale.US);
        Double quantidade_minima, quantidade_maxima, quantidade_medio;

        System.out.println("Calculadora de Estoque Médio");

        System.out.print("Digite a quantidade minima:");
        quantidade_minima = sc.nextDouble();

        System.out.print("Digite a quantidade maxima:");
        quantidade_maxima = sc.nextDouble();

        quantidade_medio = (quantidade_minima + quantidade_maxima) / 2;
        System.out.print("A qauntidade média é:"+quantidade_medio);
        
        sc.close();
    }
}