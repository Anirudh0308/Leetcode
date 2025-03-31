class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // int maxWeigth = -1, totalWeigth = 0;
        // for(int weight: weights){
        //     maxWeigth = max(maxWeigth, weights);
        //     totalWeight = totalWeigh + weight;
        // }

        // while(maxWeight< totalWeight){
        //     int midWeight = maxWeight + (totalWeight - maxWeight)/2;
        //     int daysNeeded = 1, currWeight = 0;
        //     for(int weight: weights){
        //        if(currWeight + weight > midWeight){
        //          daysNeeded++;
        //         currWeight = 0;
        //        }
        //        currWeight = currWeight + weight;
        //     }
        //     if(daysNeeded> days){
        //         maxWeight = midWeight + 1;
        //     } else{
        //         totalWeight = midWeight;
        //     }
        // }
        // return maxWeight;


         int maxWeight = -1, totalWeight = 0;
        for (int weight : weights) {
            maxWeight = max(maxWeight, weight);
            totalWeight = totalWeight + weight;
        }
        //here weight and total weight work as left and right pointer of bunary search
        while (maxWeight < totalWeight) {
            int midWeight = maxWeight + (totalWeight - maxWeight) / 2;
            int daysNeeded = 1, currWeight = 0;
            for (int weight : weights) {
                if (currWeight + weight > midWeight) {
                    daysNeeded++;
                    currWeight = 0;
                }
                currWeight = currWeight + weight;
            }
            if (daysNeeded > days) {
                maxWeight = midWeight + 1;
            } else {
                totalWeight = midWeight;
            }
        }
        return maxWeight;


    }
};