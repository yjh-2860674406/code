package Java.book5;

import java.util.Scanner;

public class two {
    public static int[][] InitMatrix (int column, int row) {
        int[][] matrix = new int[row][column];
        int[][] copy = new int[row][column];

        int x=0, y=(column+1)/2-1;
        int new_x=0, new_y = 0;

        for (int num=0; num<column*row; num++) {
            matrix[x][y] = num+1;
            copy[x][y] = 1;
            new_x = (x-1+row)%row; new_y = (y+1+column)%column;
            if (copy[new_x][new_y] == 0) {
                x = new_x; y = new_y;
            } else {
                x = (x+1+row)%row;
            }
        }
        return matrix;
    }
    
    public static void main(String[] args) {
        System.out.println("请输入方阵行列数：");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); in.close();
        int[][] matrix = InitMatrix(n, n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                System.out.printf("%1d\t", matrix[i][j]);
            }
            System.out.printf("\n");
        }
    }
}
