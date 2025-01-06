class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] dp = new int[n + 1][n + 1];

        // Start from the second-last row and move upwards
        for (int level = n - 1; level >= 0; level--) {
            for (int i = 0; i <= level; i++) {
                dp[level][i] = triangle.get(level).get(i)
                        + Math.min(dp[level + 1][i], dp[level + 1][i + 1]);
            }
        }

        // The result is stored at the top of the triangle
        return dp[0][0];
    }
}
