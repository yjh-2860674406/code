package Java.book5;

import java.util.Scanner;

public class one {
    public static int[] locateLarget (double[][] a, int column, int row) {
        int[] array = new int[2];
        double temp = a[0][0];
        for (int i=0; i<column; i++) {
            for (int j=0; j<row; j++) {
                if (a[j][i] > temp) {
                    temp = a[j][i];
                    array[0] = i+1; array[1] = j+1;
                }
            }
        }

        return array;
    }

    public static double[][] Initmatrix(int column, int row) {
        double[][] matrix = new double[row][column];
        Scanner in = new Scanner(System.in);
        System.out.println("请输入矩阵元素：");
        for (int i=0; i<column; i++) {
            for (int j=0; j<row; j++) {
                matrix[j][i] = in.nextDouble();
            }
        }
        in.close();
        return matrix;
    }

    public static void main(String[] args) {
        double[][] matrix = Initmatrix(3, 4);
        int[] array = locateLarget(matrix, 3, 4);
        for (int i=0; i<2; i++) {
            System.out.println(array[i]);
        }
    }
}
