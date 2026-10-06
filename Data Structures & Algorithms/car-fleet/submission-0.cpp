class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //time = target - position / speed
        int n = position.size();

        vector<int> indices(n);

        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j){
            return position[i] > position[j];
        });
        int fleecCount = 0;
        double previousATime = 0.0;
        for(int index : indices)
        {
            double arrivalTime = static_cast<double>(target - position[index]) / speed[index];
            if(arrivalTime > previousATime)
            {
                fleecCount++;
                previousATime = arrivalTime;
            }
        }
        return fleecCount;
    }
};
