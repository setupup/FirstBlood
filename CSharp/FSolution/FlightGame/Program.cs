using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FlightGame
{
    class Program
    {
        static int[] Map = new int[100];
        static int[] playerPos = { 0, 0 }; //playerPos[0] is As index [1]is Bs index
        static void Main(string[] args)
        {
            Random r = new Random();
            int step = 0; //to store the random number
            string input="";
            //in this array, 0 represent normal
            //2 represent bomb 3 is stop 4 is time tunel 1 represent the circle
            string[] names = new string[2]; //0wei A 1 wei B
            //Console.WriteLine("Hello,World!");
            showUI();
            Console.WriteLine("qingshuru wanjiaA de xinming");
            names[0] = Console.ReadLine();
            while (names[0] == "")
            {
                Console.WriteLine("shuru neirong wei kong qingchongxinshuru!");
                names[0] = Console.ReadLine();
            }
            Console.WriteLine("qingshuru wanjia B de xingming!");
            names[1] = Console.ReadLine();
            while (names[1] == "" || names[1] == names[0])
            {
                if (names[1] == "")
                {
                    Console.WriteLine("BU neng weikong qingchongxinshuru ");
                }
                else//name[1]==name[0]
                    Console.WriteLine("BU neng yu wanjiaA de xingmingxiangtong! ");
                names[1] = Console.ReadLine();
            }
            Console.Clear();
            showUI();
            Console.WriteLine("Game Start!!");
            Console.WriteLine("{0}yongA lai biaoshi", names[0]);
            Console.WriteLine("{0}yongB lai biaoshi", names[1]);
            Console.WriteLine("IF A and B zaitongyiweizhi then,yong <> laibiaoshi");
            InitialMap();
            drawMap();
            Console.WriteLine("Let's begin this game!!");


            //this circle let the player A and B to play the saikoro until the position >=99
            //the condition is <99
            while(playerPos[0]<99&&playerPos[1]<99) //大循环
            {
                #region A
                //player A play
                Console.WriteLine("{0}to press any key to play...", names[0]);
                Console.ReadKey(true);
                step = r.Next(1, 7);//一到六之间的随机整数
                Console.WriteLine("{0}play the number of{1}", names[0], step);
                Console.WriteLine("press any key to play....");
                Console.ReadKey(true);
                playerPos[0] = playerPos[0] + step;
                CheckPos();//检验坐标 两个
                if (playerPos[0] == playerPos[1])
                {
                    playerPos[1] = 0;
                }
                else
                {//if others?
                    switch (Map[playerPos[0]])
                    {
                        case 0:
                            break;
                        case 1://lucky turn
                            Console.Clear();
                            drawMap();
                            Console.WriteLine("You went in the lucky turn, choose:");
                            Console.WriteLine("1--- Exchange   2---bomb777");
                            int userSelect = ReadInt(1, 2);
                            if (userSelect == 1)
                            {
                                //Exchange
                                int temp = playerPos[0];
                                playerPos[0] = playerPos[1];
                                playerPos[1] = temp;
                            }
                            else
                            {
                                playerPos[1] = playerPos[1] - 6;
                                CheckPos();
                            }
                            break;
                        case 2://bomb
                            playerPos[0] = playerPos[0] - 6;
                            CheckPos();
                            break;
                        case 3://stop
                            break;
                        case 4://timetunel 
                            playerPos[0] = playerPos[0] + 10;
                            break;
                    }
                }

                Console.Clear();
                drawMap();
                Console.WriteLine("{0} zhichule {1} xindongwancheng",names[0],step);
                Console.WriteLine("*****************player A and player B is below:***************");
                Console.WriteLine("{0}position is {1} gezi", names[0], playerPos[0]+1);
                Console.WriteLine("{0}position is {1} gezi", names[1], playerPos[1]+1);

                Console.Clear();
                drawMap();
                #endregion
                #region B
                //Player B play
                #endregion
            }

            Console.ReadKey();
        }
        //fangfa de hao xi guan
        /// <summary>
        /// write the flight game of user interface
        /// </summary>
        static void showUI()
        {
            Console.WriteLine("***********************************************");
            Console.WriteLine("*                                             *");
            Console.WriteLine("*             Knight Flight Game              *");
            Console.WriteLine("*                                             *");
            Console.WriteLine("***********************************************");

        }
        /// <summary>
        /// to make the distinguish between player A and B's Position
        /// </summary>
        static void CheckPos()  //这里不传参，同时检查数组中两个分量的是否溢出。
        {
            for(int i=0;i<2;i++)
            {
                if (playerPos[i] > 99)
                {
                    playerPos[i] = 99;
                }
                if (playerPos[i] < 0) 
                {
                    playerPos[i] = 0;
                }
            }
        }
        /// <summary>
        /// to initial the map of spacial items
        /// </summary>
        static void InitialMap()
        {
            //to use it to contain the index of spatial items
            int[] luckyTurn = { 6, 23, 40, 55, 69, 83 };
            int[] landMine = { 5, 13, 17, 33, 38, 50, 64, 80, 94 };
            int[] pause = { 9, 27, 60, 93 };
            int[] timeTunnel = { 20, 25, 45, 63, 72, 88, 90 };
            for (int i = 0; i < luckyTurn.Length; i++)
            {
                int pos = luckyTurn[i];
                Map[pos] = 1;
            }
            for (int i = 0; i < landMine.Length; i++)
            {
                int pos = landMine[i];
                Map[pos] = 2;
            }
            for (int i = 0; i < pause.Length; i++)
            {
                int pos = pause[i];
                Map[pos] = 3;
            }
            for (int i = 0; i < timeTunnel.Length; i++)
            {
                int pos = timeTunnel[i];
                Map[pos] = 4;
            }
        }
        /// <summary>
        /// to get the index Pos which matches the string
        /// </summary>
        /// <param name="pos">the INDEX pos</param>
        /// <returns></returns>
        static string GetMapString(int pos)
        {
            string result="";
            if (playerPos[0] == pos && playerPos[1] == pos)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
               result= "<>";
            }
            else if (playerPos[0] == pos)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                result= "Ａ";
            }
            else if (playerPos[1] == pos)
            {
                result= "Ｂ";
                Console.ForegroundColor=ConsoleColor.Yellow;
            }
            else
            {
                switch (Map[pos])
                {
                    case 0:
                        Console.ForegroundColor = ConsoleColor.White;
                        result= "□";
                        break;
                    case 1:
                        Console.ForegroundColor = ConsoleColor.Red;
                        result= "◎";
                        break;
                    case 2:
                        Console.ForegroundColor = ConsoleColor.Green;
                        result= "★";
                        break;
                    case 3:
                        Console.ForegroundColor = ConsoleColor.Blue;
                        result= "▲";
                        break;
                    case 4:
                        Console.ForegroundColor = ConsoleColor.DarkBlue;
                        result= "※";
                        break;
                }
            }
            return result; 
 
        }
        static void drawMap()
        {
            //to draw the first line
            for (int i = 0; i < 30; i++)
            {
                Console.Write(GetMapString(i));
            }
            //the end of the first line
            Console.WriteLine("");
            for (int i = 30; i < 35; i++)
            {
                for (int j = 0; j < 29; j++)
                {
                    Console.Write("  ");
                }
                Console.WriteLine(GetMapString(i));
                //#region
                //// to determine whether the A or B is on the point i
                //    if (playerPos[0] == i && playerPos[1] == i)
                //    {
                //        Console.Write("<>");
                //    } 
                //    else if (playerPos[0] == i)
                //    {
                //        Console.Write("Ａ");
                //    }
                //    else if (playerPos[1] == i)
                //    {
                //        Console.Write("Ｂ");
                //    }
                //    else
                //    {
                //        switch (Map[i])
                //        {  
                //            case 0:
                //                Console.WriteLine("□");
                //                break;
                //            case 1:
                //                Console.WriteLine("◎");
                //                break;
                //            case 2:
                //                Console.WriteLine("★");
                //                break;
                //            case 3:
                //                Console.WriteLine("▲");
                //                break;
                //            case 4:
                //                Console.WriteLine("※");
                //                break;
                //        }
                //    }
                //#endregion


            }

            for (int i = 64; i >= 35; i--)
            {
                Console.Write(GetMapString(i));
            }
            Console.WriteLine();
            for (int i = 65; i < 70; i++)
            {
                Console.WriteLine(GetMapString(i));
            }
            for (int i = 70; i < 100; i++)
            {
                Console.Write(GetMapString(i));
            }
            Console.WriteLine();
            Console.ResetColor();
        }
        static int ReadInt()
        {
            int i = ReadInt(int.MinValue, int.MaxValue);
            return i;
        }
        static int ReadInt(int min,int max)
        {
            while (true)
            {
                try
                {
                    int number = Convert.ToInt32(Console.ReadLine());
                    if (number <min||number>max)
                    {
                        Console.WriteLine("only {0}--{1} is valid, please input again", min, max);
                        continue;
                    }
                    return number;
                }
                catch 
                {
                    Console.WriteLine("only number is valid, please input again");
                }
            }
        }

    }
}