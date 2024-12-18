int Xor(int p){
      if(p%4==1) return 1;
      if(p%4==2) return p+1;
      if(p%4==3) return 0;
        else return p;
      }
      
    int findXOR(int l, int r) {
     
     int ans=0;
      ans=Xor(l-1)^Xor(r);
      return ans;
    }
