#include <bits/stdc++.h>
using namespace std;
//5-1 给定有序整型数组A[n]和整数x，试设计一个在A中查找x的折半查找算法。
int BinarySearch(const int *arr,int low,int high,int value)
{
	if(low > high) return -1;
	int mid = (low+high)>>1;
	if (arr[mid]==value) return mid;
	else if (arr[mid]<value) return BinarySearch(arr,mid+1,high,value);
	else if (arr[mid]>value) return BinarySearch(arr,low,mid-1,value);
}
//5-2 设二叉排序树采用二叉链表存储结构：
//试设计二叉排序树的查找算法、插入算法和删除算法。
typedef struct BiTnode
{
int key;  //关键字域
//ElemType *otherinfo;  //其它数据项(可以忽略)
struct BiTnode *Lchild;  //左指针域
struct BiTnode *Rchild;  //右指针域
} BiTnode, *BiTree;
class Bit
{
public:
//查找算法
BiTnode* BiTSearch(const BiTree root,int value)
{
	BiTnode* cur = root;
	while(cur!=NULL)
	{
		if(cur->key == value)   //找到对应节点，直接返回
        {
           // cout << "Found " << value << endl;
            return cur;
        }
		else if(cur->key>value) cur = cur->Lchild;
		else if(cur->key<value) cur = cur->Rchild;
	}
    //cout << "NOT found" << endl;  //遍历完所有节点，未找到
    return NULL;
}
//插入算法
void BiTInsert(BiTree& root,int value)
{
    if (!root )     //若节点为空，生成新节点
    {
        root = new BiTnode;
        if (!root) exit(-1);
        root->key = value;
        root->Lchild = NULL;
        root->Rchild = NULL;
        cout << "Created new tree!" << endl;
        return;
    }
	BiTnode* cur = root;
	while (cur!=NULL)
	{
		if(cur->key == value)//已经存在节点
		{
			cout << "Value already existed!" << endl;
			return;
		}
		else if(cur->key>value)
		{
			if (cur->Lchild == NULL)//插入到左子树
			{
				BiTnode* p = new BiTnode;
				p->key = value;
				p->Lchild = NULL;
				p->Rchild = NULL;
				cur->Lchild = p;
				cout << "Inserted." << endl;
				return;
			}
			else cur = cur->Lchild;//左子树非空，搜索左子树
		}
		else if(cur->key<value)
		{
			if (cur->Rchild == NULL)//插入到右子树
			{
				BiTnode* p = new BiTnode;
				p->key = value;
				p->Lchild = NULL;
				p->Rchild = NULL;
				cur->Rchild = p;
				cout << "Inserted." << endl;
				return;
			}
			else cur = cur->Rchild;//右子树非空，搜索右子树
		}
	}
}
//删除算法
void BiTDelete(const BiTree root,int value)
{
	BiTnode* cur = root;
	BiTnode* par;
	while(cur!=NULL)//查找
	{
		if(cur->key == value)//找到
        {
            if(cur->Lchild ==NULL)
            {
                if(cur->Rchild==NULL)  
                {
                    DeleteLeave(cur,par);
                    cout << "Deleted " << value << endl;
                    return;
                }//叶子节点
                else    
                {
                    DeleteOnesideTree(cur,par,cur->Rchild,root);
                    cout << "Deleted " << value << endl;
                    return;
                }//右单边节点
            }
            else 
            {
                if(cur->Rchild==NULL) 
                {
                    DeleteOnesideTree(cur,par,cur->Lchild,root);
                    cout << "Deleted " << value << endl;
                    return;
                }//左单边节点
                else
                { 
                    DeleteBothsideTree(cur,root);
                    cout << "Deleted " << value << endl;
                    return;
                }//双边节点
            }
        }
        else if (cur->key>value)
        {
            par = cur;
            cur = cur->Lchild;
        }//搜索左子树
        else if (cur->key<value)
        {
            par = cur;
            cur = cur->Rchild;
        }//搜索右子树
	}
	if(cur == NULL)
	{
		cout << "Can't find appropriate node!" << endl;
	}
}
//删除叶子节点
void DeleteLeave(BiTnode* cur,BiTnode* parent)
{
    if (parent->Lchild==cur) //cur是左孩子
    {
        parent->Lchild = NULL;
        delete cur;
    }
    else if (parent->Rchild==cur)
    {
        parent->Rchild =NULL;   //cur是右孩子
        delete cur;
    }
    else if(parent == cur) delete cur;    //cur是根节点
    else cout << "Error!" << endl;  //非法
}
//删除有一个子树的节点
void DeleteOnesideTree(BiTnode* cur,BiTnode* parent,BiTnode* subtree,BiTree root)
{
    if(root == cur) root = subtree;//cur是根节点
    else if (parent->Lchild==cur)   //cur是左孩子
    {
        parent->Lchild = subtree;
        delete cur;
        return;
    }
    else if (parent->Rchild==cur)   //cur是右孩子
    {
        parent->Rchild = subtree;
        delete cur;
    }
    else cout << "Error!" << endl;  //非法
}
//删除有两个子树的节点(使用右节点最小值)
void DeleteBothsideTree(BiTnode* cur,BiTree root)
{
    if (cur==root)  //根节点
    {
        BiTnode* p = cur->Rchild;
        BiTnode* q=cur;
        while(p->Lchild!=NULL)  //找右子树最小节点
        {
            q = p;
            p = p->Lchild;
        }
        root->key = p->key;   //替换
        if(p->Rchild==NULL) DeleteLeave(p,q);   //p是叶子节点
        else DeleteOnesideTree(p,q,p->Rchild,root); //p有右子树
    }
    else //不是根节点
    {
        BiTnode* p = cur->Rchild;
        BiTnode* q = cur;
        while(p->Lchild!=NULL)  //找右子树最小节点
        {
            q = p;
            p = p->Lchild;
        }
        cur->key = p->key;   //替换
        if(p->Rchild==NULL) DeleteLeave(p,q);   //p是叶子节点
        else DeleteOnesideTree(p,q,p->Rchild,root); //p有右子树
    }
}
};
//5-3哈希表设计。为班级30个人的姓氏(单字姓)设计一个哈希表，假设姓氏用汉语拼音表示。
//要求用除留取余法构造哈希函数，用线性探测再散列法处理冲突，平均查找长度的上限为2。
#define HASH_SIZE 50//哈希表的长度
#define Name_SIZE 30//名字表长度
#define R 49//小于哈希表长度的R
//int i,key;
struct Name
{
    char *name;            //姓名
    int ascii;             //对应的ascii码和
};
struct Hash
{
    char *name;            //姓名                 
    int ascii;             //对应ASCII码和
    int s;                 //查找长度
};
Name NameList [Name_SIZE];
Hash hashtable [HASH_SIZE];
void init_Namelistlist ( );      //初始化姓名表
void C_hashtable ( ) ;      //创建hash表
void collison (int i );          //冲突函数,第i个姓名表发生冲突
void print_Namelist ( );
void print_hash ( );         //打印函数       
void init_Namelist( )
{

    NameList[0].name="zhangsan";
    NameList[1].name="lisi";
    NameList[2].name="wangmazi";
    NameList[3].name="ergoudan";
    NameList[4].name="tieniu";
    NameList[5].name="dabendan";
    NameList[6].name="xunan";
    NameList[7].name="zhoulei";
    NameList[8].name="tanglei";
    NameList[9].name="xiaomin";
    NameList[10].name="xiaohong";
    NameList[11].name="xiaoli";
    NameList[12].name="damin";
    NameList[13].name="jinzhengyu";
    NameList[14].name="xiaosaobi";
    NameList[15].name="xuyang";
    NameList[16].name="lihao";
    NameList[17].name="huangzhifeng";
    NameList[18].name="liangsifen";
    NameList[19].name="yanzhiwo";
    NameList[20].name="liyanlin";
    NameList[21].name="liuxiaohan";
    NameList[22].name="tanghuan";
    NameList[23].name="gongxiaoyu";
    NameList[24].name="haoren";
    NameList[25].name="huairen";
    NameList[26].name="shuchang";
    NameList[27].name="lixinru";
    NameList[28].name="zhouhang";
    NameList[29].name="wangcunwen";
    int i,j;
    for(i=0;i<Name_SIZE;i++)
    {    
        for(j=0;(*(NameList[i].name+j))!='\0';j++)             
        NameList[i].ascii+=toascii(*(NameList[i].name+j));            //ascii码求和
    }                  
}
void collison (int i)
{
    int key,flag;
    flag=0;                                                           //未探测至末尾
    key=(NameList[i].ascii)%R;
    while(hashtable[key].s != 0)
    {
        key=key+1; 
      //  printf("%d",key);                                             //线性探测每次加1
        if(key==HASH_SIZE-1){                                          //探测至哈希表末端
            key=0;
            flag=1;                                                    //探测至末尾标识                       
        }
    }
    if(hashtable[key].s==0)
        {
            hashtable[key].name=NameList[i].name;
            hashtable[key].ascii=NameList[i].ascii;
            if(flag==0)
            hashtable[key].s= (key-(NameList[i].ascii%R))+1 ;
            else
            hashtable[key].s= (HASH_SIZE-(NameList[i].ascii%R))+key+1;   //查找次数                                                                                       //查找次数
        }
}
void C_hashtable()                                      //创建哈希函数
{
    int i,key;
    for(i=0;i<HASH_SIZE;i++)
    {
        hashtable[i].name="\0";
        hashtable[i].ascii=0;
        hashtable[i].s=0;                              //初始化哈希表
    }
    for(i=0;i<Name_SIZE;i++)
    {
        key=(NameList[i].ascii)%R;                        //除留余数法
        if(hashtable[key].s == 0 )                      //未发生冲突
        {
            hashtable[key].name=NameList[i].name;
            hashtable[key].ascii=NameList[i].ascii;
            hashtable[key].s=1;
        }
        else                                                //发生冲突
          collison ( i );                                 //调用冲突函数
        
    }

}
void print_Namelist ( )//输出姓名名单
{
    int i;
    for(i=0;i<Name_SIZE;i++)
    {
        printf("number:%d\tname:%s\tascii:%d\n",i,NameList[i].name,NameList[i].ascii);
    }
}
void print_hash ( )//输出哈希表
{   
    int i;
    float ASL=0.0;                         //平均查找长度
    for(i=0;i<HASH_SIZE;i++)
    {   
        printf("number:%d\tname:%s\tascii:%d\t%d\n",i,hashtable[i].name,hashtable[i].ascii,hashtable[i].s);
        ASL+=hashtable[i].s;
    }
    ASL=ASL/Name_SIZE;
    printf("ASL:%f\n",ASL);
}

int a[]={5,8,13,18,25,31,40,58,76};
int main()
{
    //二分查找部分
    cout << "二分查找部分：" << endl;
    int k = BinarySearch(a,0,8,13);
    cout << "Binary Search: In index " << k << endl;
    k = BinarySearch(a,0,8,14);
    cout << "Binary Search: In index " << k << endl;
    //二叉排序树部分
    int arr[]={5,6,4,1,7,3,9,10,8,2};
    cout << "二叉排序树部分" << endl;
    Bit bit;
    BiTree root = NULL;
    for (int i=0;i<9;i++)
        bit.BiTInsert(root,arr[i]);
    bit.BiTSearch(root,7);
    bit.BiTSearch(root,11);
    bit.BiTDelete(root,1);
    bit.BiTSearch(root,1);
    bit.BiTDelete(root,9);
    bit.BiTSearch(root,9);
    bit.BiTDelete(root,11);
    //哈希表部分
    cout << "哈希表部分" << endl;
    init_Namelist( );
    C_hashtable( );
    //print_Namelist ( );
    print_hash ( );
}