package CY.cy.eleven_one;

public class Point<T> {
    private T x;
    private T y;
    public Point(T x, T y){
        this.x = x;
        this.y = y; 
    }
   public void setter_x(T x){
        this.x = x;
    }
   public void setter_y(T y){
       this.y = y;
   }
   public void getter(){
       System.out.println("("+ x +","+ y +")");
   }
   public void translate(T x , T y ){
       setter_x(x);
       setter_y(y);
   }
   public static void main(String[] args) {
       Point<Integer> point_1 = new Point<Integer>(1, 2);
       Point<Double> point_2 = new Point<Double>(1.1, 2.2);
   }
}
