class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //x esta en 1 a N.
        //se ordenará el vector en forma que el primer i + 1 faltante sera regresado.
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            //mientras 0 < x < n && x != x-1 vamos a swapear (colocar)
            while(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1; //regresar el valor de n garantiza que se regresa el ultimo valor + 1
    }
};