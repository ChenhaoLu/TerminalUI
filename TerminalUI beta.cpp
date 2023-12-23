/*
版本:bate1.4
更新：
1.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
string version="Version:Bate1.5";
void pass(){
    cout<<"pass"<<endl;
}
int random(int a,int b){//随机数(>=a&&<=b)
    srand(time(NULL));
    return (rand()%(b-a+1))+a;
}
void gotoxy(int x,int y){//移动光标
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int ExperimentMod=0;
int language=0;
int OpenExe(char sApp[100],string cmd){
    // 定义相对路径
    const char* relativePath = sApp;
    // 构建命令行指令
    string command = cmd;//  ./
    command += relativePath;
    // 执行命令行指令
    system(command.c_str());
    return 0;
}
int KillApp(string AppName){
    string cmd="taskkill /im ",a=" /f";
    cmd.append(AppName);
    cmd.append(a);
    system(cmd.c_str());
    return 0;
}
string sStr[100][2]={//? 字库
    {},//0
    {"设置","Settings"},//1
    {"功能1","now1"},//2
    {"设置","Setting"},//3
    {"实验性功能","Experiments"},//4
    {"菜单","Menu"},//5
    {"关于","About"},//6
    {"开源协议",""},//7
    {"版本号:Beta1.5","Version:Beta1.5"},//todo8=========================================================================================================================
    {"返回","Return"},//9
    {"错误:没有找到该界面!","Error: The interface was not found!"},//10
    {"语言","Language"},//11
    {"中文","English"},//12
    {"已禁用","Disabled"},//13
    {"已启用","Enabled"},//14
    {"默认","Default"},//15
    {"游戏","Game"},//16
    {"警告:实验有风险!","Warning:The experiment carries risks!"},//17
    {"关于Tool","About Tool"},//18
    {"编程语言:","Programming Language:"},//19
    {"按'↑'和'↓'选择,按回车键进入.","Press' ↑ 'and' ↓ 'to select, and press the Enter key to enter."},//20
    {"测试界面","Test Box"},//21
    {"测试","Test"},//22
    {"初始化","start"},//23
    {"退出","exit"},//24
    {"",""},//25
    {"",""},//26
    {"",""},//27
    {"",""},//28
    {"",""},//29
    {"",""},//30
    {"",""},//31
};
struct Box{
    int number;
    string name;
    string title;
    string specialtitle[10][10];//color,content
    string content[10];
    string role[10][2];//toBox,command;CommandName
}sBox[10][2];
void StartBoxContent(){
    for(int i=0;i<2;i++){
        sBox[1][i].name="Home";
        sBox[1][i].title=sStr[5][language];
        sBox[1][i].number=4;
        sBox[1][i].content[0]=sStr[2][language];
        sBox[1][i].role[0][0]="toBox";
        sBox[1][i].role[0][1]="Test";
        sBox[1][i].content[1]=sStr[16][language];
        sBox[1][i].role[1][0]="command";
        sBox[1][i].role[1][1]="Game";
        sBox[1][i].content[2]=sStr[3][language];
        sBox[1][i].role[2][0]="toBox";
        sBox[1][i].role[2][1]="setting";
        sBox[1][i].content[3]=sStr[24][language];
        sBox[1][i].role[3][0]="toBox";
        sBox[1][i].role[3][1]="exit";
    }
}
void LookforBox(){
    pass();
}
void LookforCommand(){
    pass();
}
int NumNow;
string KeyPressed(){//检测按键
    while (true){
        if (_kbhit()){ 
            int key=_getch();
            if (key==0||key==224){ // 处理特殊的控制键
                key = _getch();
                if (key==72){//up
                    return "up";
                } else if (key==80){//down
                    return "down";
                } else if(key==75){//left
                    return "left";
                } else if(key==77){//right
                    return "right";
                }
            } else if (key==27){//esc
                return "esc";
            } else if (key==13){//enter
                return "enter";
            } else if (key==' '){//space
                return "space";
            }
        }
        Sleep(50);
    }
}
int color(string a){
    if(a=="w")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//*白色
    if(a=="r")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//*红色
    if(a=="g")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//*绿色
    if(a=="b")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//*蓝色
    if(a=="y")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//*黄色
    if(a=="pi")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_BLUE);//*粉色
    if(a=="c")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//*青色
    if(a=="p")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//*紫色
    return 0;
}

class{
    private:
        int PromptLong=54;
        int prompt1(string TitleContent,int TitleMod){
            cout<<endl;
            color("c");
            for (int i = 0; i < PromptLong; i++)printf("=");
            color("w");
            printf("\n|");
            for (int i = 0; i < (PromptLong-TitleContent.size())/2-1; i++)printf(" ");
            if(TitleMod==1)color("w");
            else if(TitleMod==2)color("r");
            else if(TitleMod==3)color("y");
            cout<<TitleContent;
            for (int i = 0; i < (PromptLong-TitleContent.size())/2-1; i++)printf(" ");
            color("w");
            printf("|\n");
            color("c");
            for (int i = 0; i < PromptLong;i++)printf("=");
            return 0;
        }
        int prompt(string TitleContent,int TitleMod){
            cout<<endl;
            color("c");
            for (int i = 0; i < PromptLong; i++)printf("=");
            color("w");
            if(TitleMod==1)color("w");
            else if(TitleMod==2)color("r");
            else if(TitleMod==3)color("y");
            int len=TitleContent.size(),lennow=0,lens=len;
            printf("\n");
            for(int i=0;i<=len/PromptLong;i++){
                printf("|");
                if(lens>PromptLong){
                    for(int j=0;j<PromptLong-2;j++){
                        cout<<TitleContent[lennow+j];
                    }
                    lens-=PromptLong-2;
                    lennow=len-lens;
                }else{
                    for (int i = 0; i < (PromptLong-lens)/2-1; i++)printf(" ");
                    for(int j=0;j<lens;j++){
                        cout<<TitleContent[lennow+j];
                    }
                    for (int i = 0; i < (PromptLong-lens)/2-1; i++)printf(" ");
                    lens=0;
                    lennow=len;
                }
                printf("|\n");
            }
            color("c");
            for (int i = 0; i < PromptLong;i++)printf("=");
            return 0;
        }
    public:
        void printtitle(string TitleContent,int TitleMod){
            color("y");
            printf(" _____                   _             _   _   _ ___ \n");
            printf("|_   _|__ _ __ _ __ ___ (_)_ __   __ _| | | | | |_ _|\n");
            printf("  | |/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` | | | | | || | \n");
            printf("  | |  __/ |  | | | | | | | | | | (_| | | | |_| || | \n");
            printf("  |_|\\___|_|  |_| |_| |_|_|_| |_|\\__,_|_|  \\___/|___|");
            color("r");
            cout<<endl<<"                                           "<<version<<endl;
            prompt(TitleContent,TitleMod);
        }
        void printfloor(){
            printf("\n");
            color("c");
            for(int i=0;i<PromptLong;i++)printf("_");
            printf("\n");
            for(int i=0;i<PromptLong;i++)printf("=");
            color("w");
            printf("\n%s",sStr[20][language].c_str());
        }
}title;
void start(){
    system("cls");
    title.printtitle(sStr[23][language],1);

}
string Box(string iBoxName){
    string TitleA;
    int TitleB;
    bool SpecialTitle=false;
    while (iBoxName=="Home"){
        system("cls");
        if(!SpecialTitle){
            TitleA=sStr[5][language];
            TitleB=1;
        }
        title.printtitle(TitleA,TitleB);
        SpecialTitle=false;
        printf("\n\n");
        int iNum=4;//按钮数
        string s[100]={//按钮内容
            sStr[2][language],
            sStr[16][language],
            sStr[1][language],
            sStr[24][language]
        };if(ExperimentMod==1){
            iNum=5;//按钮数
            s[0]=sStr[2][language];
            s[1]=sStr[16][language];
            s[2]=sStr[4][language];
            s[3]=sStr[1][language];
            s[4]=sStr[24][language];
        }for (int i = 1; i <= iNum; i++){
            color("y");
            if(NumNow==i)color("w");
            printf("[ %d ]  ",i);
            color("g");
            if(NumNow==i)color("b");
            cout<<s[i-1]<<endl;
        }
        title.printfloor(); 
        string key=KeyPressed();
        if(key=="up"&&NumNow>1)NumNow--;
        else if (key=="down"&&NumNow<iNum)NumNow++;
        else if (key=="enter"){//按钮作用
            if(NumNow==1)return "Box1";
            else if(NumNow==2)OpenExe("game3.exe",".\\");
            else if(NumNow==3&&ExperimentMod==0||ExperimentMod==2)return "Settings";
            else if(NumNow==3&&ExperimentMod==1)return "Experiments";
            else if(NumNow==4&&ExperimentMod==1)return "Settings";
            else if(NumNow==4&&ExperimentMod==0)exit(0);
            else if(NumNow==5&&ExperimentMod==1)exit(0);
        }
    }
    while (iBoxName=="Settings"){
        system("cls");
        if(!SpecialTitle){
            TitleA=sStr[3][language];
            TitleB=1;
        }
        title.printtitle(TitleA,TitleB);
        SpecialTitle=false;
        printf("\n\n");
        int iNum=4;//按钮数
        string s[100]={sStr[9][language],sStr[11][language],sStr[4][language],sStr[6][language]};//按钮内容
        for(int i = 1; i <= iNum; i++){
            color("y");
            if(NumNow==i)color("w");
            printf("[ %d ]  ",i);
            color("g");
            if(NumNow==i)color("b");
            cout<<s[i-1];
            if(i==2){
                color("w");
                cout<<"\t\t\t"<<sStr[12][language];}
            if(i==3){
                cout<<"\t\t";
                if(ExperimentMod==0){
                    color("w");
                    cout<<sStr[15][language];
                }
                else if(ExperimentMod==1){
                    color("g");
                    cout<<sStr[14][language];
                }
                else if(ExperimentMod==2){
                    color("r");
                    cout<<sStr[13][language];
                }
            }
            cout<<endl;
        }
        title.printfloor(); 
        string key=KeyPressed();
        if(key=="up"&&NumNow>1)NumNow--;
        else if (key=="down"&&NumNow<iNum)NumNow++;
        else if (key=="enter"){//按钮作用
            if(NumNow==1)return "Home";
            else if(NumNow==2){
                if(language==0)language=1;
                else language=0;
            }
            else if(NumNow==3){
                if(ExperimentMod==0)ExperimentMod=1;
                else if(ExperimentMod==1)ExperimentMod=2;
                else ExperimentMod=0;
            }
            else if(NumNow==4)return "About";
        }
        if(NumNow==3){//编辑标题
            TitleA=sStr[17][language];
            TitleB=3;
            SpecialTitle=true;
        }
    }
while (iBoxName=="TestBox"){
        system("cls");
        if(!SpecialTitle){
            TitleA=sStr[5][language];
            TitleB=1;
        }
        title.printtitle(TitleA,TitleB);
        SpecialTitle=false;
        printf("\n\n");
        int iNum=3;//按钮数
        string s[100]={sStr[2][language],sStr[16][language],sStr[1][language]};//按钮内容
        if(ExperimentMod==1){
            iNum=4;//按钮数
            s[0]=sStr[2][language];
            s[1]=sStr[16][language];
            s[2]=sStr[4][language];
            s[3]=sStr[1][language];
        }
        for (int i = 1; i <= iNum; i++){
            color("y");
            if(NumNow==i)color("w");
            printf("[ %d ]  ",i);
            color("g");
            if(NumNow==i)color("b");
            cout<<s[i-1]<<endl;
        }
        title.printfloor(); 
        string key=KeyPressed();
        if(key=="up"&&NumNow>1)NumNow--;
        else if (key=="down"&&NumNow<iNum)NumNow++;
        else if (key=="enter"){//按钮作用
            if(NumNow==1)return "Box1";
            else if(NumNow==2)OpenExe("game3.exe",".\\");
            else if(NumNow==3&&ExperimentMod==0||ExperimentMod==2)return "Settings";
            else if(NumNow==3&&ExperimentMod==1)return "Experiments";
            else if(NumNow==4&&ExperimentMod==1)return "Settings";
        }
    }
    while (iBoxName=="About")
    {
        system("cls");
        if(!SpecialTitle){
        TitleA=sStr[18][language];
        TitleB=1;}
        title.printtitle(TitleA,TitleB);
        SpecialTitle=false;
        printf("\n\n");
        int iNum=1;//按钮数
        string s[100]={sStr[9][language]};//按钮内容
        color("w");//内容颜色
        cout<<"\t"<<"Terminal UI 图形用户界面"<<endl;
        cout<<"\t"<<version<< "(c++)" << endl;
        cout<<"\t"<<"作者:Lu_Chenhao"<<endl;
        cout<<"\t"<<"开源地址:https://gitee.com/luchenhaocode/terminal-ui";
        cout<<"\n\n\t"<< "本次更新:"<< "1.修改了界面布局"<<endl;
        for (int i = 1; i <= iNum; i++)
        {
            color("y");
            if(NumNow==i)color("w");
            printf("[ %d ]  ",i);
            color("g");
            if(NumNow==i)color("b");
            cout<<s[i-1]<<endl;
        }
        title.printfloor(); 
        string key=KeyPressed();
        if(key=="up"&&NumNow>1)NumNow--;
        else if (key=="down"&&NumNow<iNum)NumNow++;
        else if (key=="enter"){//按钮作用
            if(NumNow==1)return "Settings";
        }
    }
    while (true)//ErrorBox
    {
        system("cls");
        if(!SpecialTitle){TitleA=sStr[10][language];TitleB=2;}
        title.printtitle(TitleA,TitleB);
        SpecialTitle=false;
        printf("\n\n");
        int iNum=1;//按钮数
        string s[100]={sStr[9][language]};//按钮内容
        for (int i = 1; i <= iNum; i++)
        {
            color("y");
            if(NumNow==i)color("w");
            printf("[ %d ]  ",i);
            color("g");
            if(NumNow==i)color("w");
            cout<<s[i-1]<<endl;
        }
        title.printfloor(); 
        string key=KeyPressed();//检测按键
        if(key=="up"&&NumNow>1)NumNow--;
        else if (key=="down"&&NumNow<iNum)NumNow++;
        else if (key=="enter"){//按钮作用
            if(NumNow==1)return "Home";
        }
    }
}

int main(){
    string BoxName="Home";
    while (true)
    {
        NumNow=1;
        BoxName=Box(BoxName);
    }
    return 0;
}


