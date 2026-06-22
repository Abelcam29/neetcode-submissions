class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.begin(), people.end());
       int l = 0, r = people.size() - 1;
       int cant = 0;
       while(l <= r)
       {
            int max = people[r] + people[l];
            if(max <= limit)
            {
                r--;
                l++;
                cant++;
            }
            else if(max > limit)
            {
                r--;
                cant++;
            }
       }
       return cant;
    }
};