/**
 * Created by hduser on 15-12-4.
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * For example,
 * Given the following matrix:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 */
import java.util.ArrayList;
import java.util.List;
public class SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        return helper(matrix);
    }
    private List<Integer> helper(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix.length == 0) {
            return res;
        }
        int[] nx = {0, 1, 0, -1};
        int[] ny = {1, 0, -1, 0};
        int x = 0, y = -1; //　因为是从(0, 0) 开始的
        int m = matrix.length, n = matrix[0].length;
        int i = 0, k = 0;
        while (m > 0 && n > 0) {
            if (i % 2 == 0) {
                k = n;  //　走的行
                m--;    //　少了一行
            } else {
                k = m;  // 走的列
                n--;    // 少了一列
            }
            while (k > 0) {
                x += nx[i];
                y += ny[i];
                res.add(matrix[x][y]);
                k--;
            }
            i++;
            i %= 4;
        }
        return res;
    }
}
