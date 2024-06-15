
import java.util.Random;
import java.util.Scanner;

public class Bobing {

    public class Player
    {
        private int no=0;
        private int[] pawards= {0,0,0,0,0,0};//统计获奖

        public void play()//投掷一次
        {
            int[] results=new int[6];//用于存放一次投掷的结果
            for(int i=0;i<6;i++)//清空
                results[i]=0;

            Random ra=new Random();
            for(int j=0;j<6;j++)
                results[ra.nextInt(6)]++;

            judge_all(results);
        }
        public void get_award()
        {
            System.out.print("恭喜Player"+this.no+"一共荣获");
            for(int i=1;i<6;i++)
                System.out.print(Award.name[i]+pawards[i]+"个 ");
            System.out.println('!');
                
        }

        public void set_no(int x)
        {
            no=x;
        }

        private void judge_all(int[] res)
        {
            if(res[3]>3)
            {
                judge_top(res);
                return;//分流到状元，且状元与其他奖不兼容
            }

            for(int i=0;i<6;i++)
            {
                if(res[i]>4)
                {
                    judge_top(res);
                    return;//分流到状元，且状元与其他奖不兼容
                }

                else if(res[i]==4)
                    judge(4);//分流到四进
            }

            if(res[3]==3)
                judge(3);//三红
            else if(res[3]==2)
                judge(2);//二进
            else if(res[3]==1)
            {
                boolean s=true;
                for(int i=0;i<6;i++)
                {
                    if(res[i]!=1)
                    {
                        s=false;
                        break;
                    }
                }
                if(s)
                    judge(1);//对堂
                else
                    judge(5);//一秀
            }
        }

        private void judge(int i)
        {
            if(Award.awards[i]>0)
            {
                Award.awards[i]--;
                this.pawards[i]++;
                System.out.println("恭喜Player"+this.no+"荣获"+Award.name[i]+'!');
            }
            else
                System.out.println("恭喜Player"+this.no+"荣获空气"+Award.name[i-1]+'!');
        }

        private void judge_top(int[] res)
        {
            int s_p=judge_top_rank(res),s_t=judge_top_rank(Award.top);

            if(s_p>s_t)//卫冕失败
            {
                Award.top=res;
                Award.top_no=no;
                return;
            }
        }

        private int judge_top_rank(int[] res)//状元分级
        {
            int sum=0,rank=0;
            if(res[3]==4 && res[0]==2)
                rank=6;//插金花

            if(res[3]==6)
                rank=5;//六红
            for(int i=0;i<6;i++)
                if(res[i]==6)
                {
                    rank=4;//六黑
                    sum+=i;
                    break;
                }

            if(res[3]==5)
            {
                rank=3;//五红
                for(int i=0;i<6;i++)
                {
                    if(i!=3 && res[i]>0)
                        sum+=i;
                }
            }
            for(int i=0;i<6;i++)
            {
                if(res[i]==5)
                {
                    rank=2;//五黑
                    sum+=i*10;
                }
                else if(res[i]!=0)
                    sum+=i;
            }

            if(res[3]==4)
            {
                rank=3;//四红
                for(int i=0;i<6;i++)
                {
                    if(i!=3 && res[i]>0)
                        sum+=i;
                }
            }
            sum+=rank*100;
            return sum;
        }

        public Player(int x)
        {
            no=x;
        }
    }

    public static void main(String[] args)
    {
        int round=0;
        Scanner input = new Scanner(System.in);
        System.out.print("请输入玩家个数：");
        int pn = input.nextInt();

        Player[] players=new Player[pn];
        Bobing bb=new Bobing();
        for(int i=0;i<pn;i++)
        {
            players[i]=bb.new Player(i);
        }

        boolean b=true;
        while(b)//进行游戏
        {
            for(int i=0;i<pn;i++)
            {
                round++;
                System.out.println("第"+round+"轮：");
                players[i].play();
            }

            for(int i=1;i<6;i++)//游戏结束的判断
            {
                if(Award.awards[i]>0)
                    break;
                if(i==5)
                    b=false;
            }

        }

        System.out.println("状元是："+Award.top_no);
        players[Award.top_no].pawards[0]++;
        for(Player p:players)
            p.get_award();
    }
}
