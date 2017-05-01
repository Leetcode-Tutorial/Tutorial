class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        if(m < n){//矩阵转置
            vector<vector<int>> tmp;
            for(int i = 0; i < n; i++){
                tmp.push_back({});
                for(int j = 0; j < m; j++)
                    tmp[i].push_back(matrix[j][i]);
            }
            swap(m, n);
            matrix.swap(tmp);
        }

        int ans = 0x80000000;
        for(int i = 0; i < n; i++){//枚举左边界
            vector<long long> tmp(m, 0);
            for(int j = i; j < n; j++){//枚举右边界
                long long sum = 0;
                set<long long> se = {0};
                for(int p = 0; p < m; p++){//枚举下边界
                    tmp[p] += matrix[p][j];
                    sum += tmp[p];
                    auto it = se.lower_bound(sum-k);//O(logm)查找
                    if(it != se.end()) ans = max(ans, int(sum-*it));
                    se.insert(sum);
                }
            }
        }
        return int(ans);
    }
};
