import java.util.Scanner;

public class GridWalk {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int nowRows = sc.nextInt();//H
        int nowCols = sc.nextInt();//W
        sc.nextLine(); // 改行を消費


        // 二次元配列の宣言
        char[][] matrix = new char[rows][cols];

        // 行列の要素を入力
        for (int i = 0; i < rows; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = line.charAt(j);//改行消費しないとここでエラーでる
            }
        }
        
        String line1 = sc.nextLine(); 
        char[] siji = new char[line1.length()];

        for (int i = 0; i < line1.length(); i++) {
            siji[i] = line1.charAt(i);
        }

        nowRows--;
        nowCols--;
        

        for(int i = 0; i < line1.length(); i++){
            if(siji[i] == 'U' && nowRows > 0 && !(matrix[nowRows - 1 ][nowCols] == '#')){
                nowRows--;
            }
            else if(siji[i] == 'D' && nowRows < (rows - 1) && !(matrix[nowRows + 1 ][nowCols] == '#')){
                nowRows++;
            }
            else if(siji[i] == 'L' && nowCols > 0 && !(matrix[nowRows][nowCols - 1] == '#')){
                nowCols--;
            }
            else if(siji[i] == 'R' && nowCols < (cols - 1) && !(matrix[nowRows][nowCols + 1] == '#')){
                nowCols++;
            }
        }

        nowRows++;
        nowCols++;

        System.out.println(nowRows + " " + nowCols );

        sc.close();
    }
}
