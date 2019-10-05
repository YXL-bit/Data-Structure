#include<iostream>
#include<iterator>
#define initlistsize 10
#define increment 10  //额外的存储容量
using namespace std;
class sqlist{
  int *elem;   //数组指针，指示顺序表的基地址
  int listsize;//一维数组容量
  int length;//表中数据元素的实际个数
public:
  sqlist();//初始化线性表
  void initlistn();//给数组输入数据
  void print();//输出数据
  void insertlist(int pos,int e);//插入函数：在pos位置插入e
  void deletelist(int pos,int &e);//删除函数，删除pos位置的数据，用e返回被删除的数据
  int search(int x);//找出x在数组中的位置
  void turnlist();//数组翻转
};  
sqlist::sqlist(){
  elem=new int[initlistsize];//动态分配容量为100,指针elem指向数组首地址
  listsize=initlistsize;//一维数组容量为100
  length=0;
}
//=========================================================================================================
void sqlist::initlistn(){//给数组输入数据
  cout<<"你想输入多少数据:";
  int n;
  cin>>n;
  cout<<"请输入"<<n<<"个数据：";
  for(int i=0;i<n;i++)
    cin>>elem[i];
  length=n;
}
//=========================================================================================================
void sqlist::print(){     //输出数组的数据
  for(int i=0;i<length;i++)
     cout<<elem[i]<<' ';
  cout<<endl;
}
//========================================================================================================
void sqlist::insertlist(int pos,int e){
  if(pos<1||pos>length+1){ cout<<"插入位置异常"; return;}
  if(length>=listsize)//-------------------------------------------/*
  {                                                              //
     int *elem1=new int[listsize+increment];                     //插入数据时长度超出容量，则新分配一个数组存储空间
     for(int i=0;i<length;i++) // /*                            //
       elem1[i]=elem[i];       //把旧表单赋值给新表单              //
     delete []elem;            //                               //
     elem=elem1;               //                               //
     listsize+=increment;      // */                            // 
   }    //---------------------------------------------------------*/
   int *p=&elem[pos-1],*q=&elem[length-1];//-----------------------/*
   for(;p<=q;q--)                                                //
     *(q+1)=*q;                                                  // 在数组pos位置插入e
   *p=e;                                                         //
   length++;                                                     //
}   //-------------------------------------------------------------*/
//=========================================================================================================
void sqlist::deletelist(int pos,int &e){                        //删除数组pos位置上的数据
  if(pos<1||pos>length)return;
  int *p=&elem[pos-1],*q=&elem[length-1];
   e=*p;
  cout<<"已删除"<<pos<<"位置上的数据"<<e<<endl;
  for(;p<q;p++)
    *p=*(p+1);  //把pos位置后面的数据赋值到前一位，覆盖pos位置的数据
  length--; 
}
//=========================================================================================================
int sqlist::search(int x){     //找出x在数组中的位置
   for(int i=0;i<length;i++)
     if(x==elem[i])return i;
   return -1;
}
//=========================================================================================================
void sqlist::turnlist(){      //数组翻转
  int *temp=new int;
  int *p=elem,*q=&elem[length-1];
  for(;p<q;p++,q--){
     *temp=*p;
     *p=*q;
     *q=*temp;
  }
}
//========================================================================================================
int main()
{
 sqlist la;
 la.initlistn();
 cout<<"数据为：";
 la.print();
 int k,l;
 cout<<"请输入插入的位置：";
 cin>>k;
 cout<<"请输入插入的数据：";
cin>>l;
 la.insertlist(k,l);
 cout<<"数据为：";
 la.print();
 int e,n;
 cout<<"你想删除哪个位置：";
 cin>>n;
 la.deletelist(n,e);
 cout<<"数据为：";
 la.print();
 cout<<"数组翻转";
 la.turnlist();
 cout<<"数据为：";
 la.print();
 return 0;
}
 

 

 













