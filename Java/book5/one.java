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
        int row = 0; int column = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("请输入矩阵行数："); row = input.nextInt();
        System.out.println("请输入矩阵列数："); column = input.nextInt();
        double[][] matrix = Initmatrix(row, column);
        int[] array = locateLarget(matrix, row, column);
        System.out.println("最大元素在：第 " + array[0] + " 行 第 " + array[1] + " 列。");
        input.close();
    }
}
