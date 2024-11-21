public class Triangulo extends ObjetoGeometrico{
    public double base;
    public double altura;
    public double ladoA;
    public double ladoB;
    public double ladoC;
    
    Triangulo(double b, double a,double ladoA, double ladoB, double ladoC){
    base = b;
    altura = a;
    ladoA = ladoA;
    ladoB = ladoB;
    ladoC = ladoC;
    }
    
    public double getArea(){
    area = base * altura /2;
    return area;
    }
    
    
    public double getPerimetro(){
    double perimetro = ladoA + ladoB + ladoC;
    return perimetro;
    }
    
    public String getCor(){
    cor = "Azul";
    return cor;
    }
    }
    