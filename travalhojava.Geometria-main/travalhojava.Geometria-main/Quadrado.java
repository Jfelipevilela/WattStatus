abstract public class ObjetoGeometrico{
    public double area;
    private double perimetro;
    protected String cor;
    }
    
    
    public class Quadrado extends ObjetoGeometrico {
    private double lado;
    Quadrado (double l){
    lado = l;
    }
    
    public double getArea(){
    area = lado*lado;
    return area;
    }
    
    public double getPerimetro(){
    double perimetro = lado*4;
    return perimetro;
    }
    
    public String getCor(){
    cor = "Azul";
    return cor;
    }
    
    }
    
    