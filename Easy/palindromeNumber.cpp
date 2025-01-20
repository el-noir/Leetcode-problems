class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long int reverse =0; 
        long int nu= x;
        while(nu!=0){
            reverse = (reverse*10)+ (nu%10);
            nu= nu/10;
        }
        return (reverse==x);
    }
};