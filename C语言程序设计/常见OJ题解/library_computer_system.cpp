#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;
struct LoginReq 
{
User* userPointer; //指向当前请求登录的用户对象
int labNum; //用户请求登录 lab 的 number
int stationNum; //用户请求登录 station 的 number
int yy,mm,dd; //用户请求登录的 date
bool flag;
}; //flag=true 表示登录成功，flag=false 表示登录失败
struct LogoffReq 
{
User* userPointer; //指向当前请求注销的用户对象
int yy,mm,dd; //用户请求退出的 date
bool flag; //flag=true 表示注销成功，flag=false 表示注销失败
};
class ComputerLab
{
    int Lab_num,Sta_num;
    bool vacant;
    User* user;
    public:
        ComputerLab(){}
        ComputerLab(int Labnum,int StaNum)
        {
            Lab_num = Labnum;
            Sta_num = StaNum;
            vacant = true;
        }
        int Get_Lab_num() const
            {return Lab_num;}
        int Get_Sta_num() const
            {return Sta_num;}
        bool Vacant()
            {return vacant;}
        std::string Get_UserName()
            {return user->Get_user_name();}
        void operator+(LoginReq &r)
        {
                user = r.userPointer;
                user->yy = r.yy;user->mm = r.mm;user->dd = r.dd;
                vacant = false;
            //传入用户数据，并且状态改为被占用
        }
        void operator-(LogoffReq& r)
        {
            if(vacant)
                  std::cout << "invalid logoff" <<std::endl;
            else 
            {
                user = nullptr;
                vacant = true;
            }
        }
        
};
class User
{
    std::string user_name;
    friend ComputerLab;
    public:
     int yy,mm,dd;
        User():user_name("empty"),yy(0),mm(0),dd(0){}
        User(std::string name,int y,int m,int d)
        {
           user_name = name;
           yy = y;
           mm = m;
           dd = d;
          
        }
        std::string Get_user_name()
        {
            return user_name;
        }
        virtual int charge(int time){};
        virtual std::string getType(){return "User";};
};
class Student: public User
{
    const int FREEDAY = 14;
    const int ChargeRate = 1;
    public:
    Student (): User() {}
    Student(std::string name, int y,int m,int d): User(name,y,m,d) {}
    virtual int charge(int time) override 
    {
        if(time <= FREEDAY) return 0;
        else
        {
            return ChargeRate*(time - FREEDAY);
        }
    }
    virtual std::string getType() override
    {
        return "Student";
    }
};
class Staff: public User
{
    const int PRICEDAY = 30;
    const int ChargeRate = 4;
    public:
    Staff() : User() {}
    Staff(std::string name, int y, int m, int d): User(name,y,m,d) {}
    virtual int charge(int time) override
    {
        if(time <= PRICEDAY) return 0;
        else
        {
            return ChargeRate*(time - PRICEDAY);
        }
    }
    virtual std::string getType() override
    {
        return "Staff";
    }
};
int GetTime(int y1,int m1,int d1,int y2,int m2,int d2)
{
        int C=0;
        int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(y1-y2==0)
        {
                if((y1%4==0&&y1%100!=0)||(y1%400==0))
                        m[2]=29;
                for(int i=m1;i<m2;i++)
                {
                        if(i==m1)
                                C=m[i]-d1;
                        else
                        	C+=m[i];
                }
                C+=d2;
                if(m1==m2)C=d2-d1;
                return C;

        }
        else{
                for(int i=y1;i<y2;i++)
                {
                        if(i%4==0&&i%100!=0||i%400==0)C+=366;
                        else C+=365;
                }
                if(y1%4==0&&y1%100!=0||y1%400==0) m[2]=29;
                for(int i=1;i<m1;i++) C-=m[i];
                C-=d1;
                if(y2%4==0&&y2%100!=0||y2%400==0) m[2]=29;
                else m[2]=28;
                for(int i=1;i<m2;i++)C+=m[i];
                C+=d2;
                return C;
        }
        return 0;
    }//计算使用时长

int main()
{
    int index = 0;
    ComputerLab Lab[18];
    std::vector<User*> user; 
    for(int i = 1;i<=4;i++)
    for(int j = 1;j<=6;j++)
    {
        if(i==1&&j==4) break;
        if(i==2&&j==5) break;
        if(i==3&&j==6) break;
        Lab[index++] = ComputerLab(i,j);
    }//初始化机房列表
 
    char c;
    while(cin>>c,c!='=')
    {
        
        int find = 0;
        //上机
        if(c=='+')
        {
            std::string username;int labnum,int stanum;int yy,mm,dd;
            std::cin >> username>> labnum >> stanum >> yy >> mm >> dd;
            for (int i=0;i<user.size();i++)
                if (user[i]->Get_user_name() == username)
                    find = -1;//无法重复登陆
            if(find!=-1)
            {
                for (int i=0;i<18;i++)
                        if(Lab[i].Get_Lab_num() == labnum && Lab[i].Get_Sta_num()==stanum)
                        {
                            if(Lab[i].Vacant())
                            {
                                LoginReq Lin;
                                if(isalpha(username[0]))
                                {
                                    User* guest = new Staff(username,yy,mm,dd);
                                    user.push_back(guest);
                                    Lin.userPointer = guest;
                                    Lab[i] + Lin;
                                }
                                else if (isdigit(username[0]))
                                {
                                    User* guest = new Student(username,yy,mm,dd);
                                    user.push_back(guest);
                                    Lin.userPointer = guest;
                                    Lab[i] + Lin;
                                }
                                find = 1;
                            }//找到且空闲，执行登陆操作 
                            else
                                find = -1;//不空闲
                        }
                         
                        else
                            find=0;//机房位置不合法
            }
            if(find!=1)
                cout<<"invalid login"<<endl;
        }
        //下机
 
        if(c=='-')
        {
            int Index = 0;
            std::string username;int yy,mm,dd;
            std::cin >> username>> yy >> mm >> dd;
            for(int i = 0;i<user.size();i++)
            {
                if(username ==user[i]->Get_user_name())
                {
                   find = 1;
                    Index = i+1;
                    break;
                }
            }
            if(!find)
                std::cout<<"invalid logoff"<<endl;//虚空登出，报错
            else
            {
                if(Index>=1)
                {
                    int days = GetTime(user[Index]->yy,user[Index]->mm,user[Index]->dd,yy,mm,dd);
                    int price = user[Index]->charge(days);//计算价格
                    LogoffReq Lout;
                    Lout.userPointer = user[Index];
                    Lout.yy= yy;Lout.mm = mm;Lout.dd = dd;
                    for (int i=0;i<18;i++)
                        if (Lab[i].Get_UserName() == username)
                        {
                            Lab[i] - Lout;
                            std::cout << username << " log off, time: " << days << " days, price: "\
                            << price << " RMB" << std::endl;
                }
            }
        }
 
        //输出所有计算机情况
        for(int i = 0;i<18;i++)
        {
            if(i==0||i==5||i==11||i==15)
            {
                cout<<Lab[i].Get_Lab_num()<<" ";
            }
            cout<<Lab[i].Get_Sta_num()<<":"<<" "<<Lab[i].Get_UserName()<<" ";
            if(i==4||i==10||i==14||i==17)
                cout<<endl;
                
        }
        cout<<endl;
    }
 
    return 0;
}
  