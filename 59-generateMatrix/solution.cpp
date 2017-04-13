class Solution {
public:
   void turn (int &dis_x, int &dis_y) {
    	if (dis_x == 1) {
            dis_x = 0, dis_y = -1;
        }
        else if (dis_x == -1) {
            dis_x = 0, dis_y = 1;
        }
        else if (dis_y == 1) {
            dis_x = 1, dis_y = 0;
        }
        else if (dis_y == -1) {
            dis_x = -1, dis_y = 0;
        }
    }
    
    void go (int x, int y, int dis_x, int dis_y, int num, vector<vector<int> > &ans, int &n) {
        if (num > n*n || ans[x][y]) return ;
        ans[x][y] = num++;
        int xx = x+dis_x, yy = y+dis_y;
        if (xx >= n || yy >= n || xx < 0 || yy < 0 || ans[xx][yy]) 
        	turn (dis_x, dis_y);
        go (x+dis_x, y+dis_y, dis_x, dis_y, num, ans, n);
    }
    
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans (n, vector<int> (n, 0));
        go (0, 0, 0, 1, 1, ans, n);
        return ans;
    }
};
