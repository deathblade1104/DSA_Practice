class Solution {
public:
    double helper(double&x, int n)
    {        
        if(n==0)
            return 1;
        
        if(n==1)
            return x;
        
        double val = helper(x,n/2);
        
        if(n%2==0)
            return val *  val;
        
        return x*val*val;
    }
    double myPow(double x, int n) {
                
        double val = helper(x,abs(n));
        
        if(n<0)
            return (1.0/val);
        
        return val;
    }
};