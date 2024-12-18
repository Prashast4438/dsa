
    vector<int> findPrimeFactors(int N) {

        // Write your code here
     vector<int>primeFactors(N+1);
     for(int i=2;i<=N;i++)
     {
         primeFactors[i]=1;
     }
     for(int i=2;i*i<=N;i++)
     {
         if(primeFactors[i]==1)
         {
             for(int j=i*i;j<=N;j=j+i)
             {
                 primeFactors[j]=0;
             }
         }
         
     }
     vector<int>ans;
     for (int i = 2; i <= N; i++) {
        // Check if i is a prime factor and divide N by i as long as it's divisible
        while (primeFactors[i] == 1 && N % i == 0) {
            ans.push_back(i); // Add prime factor i to result
            N /= i; // Divide N by i to get the next factor
        }
    }

     
     return ans;
    }
