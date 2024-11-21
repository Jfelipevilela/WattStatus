public class QuadroNegro {
private Quadrado quadrado;
private Retangulo retangulo;
private Circunferencia circunferencia;
private Triangulo triangulo;

public void limpaQuadro(){

}

public void criaQuadro(double l) {
quadrado = new Quadrado(l);
}
public void criaRetangulo(double c, double a){
retangulo = new Retangulo(c, a);
}
public void criaCircunferencia (double r){
circunferencia = new Circunferencia(r);
}
public void criaTriangulo (double b, double a,double ladoA, double ladoB, double ladoC){
triangulo = new Triangulo(b,a,ladoA,ladoB,ladoC);
}
}
