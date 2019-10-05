#include<iostream>
#define Length 5  //链表容量
using namespace std;
typedef int ElemType;
 struct Component {
    ElemType data;
    int next;
};
class Slinklist{
        Component Vlist[Length];
    public:
        
        void CreatSlinklist();//创建静态链表
        void print();//输出链表数据

};
void Slinklist::CreatSlinklist(){
    cout<<"请输入静态链表的数据元素：";
    for(int i = 0;i < Length;i++){
        cin>>Vlist[i].data;
    }
}
void Slinklist::print(){
    cout<<"输出数据：";
    for(int i = 0; i < Length;i++){
        cout<<Vlist[i].data<<" ";
    }cout<<endl;
}
int main()
{
    Slinklist v;
    v.CreatSlinklist();
    v.print();
    return 0;
}