MostraAreaObjetosaAreaObjetos(){
    System.out.println("Quadrado. Area" + quadrado.getArea());
    System.out.println("Retangulo. Area" + retangulo.getArea());
    System.out.println("Triangulo. Area" + (triangulo.base * triangulo.altura)/2);
    System.out.println("Circunferencia. Area" + circunferencia.getArea());
    }
    
    public void mostraPerimetroObjetos(){
    
    }
    
    public void mostraCorObjetos(){
    
    }
    
    public static void main (String[] args) {
    QuadroNegro quadroNegro = new QuadroNegro();
    quadroNegro.criaQuadrado(10.6);
    quadroNegro.criaRetangulo(50.5,20.4);
    quadroNegro.criaTriangulo(6.7,5.5,5,5,5);
    quadroNegro.criaCircunferencia(10);
    quadroNegro.mostraCorObjetos();
    
    }
    