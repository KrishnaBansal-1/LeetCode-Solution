// You are given a string num which represents a positive integer, and an integer t.

// A number is called zero-free if none of its digits are 0.

// Return a string representing the smallest zero-free number greater than or equal to num such that the product of
// its digits is divisible by t.
// If no such number exists, return "-1".

class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b){
        return b == 0 ? a : gcd(b, a%b);
    }
    // just find the smallest possible number (divisible by t) of  length 'len'
    string calc(ll t, int len){
        string ans;

        for (int i = 9; i > 1; i--){
            while (t % i == 0){
                ans.push_back('0' + i);
                t /= i;
            }
        }

        if (t > 1)
            return "-1";

        while (ans.size() < len)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    string smallestNumber(string s, long long t) {
        int n = s.size();

        string got = calc(t, n);
        // return got;

//if size greater that is the ans
        if (got.size() > n || got == "-1" || got == s)
            return got;
        
        //avl[i] shows the product required when the first i character are taken
        vector<ll> avl(n+1, t);
        
        int top = 0; // get the first occuring zero
        for (; top < n; top++)
            if (s[top] == '0') break;

        int i; //calculate the avl till top
        for (i = 1; i <= top; i++){
            if (s[i-1] == '0') break;
            avl[i] = avl[i-1] / gcd(avl[i-1], s[i-1]-'0');
        }

        if (avl[n] == 1)
            return s;

        if (top == n) top--;
        // now go from top to 0th index and check for each digit 
        for (i = top; i >= 0; i--){
            //size remaining to the right side of i
            int rem = n - i - 1;
            //for each increment and check if the product can be achievable
            for (int j = (s[i]-'0')+1; j <= 9; j++){

                ll req = avl[i] / gcd(avl[i], j);

                string got2 = calc(req, rem);
                //if size at right enough then that is the answer
                if (got2.size() == rem && got2 != "-1"){
                    string finalans = s.substr(0, i);
                    finalans.push_back('0'+j);
                    finalans += got2;
                    return finalans;
                }
            }
        }
        //if finally no result found return with 1 greater length
        return calc(t, n+1);
    }
};
