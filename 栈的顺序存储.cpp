
 #include<iostream>
 #define initstacksize 100
 #define increment 10
 using namespace std;
 class stack{
   int *base;
   int *top;
   int stacksize;
  public:
    stack();
    void initstackn(int n);
    void push(int e);
    void pop(int &e);
    int emptystack();
    void conversion(int n);
   };
   stack::stack(){
     base=new int[initstacksize];
     stacksize=initstacksize;
     top=base;
   }
  void stack::initstackn(int n){
      for(int i=0;i<n;i++){
         cin>>base[i];
         top++;
       }
  }
  void stack::push(int e){
    if(top-base==stacksize){
      int *base1=new int[stacksize+increment];
      for(int i=0;i<stacksize;i++)
        base1[i]=base[i];
      delete []base;
      base=base1;
      top=base+stacksize;
      stacksize+=increment;
    }
    *top++=e;
  }
  void stack::pop(int &e){
     if(top==base)return;
     e=*--top;
   }
  int stack::emptystack(){
    if(top==base)return 1;
    else return 0;
   }
  void stack::conversion(int n){
    while(n){
      push(n%8);
      n/=8;
     }
    int e;
    while(!emptystack()){
      pop(e);
      cout<<e;
    }
   }    
 


  



































