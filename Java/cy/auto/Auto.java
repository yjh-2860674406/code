package Java.cy.auto;

public class Auto {
   private double speed;
   public Auto(){
       this.speed = 0;
   }
   public void start(){
       System.out.println("汽车启动");
       this.speedUp();
   }
   public void speedUp(){
       this.speed+=10;
       System.out.println("此时速度为："+this.speed);
   }
   public void stop(){
       this.speed = 0;
       System.out.println("汽车刹车");
   }

}
