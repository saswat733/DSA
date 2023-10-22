int power(int a,int b){          //program for finding the power of number   
  if(b==0){                      //optimised code
    return 1;
  }
  if(b==1){
    return a;
  }
  int ans=power(a,b/2);


  //if b is even
  if(b%2==0){
     return ans*ans;
  }
  else{
    return ans*ans*a;
  }
}

