class Solution {
public:     
    typedef long long ll;
    const ll MOD = 1e9 +7;
    int m;
    int n ;
    vector<vector<pair<ll, ll>>> t;

    pair<ll, ll> solve(int i , int j ,vector<vector<int>>& grid ){
        if(i == m -1 && j == n -1){
            return {grid[i][j], grid[i][j]};
        }
        //
        if(t[i][j] != make_pair(LLONG_MAX, LLONG_MIN)){
            return t[i][j];
        }
        //
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;
        if(i + 1 < m){
            auto [maxDown, minDown] = solve(i + 1, j , grid);
            maxVal = max({maxVal, grid[i][j] * maxDown, grid[i][j] * minDown});
            minVal = min({minVal, grid[i][j] * maxDown, grid[i][j] * minDown});
        }
        if(j + 1 < n){
            auto [maxRight, minRight] = solve(i , j  + 1, grid);
            maxVal = max({maxVal, grid[i][j] * maxRight, grid[i][j] * minRight});
            minVal = min({minVal, grid[i][j] * maxRight, grid[i][j] * minRight});
        }
        return t[i][j]=  {maxVal , minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        t = vector<vector<pair<ll,ll>>>(m, vector<pair<ll,ll>>(n, {LLONG_MAX, LLONG_MIN}));
        auto [maxProd, minProd] =solve(0, 0, grid);
        return maxProd < 0 ? -1 : (maxProd % MOD);
    }
};