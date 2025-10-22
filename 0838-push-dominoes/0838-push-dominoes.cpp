class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        
        vector<int> rightClosestL(n);
        vector<int> leftClosestR(n);
        
        //Moving right to left to find rightClosestL
        for(int i = n-1; i>=0; i--) {
            if(dominoes[i] == 'L')
                rightClosestL[i] = i; //L starts from me
            else if(dominoes[i] == '.')
                rightClosestL[i] = i < n-1 ? rightClosestL[i+1] : -1;
            else
                rightClosestL[i] = -1;
        }
        for(int i = 0; i<n; i++) {
            if(dominoes[i] == 'R')
                leftClosestR[i] = i; //R starts from me
            else if(dominoes[i] == '.')
                leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
            else
                leftClosestR[i] = -1;
        }

        string result(n, ' ');

        for(int i = 0; i<n; i++) {
            int distRightL = abs(i-rightClosestL[i]); //distance from 'R' towards my left direction
            int distLeftR  = abs(i-leftClosestR[i]);  //distance from 'L' towards my right direction
            
            if(rightClosestL[i] == leftClosestR[i])
                result[i] = '.';
            else if(rightClosestL[i] == -1)  //No force from right direction towards left, so move R
                result[i] = 'R';
            else if(leftClosestR[i] == -1)   //No force from left direction towards right, so move L
                result[i] = 'L';
            else if(distLeftR == distRightL) //Equal force from left and right
                result[i] = '.';
            else
                result[i] = distRightL < distLeftR ? 'L': 'R'; 
        }
        return result;
    }
};