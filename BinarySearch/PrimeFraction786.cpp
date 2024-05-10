   
   class Solution {
    public:
        bool check(vector<int>& arr, int k, double m){
            int j = arr.size() - 1;
            int cnt = 0;
            for(int i = arr.size() - 2; i >= 0 ; i--) {
                //double d = ;
                while(i < j && 1.0 * arr[i] / arr[j] <= m){
                    cnt += i + 1;
                    j--;
                }
            }
            return cnt >= k;
        }
        vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
            // 1 2 3 4
            // 3 2 1 n * (n + 1) / 2
            double l = 0.0;
            double r = 1;
            while(r - l > 0.000001){
                auto mid = (l + r) / 2;
                if(check(arr,k,mid)){
                    r = mid;
                } else l = mid;
            }
            //return {};
            cout<<l<<endl;
            int i = arr.size() - 2, j = arr.size() - 1;
            while(i >= 0){
                double d = 1.0 * arr[i] / arr[j];
                if(fabs(d - l) < 0.000001){
                    return {arr[i], arr[j]};
                } else if(d > l){
                    i--;
                } else if(d < l){
                    j--;
                }
            }
            return {-1, -1};
        }
    };