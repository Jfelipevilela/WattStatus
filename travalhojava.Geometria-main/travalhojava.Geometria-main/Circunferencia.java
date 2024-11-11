public class Circunferencia extends ObjetoGeometrico{
    public double pi = 3.141618;
    public double raio;
    
    Circunferencia(double r){
    raio = r;
    
    }
    
    public double getArea(){
    area = pi * (raio*raio);
    return area;
    }
    
    public double getPerimetro() {
    double perimetro = 2 * pi * raio;
    return perimetro;
    }
    
    public String getCor(){
    return "Amarelo";
    }
    }
    
    