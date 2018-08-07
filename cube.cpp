#include<bits/stdc++.h>
using namespace std;

#define _WIN32_WINNT 0x0502
#include<windows.h>


void textcolor(unsigned short color) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}



int minu=21;
int cube[6][3][3];
int cur_window=1;
int bot_window=2;
pair<int,int> coor[]={{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}};
char moves[]="RDULFBMESrdulfbmes";

//help menu improve kora lagbe
void help()
{
    cout<<"command                                       description\n";
    cout<<"---------------------------------------------------------\n\n";
    cout<<"-? / help / -h                                help menu\n";
    cout<<"-u / undo                                     UNDO move\n";
    cout<<"-v / view                                     view cube\n";
    cout<<"-s / scramble                                 re-scramble cube\n";
    cout<<"RDULFBMESrdulfbmes                            move\n";
    cout<<"clear / -c                                    clear screan\n";
    cout<<"exit / -e                                     exit game\n";
}

string new_str(string s)
{
    string ss="";
    for(int i=0;i<s.size();i++)ss+=tolower(s[i]);
    return ss;
}


void print_with_color(int n)
{
    if(n==0)
    {
        textcolor(240);
    }
    if(n==1)
    {
        textcolor(160);
    }
    if(n==2)
    {
        textcolor(96);
    }
    if(n==3)
    {
        textcolor(144);
    }
    if(n==4)
    {
        textcolor(64);
    }
    if(n==5)
    {
        textcolor(208);
    }
    //cout<<n;
    cout<<"     ";
    textcolor(15);
}


void view()
{

    // 1st line;
    for(int i=0;i<minu;i++)cout<<" ";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<" ";
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        int xxx=2;
        while(xxx--)
        {
            for(int i=0;i<minu;i++)cout<<" ";
            cout<<"| ";
            for(int j=0;j<3;j++)
            {
                if(j)cout<<" ";
                print_with_color(cube[0][i][j]);
            }
            cout<<" |";
            for(int i=0;i<minu;i++)cout<<" ";
            cout<<endl;
        }
    }
    for(int i=0;i<minu;i++)cout<<" ";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<" ";
    cout<<endl;

    //2nd line;


    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<"-";
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        int xxx=2;
        while(xxx--)
        {
            cout<<"| ";
            for(int j=0;j<3;j++)
            {
                if(j)cout<<" ";
                print_with_color(cube[5][i][j]);
            }
            cout<<" |";
            cout<<"| ";
            for(int j=0;j<3;j++)
            {
                if(j)cout<<" ";
                print_with_color(cube[1][i][j]);
            }
            cout<<" |";
            cout<<"| ";
            for(int j=0;j<3;j++)
            {
                if(j)cout<<" ";
                print_with_color(cube[4][i][j]);
            }
            cout<<" |";
            cout<<endl;
        }
    }
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<"-";
    cout<<endl;

    // 3rd line
    for(int i=0;i<minu;i++)cout<<" ";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<" ";
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        int xxx=2;
        while(xxx--)
        {
            for(int i=0;i<minu;i++)cout<<" ";
            cout<<"| ";
            for(int j=0;j<3;j++)
            {
                if(j)cout<<" ";
                print_with_color(cube[2][i][j]);
            }
            cout<<" |";
            for(int i=0;i<minu;i++)cout<<" ";
            cout<<endl;
        }
    }
    for(int i=0;i<minu;i++)cout<<" ";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<" ";
    cout<<endl;

    // 4st line;
    for(int i=0;i<minu;i++)cout<<" ";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<" ";
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        int xxx=2;
        while(xxx--)
        {
            for(int i=0;i<minu;i++)cout<<" ";
            cout<<"| ";
            for(int j=0;j<3;j++)
            {
                if(j)cout<<" ";
                print_with_color(cube[3][i][j]);
            }
            cout<<" |";
            for(int i=0;i<minu;i++)cout<<" ";
            cout<<endl;
        }
    }
    for(int i=0;i<minu;i++)cout<<" ";
    for(int i=0;i<minu;i++)cout<<"-";
    for(int i=0;i<minu;i++)cout<<" ";
    cout<<endl;

}
void rot(int side,int clock)
{
    vector<int> p;
    if(clock==1)
    {
        for(int i=0;i<8;i++)
        {
            int x=coor[i].first;
            int y=coor[i].second;
            p.push_back(cube[side][x][y]);
        }
        for(int i=0;i<8;i++)
        {
            int j=(2+i)%8;
            int x=coor[j].first;
            int y=coor[j].second;
            cube[side][x][y]=p[i];
        }
    }
    else
    {
        for(int i=7;i>=0;i--)
        {
            int x=coor[i].first;
            int y=coor[i].second;
            p.push_back(cube[side][x][y]);
        }
        for(int i=7;i>=0;i--)
        {
            int j=(6+i)%8;
            int x=coor[j].first;
            int y=coor[j].second;
            cube[side][x][y]=p[7-i];
        }
    }
}



void mov(char ch)
{
    bool f=0;
    for(int i=0;i<18;i++)if(moves[i]==ch)f=1;
    if(f)
    {
        if(ch=='R' || ch=='r')
        {
            vector<int> p;
            for(int k=0;k<4;k++)
            {
                for(int i=0;i<3;i++)
                {
                    p.push_back(cube[k][i][2]);
                }
            }
            int t;
            if(ch=='R')
            {
                t=1;
                rot(4,1);
            }
            else
            {
                t=3;
                rot(4,-1);
            }
            while(t--)
            {
                for(int i=0;i<3;i++)p.push_back(p[i]);
                p.erase(p.begin());p.erase(p.begin());p.erase(p.begin());
            }
            t=0;
            for(int k=0;k<4;k++)
            {
                for(int i=0;i<3;i++)
                {
                    cube[k][i][2]=p[t];
                    t++;
                }
            }
            return ;
        }
        if(ch=='L' || ch=='l')
        {
            vector<int> p;
            for(int k=0;k<4;k++)
            {
                for(int i=0;i<3;i++)
                {
                    p.push_back(cube[k][i][0]);
                }
            }
            int t;
            if(ch=='L')
            {
                t=3;
                rot(5,1);
            }
            else
            {
                t=1;
                rot(5,-1);
            }
            while(t--)
            {
                for(int i=0;i<3;i++)p.push_back(p[i]);
                p.erase(p.begin());p.erase(p.begin());p.erase(p.begin());
            }
            t=0;
            for(int k=0;k<4;k++)
            {
                for(int i=0;i<3;i++)
                {
                    cube[k][i][0]=p[t];
                    t++;
                }
            }
            return ;
        }
        if(ch=='U' || ch=='u')
        {

            vector<int> p;
            for(int i=0;i<3;i++)p.push_back(cube[1][0][i]);
            for(int i=0;i<3;i++)p.push_back(cube[4][0][i]);
            for(int i=0;i<3;i++)p.push_back(cube[3][2][2-i]);
            for(int i=0;i<3;i++)p.push_back(cube[5][0][i]);
            int t=0;
            if(ch=='U')
            {
                for(int i=0;i<3;i++)cube[5][0][i]=p[t++];
                for(int i=0;i<3;i++)cube[1][0][i]=p[t++];
                for(int i=0;i<3;i++)cube[4][0][i]=p[t++];
                for(int i=0;i<3;i++)cube[3][2][2-i]=p[t++];
                rot(0,1);
            }
            else
            {
                for(int i=0;i<3;i++)cube[4][0][i]=p[t++];
                for(int i=0;i<3;i++)cube[3][2][2-i]=p[t++];
                for(int i=0;i<3;i++)cube[5][0][i]=p[t++];
                for(int i=0;i<3;i++)cube[1][0][i]=p[t++];
                rot(0,-1);
            }
            return ;
        }
        if(ch=='D' || ch=='d')
        {

            vector<int> p;
            for(int i=0;i<3;i++)p.push_back(cube[1][2][i]);
            for(int i=0;i<3;i++)p.push_back(cube[4][2][i]);
            for(int i=0;i<3;i++)p.push_back(cube[3][0][2-i]);
            for(int i=0;i<3;i++)p.push_back(cube[5][2][i]);
            int t=0;
            if(ch=='D')
            {
                for(int i=0;i<3;i++)cube[4][2][i]=p[t++];
                for(int i=0;i<3;i++)cube[3][0][2-i]=p[t++];
                for(int i=0;i<3;i++)cube[5][2][i]=p[t++];
                for(int i=0;i<3;i++)cube[1][2][i]=p[t++];
                rot(2,1);
            }
            else
            {
                for(int i=0;i<3;i++)cube[5][2][i]=p[t++];
                for(int i=0;i<3;i++)cube[1][2][i]=p[t++];
                for(int i=0;i<3;i++)cube[4][2][i]=p[t++];
                for(int i=0;i<3;i++)cube[3][0][2-i]=p[t++];
                rot(2,-1);
            }
            return ;
        }
        if(ch=='F' || ch=='f')
        {

            vector<int> p;
            for(int i=0;i<3;i++)p.push_back(cube[0][2][i]);
            for(int i=0;i<3;i++)p.push_back(cube[4][i][0]);
            for(int i=0;i<3;i++)p.push_back(cube[2][0][2-i]);
            for(int i=0;i<3;i++)p.push_back(cube[5][2-i][2]);
            int t=0;
            if(ch=='F')
            {
                for(int i=0;i<3;i++)cube[4][i][0]=p[t++];
                for(int i=0;i<3;i++)cube[2][0][2-i]=p[t++];
                for(int i=0;i<3;i++)cube[5][2-i][2]=p[t++];
                for(int i=0;i<3;i++)cube[0][2][i]=p[t++];
                rot(1,1);
            }
            else
            {
                for(int i=0;i<3;i++)cube[5][2-i][2]=p[t++];
                for(int i=0;i<3;i++)cube[0][2][i]=p[t++];
                for(int i=0;i<3;i++)cube[4][i][0]=p[t++];
                for(int i=0;i<3;i++)cube[2][0][2-i]=p[t++];
                rot(1,-1);
            }
            return ;
        }
        if(ch=='B' || ch=='b')
        {

            vector<int> p;
            for(int i=0;i<3;i++)p.push_back(cube[0][0][i]);
            for(int i=0;i<3;i++)p.push_back(cube[4][i][2]);
            for(int i=0;i<3;i++)p.push_back(cube[2][2][2-i]);
            for(int i=0;i<3;i++)p.push_back(cube[5][2-i][0]);
            int t=0;
            if(ch=='B')
            {
                for(int i=0;i<3;i++)cube[5][2-i][0]=p[t++];
                for(int i=0;i<3;i++)cube[0][0][i]=p[t++];
                for(int i=0;i<3;i++)cube[4][i][2]=p[t++];
                for(int i=0;i<3;i++)cube[2][2][2-i]=p[t++];
                rot(3,1);
            }
            else
            {
                for(int i=0;i<3;i++)cube[4][i][2]=p[t++];
                for(int i=0;i<3;i++)cube[2][2][2-i]=p[t++];
                for(int i=0;i<3;i++)cube[5][2-i][0]=p[t++];
                for(int i=0;i<3;i++)cube[0][0][i]=p[t++];
                rot(3,-1);
            }
            return ;
        }
        if(ch=='M' || ch=='m')
        {

            vector<int> p;
            for(int i=0;i<3;i++)p.push_back(cube[0][i][1]);
            for(int i=0;i<3;i++)p.push_back(cube[1][i][1]);
            for(int i=0;i<3;i++)p.push_back(cube[2][i][1]);
            for(int i=0;i<3;i++)p.push_back(cube[3][i][1]);
            int t=0;
            if(ch=='m')
            {
                for(int i=0;i<3;i++)cube[1][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[2][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[3][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[0][i][1]=p[t++];
            }
            else
            {
                for(int i=0;i<3;i++)cube[3][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[0][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[1][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[2][i][1]=p[t++];
            }
            return ;
        }
        if(ch=='E' || ch=='e')
        {

            vector<int> p;
            for(int i=0;i<3;i++)p.push_back(cube[1][1][i]);
            for(int i=0;i<3;i++)p.push_back(cube[4][1][i]);
            for(int i=0;i<3;i++)p.push_back(cube[3][1][2-i]);
            for(int i=0;i<3;i++)p.push_back(cube[5][1][i]);
            int t=0;
            if(ch=='e')
            {
                for(int i=0;i<3;i++)cube[4][1][i]=p[t++];
                for(int i=0;i<3;i++)cube[3][1][2-i]=p[t++];
                for(int i=0;i<3;i++)cube[5][1][i]=p[t++];
                for(int i=0;i<3;i++)cube[1][1][i]=p[t++];
            }
            else
            {
                for(int i=0;i<3;i++)cube[5][1][i]=p[t++];
                for(int i=0;i<3;i++)cube[1][1][i]=p[t++];
                for(int i=0;i<3;i++)cube[4][1][i]=p[t++];
                for(int i=0;i<3;i++)cube[3][1][2-i]=p[t++];
            }
            return ;
        }

        if(ch=='S' || ch=='s')
        {

            vector<int> p;
            for(int i=0;i<3;i++)p.push_back(cube[0][1][i]);
            for(int i=0;i<3;i++)p.push_back(cube[4][i][1]);
            for(int i=0;i<3;i++)p.push_back(cube[2][1][2-i]);
            for(int i=0;i<3;i++)p.push_back(cube[5][2-i][1]);
            int t=0;
            if(ch=='S')
            {
                for(int i=0;i<3;i++)cube[4][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[2][1][2-i]=p[t++];
                for(int i=0;i<3;i++)cube[5][2-i][1]=p[t++];
                for(int i=0;i<3;i++)cube[0][1][i]=p[t++];
            }
            else
            {
                for(int i=0;i<3;i++)cube[5][2-i][1]=p[t++];
                for(int i=0;i<3;i++)cube[0][1][i]=p[t++];
                for(int i=0;i<3;i++)cube[4][i][1]=p[t++];
                for(int i=0;i<3;i++)cube[2][1][2-i]=p[t++];
            }
            return ;
        }

    }
}

void scramble()
{
    srand(time(NULL));
    int x=1000;
    while(x--)
    {
        int t=rand()%18;
        mov(moves[t]);
    }
}



bool is_solved()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(cube[i][j][k]!=cube[i][0][0])return 0;
            }
        }
    }
    return 1;
}
int main()
{

    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL ){ SetWindowPos(hwnd ,0,0,0 ,1000,1000 ,SWP_SHOWWINDOW|SWP_NOMOVE); }
    SetConsoleTitle("RUBIX CUBE SIMULATOR'");
    time_t previous_time,next_time;
    time(&previous_time);
    double seconds;
    for(int x=0;x<6;x++)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cube[x][i][j]=x;
            }
        }
    }
    scramble();
    system ("CLS");
    cout<<"for help menu, type -? or -h or help ...\n\n";
    view();
    string ss;
    stack<string> s;
    while(!is_solved())
    {
        cout<<"\n>>>  ";
        cin>>ss;
        if(new_str(ss)=="-?" || new_str(ss)=="-h" || new_str(ss)=="help")
        {
            help();
            continue;
        }
        if(new_str(ss)=="-v" || new_str(ss)=="view")
        {
            system ("CLS");
            view();
            continue;
        }
        if(new_str(ss)=="-e" || new_str(ss)=="exit")
        {
            return 0;
        }
        if(new_str(ss)=="-c" || new_str(ss)=="clear")
        {
            system ("CLS");
            continue;
        }
        if(new_str(ss)=="-s" || new_str(ss)=="scramble")
        {
            scramble();
            cout<<"\n";
            system ("CLS");
            view();
            cout<<"\n";
            time(&previous_time);
            continue;
        }
        if(new_str(ss)=="-u" || new_str(ss)=="undo")
        {
            if(!s.empty())
            {
                string kk=s.top();
                s.pop();
                ss="";
                for(int i=kk.size()-1;i>=0;i--)
                {
                    if(kk[i]<='z' && kk[i]>='a')ss+=toupper(kk[i]);
                    else ss+=tolower(kk[i]);
                }
            }
            else continue;
        }
        else s.push(ss);
        for(int i=0;i<ss.size();i++)mov(ss[i]);
        system ("CLS");
        time(&next_time);
        seconds = difftime(next_time,previous_time);
        textcolor(144);
        printf("time= %.3f seconds\n\n",seconds);
        textcolor(15);
        cout<<">>> "<<ss<<"\n\n";
        view();
        cout<<"\n";
    }
    printf("!!END GAME!!\n\n");
    time(&next_time);
    seconds = difftime(next_time,previous_time);
    textcolor(144);
    printf("Your time is %.3f seconds\n\n",seconds);
    textcolor(15);
    system("PAUSE");
}
