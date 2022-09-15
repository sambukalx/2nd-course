public class TestBall {
    public static void main(String[] args) {
        Ball b1 = new Ball();
        System.out.println(b1);
        b1 = new Ball(2, "Жельый");
        System.out.println(b1);
        System.out.println("Диаметр шара = " + b1.getDiametr());
    }
}
