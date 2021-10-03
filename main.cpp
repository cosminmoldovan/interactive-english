///-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
#include <iostream>
#include <fstream>
#include <string.h>
#include <graphics.h>
#include <windows.h>
#include <MMSystem.h>
using namespace std;
int scx=getmaxwidth()/800;
int scy=getmaxheight()/600;
void meniu();
void meniu2();
void numerele();
void familia();
void familia1();
void pronumele();
void pronumele1();
void pronumele2();
void alimentatie();
void alimentatie1();
void alimentatie2();
void alimentatie3();
void fonetic();
int unde_meniu(int x,int y)
{
    if(x>=scx*747&&y>=scy*15&&x<=scx*787&&y<=scy*45)
        return 11;
    if(x>=scx*700&&y>=scy*15&&x<=scx*740&&y<=scy*45)
        return 12;
    if(x>=scx*653&&y>=scy*15&&x<=scx*693&&y<=scy*45)
        return 13;
    if(x>=scx*20&&y>=scy*110&&x<=scx*297&&y<=scy*187)
         return 1;
    if(x>=scx*20&&y>=scy*207&&x<=scx*297&&y<=scy*284)
         return 2;
    if(x>=scx*20&&y>=scy*304&&x<=scx*297&&y<=scy*381)
         return 3;
    if(x>=scx*20&&y>=scy*401&&x<=scx*297&&y<=scy*478)
         return 4;
    if(x>=scx*500&&y>=scy*110&&x<=scx*777&&y<=scy*187)
        return 5;
    if(x>=scx*500&&y>=scy*207&&x<=scx*777&&y<=scy*284)
        return 6;
    if(x>=scx*500&&y>=scy*304&&x<=scx*777&&y<=scy*381)
        return 7;
    if(x>=scx*500&&y>=scy*401&&x<=scx*777&&y<=scy*478)
        return 8;
    if(x>=scx*360&&y>=scy*498&&x<=scx*428&&y<=scy*554)
        return 9;
    if(x>=scx*300&&y>=scy*200&&x<=scx*500&&y<=scy*400)
        return 10;
    if(x>=scx*600&&y>=scy*500&&x<=scx*800&&y<=scy*600)
        return 14;
    return 0;
}
void bar(char t[100])
{
    setbkcolor(COLOR(198,207,214));
    cleardevice();
    readimagefile("img/bk.jpg",0,0,scx*800,scy*600);
    readimagefile("img/logo.jpg",scx*40,scy*10,scx*280,scy*50);
    settextstyle(8,0,12);
    setcolor(COLOR(127,127,127));
    char text[100];
    strcpy(text,">> ");
    strcat(text,t);
    outtextxy(scx*282,scy*25,text);
}
void buton(int exit,int help,int acasa)
{
    if(exit==1)
        readimagefile("img/exit.jpg",scx*747,scy*15,scx*787,scy*45);
    if(help==1)
        readimagefile("img/help.jpg",scx*700,scy*15,scx*740,scy*45);
    if(acasa==1)
        readimagefile("img/acasa.jpg",scx*653,scy*15,scx*693,scy*45);
}
void mousetrece()
{
    while(!ismouseclick(WM_LBUTTONDOWN))
    {

       int x=mousex();
       int  y=mousey();
        int zona1=unde_meniu(x,y);
        switch(zona1)
        {
                case 11:readimagefile("img/exitactiv.jpg",scx*747,scy*15,scx*787,scy*45);break;
                case 12:readimagefile("img/helpactiv.jpg",scx*700,scy*15,scx*740,scy*45);break;
                case 13:readimagefile("img/acasaactiv.jpg",scx*653,scy*15,scx*693,scy*45);break;
                case 0:readimagefile("img/acasa.jpg",scx*653,scy*15,scx*693,scy*45);
                       readimagefile("img/exit.jpg",scx*747,scy*15,scx*787,scy*45),
                       readimagefile("img/help.jpg",scx*700,scy*15,scx*740,scy*45);break;
        }
    }
}
void ajutor()
{
    bar("ajutor");
    readimagefile("img/acasa.jpg",scx*747,scy*15,scx*787,scy*45);
    readimagefile("img/ajutor.jpg",scx*200,scy*80,scx*600,scy*580);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {

       int x=mousex();
       int  y=mousey();
        int zona1=unde_meniu(x,y);
        switch(zona1)
        {
                case 11:readimagefile("img/acasaactiv.jpg",scx*747,scy*15,scx*787,scy*45);break;
                case 0:readimagefile("img/acasa.jpg",scx*747,scy*15,scx*787,scy*45);break;

        }
    }
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 11:meniu();
        }

    }while(1);
    closegraph();
}
struct traducere
{
    char en[1000];
    char ro[1000];
};
traducere v[1000];
int n;
void citire (char nf[],traducere v[],int &n)
{
    int i;
    ifstream in (nf);
    in>>n;
    for(i=1;i<=n;i++)
    {
        in.get();
        in.get(v[i].en,1000);
        in.get();
        in.get(v[i].ro,1000);
        in.get();
    }
    in.close();
}
void citiretext(char t[],int nr,int x,int y,int ct)
{
    char lit;
    setcolor(ct);
    int l=0;
    t[0]='_';
    t[l]='\0';
    do
    {

        settextstyle(8,0,13);
        outtextxy(x,y,t);
        lit=getch();
        if(lit!=8 && lit!=13 && l<nr)
        {
            t[l]=lit;
            t[l+1]='\0';
            l++;
        }
        else
            if(lit==8 && l>0)
            {
                setcolor(COLOR(255,255,255));outtextxy(x,y,t);
                t[l-1]=t[l];
                t[l]='\0';
                l--;
                setcolor(ct);outtextxy(x,y,t);
            }

    }
    while(lit!=13);
}
void corect()
{
        readimagefile("img/corect.jpg",scx*25,scy*490,scx*775,scy*570);
}
void gresit()
{
         readimagefile("img/gresit.jpg",scx*25,scy*490,scx*775,scy*570);
}
void tr(int a)
{
    char t[100];
    int k,nr;
    setbkcolor(COLOR(245,245,245));
    setcolor(COLOR(0,160,230));
    settextstyle(8,0,13);
        readimagefile("img/camp.jpg",scx*100,scy*100,scx*700,scy*500);
        readimagefile("img/enter.jpg",scx*300,scy*510,scx*500,scy*590);
        outtextxy(scx*140,scy*165,v[a].en);

    setbkcolor(COLOR(255,255,255));
    citiretext(t,42,scx*185,scy*210,BLACK);
    int semtr=0;
        if(stricmp(v[a].ro,t)==0)
        {
            semtr=1;
            corect();

        }
        if(semtr==0)
        {
             gresit();
             delay(1500);
             meniu();

        }
}
void testtraducere()
{

    citire("date.in",v,n);
    setbkcolor(COLOR(198,207,214));
    cleardevice();
    readimagefile("img/bktr.jpg",0,0,scx*800,scy*600);
    readimagefile("img/logo.jpg",scx*40,scy*10,scx*280,scy*50);
    buton(1,1,1);
    mousetrece();
    tr(1);
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 9:alimentatie();


        }

    }while(1);
    closegraph();

}
void lectie2(char titlu[50],char imagine [50])
{
    bar(titlu);
    buton(1,1,1);
    readimagefile(imagine,scx*0,scy*80,scx*800,scy*480);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 11:exit(1);
                case 12:ajutor();
                case 13:meniu2();

        }

    }while(1);
    closegraph();
}
void plante()
{
    bar("plante");
    buton(1,1,1);
    readimagefile("img/fructe.jpg",scx*50,scy*80,scx*370,scy*550);
    readimagefile("img/legume.jpg",scx*410,scy*80,scx*740,scy*550);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
        }

    }while(1);
    closegraph();
}
void animalele()
{
    bar("animalele");
    buton(1,1,1);
    readimagefile("img/farm.jpg",scx*50,scy*80,scx*370,scy*550);
    readimagefile("img/vild.jpg",scx*410,scy*80,scx*740,scy*550);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
        }

    }while(1);
    closegraph();
}
void alimentatie1()
{
    bar("Alimentatie");
    buton(1,1,1);
    readimagefile("img/alimente3.jpg",scx*0,scy*80,scx*400,scy*480);
    readimagefile("img/alimente4.jpg",scx*400,scy*80,scx*800,scy*480);
    readimagefile("img/prev.jpg",scx*360,scy*498,scx*428,scy*554);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 9:alimentatie();

        }

    }while(1);
    closegraph();
}
void alimentatie()
{
    bar("Alimentatie");
    buton(1,1,1);
    readimagefile("img/alimente1.jpg",scx*0,scy*80,scx*400,scy*480);
    readimagefile("img/alimente2.jpg",scx*400,scy*80,scx*800,scy*480);
    readimagefile("img/next.jpg",scx*360,scy*498,scx*428,scy*554);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 9:alimentatie1();
        }

    }while(1);
    closegraph();
}

void pronumele1()
{
    bar("Dativ si Acuzativ");
    buton(1,1,1);
    readimagefile("img/dativ.jpg",scx*0,scy*80,scx*400,scy*480);
    readimagefile("img/acuzativ.jpg",scx*400,scy*80,scx*800,scy*480);
    readimagefile("img/prev.jpg",scx*360,scy*498,scx*428,scy*554);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 9:pronumele();

        }

    }while(1);
    closegraph();
}
void pronumele()
{
    bar("Nominativ si Genitiv");
    buton(1,1,1);
    readimagefile("img/nominativ.jpg",scx*0,scy*80,scx*400,scy*480);
    readimagefile("img/genitiv.jpg",scx*400,scy*80,scx*800,scy*480);
    readimagefile("img/next.jpg",scx*360,scy*498,scx*428,scy*554);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 9:pronumele1();

        }

    }while(1);
    closegraph();
}
void familia1()
{
    bar("familia");
    buton(1,1,1);
    readimagefile("img/f3.jpg",scx*0,scy*80,scx*400,scy*480);
    readimagefile("img/prev.jpg",scx*360,scy*498,scx*428,scy*554);
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 14:familia();
                case 9:familia();

        }

    }while(1);
    closegraph();
}

void familia()
{
    bar("familia");
    buton(1,1,1);
    readimagefile("img/f1.jpg",scx*0,scy*80,scx*400,scy*480);
    readimagefile("img/f2.jpg",scx*400,scy*80,scx*800,scy*480);
    readimagefile("img/next.jpg",scx*360,scy*498,scx*428,scy*554);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 9:familia1();

        }

    }while(1);
    closegraph();
}
void slide()
{
            readimagefile("img/asteapta.jpg",scx*74,scy*526,scx*726,scy*576);
            readimagefile("img/p1.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(3000);
            readimagefile("img/p2.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(7000);
            readimagefile("img/p3.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(7000);
            readimagefile("img/p4.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(7000);
            readimagefile("img/p5.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(7000);
            readimagefile("img/p6.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(7000);
            readimagefile("img/p7.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(7000);
            readimagefile("img/p8.jpg",scx*74,scy*94,scx*726,scy*526);
                delay(7000);

}
void prezentarea()
{
    bar("prezentarea");
    buton(1,1,1);
    readimagefile("img/porneste.jpg",scx*325,scy*225,scx*475,scy*375);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 10:slide(),prezentarea();

        }

    }while(1);
    closegraph();
}
void numerele2()
{
    bar("numerele 2/2");
    buton(1,1,1);
    readimagefile("img/30.jpg",scx*150,scy*100,scx*350,scy*500);
    readimagefile("img/100.jpg",scx*450,scy*100,scx*650,scy*500);
    readimagefile("img/prev.jpg",scx*360,scy*498,scx*428,scy*554);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 9:numerele();

        }

    }while(1);
    closegraph();
}

void numerele()
{
    bar("numerele 1/2");
    buton(1,1,1);
    readimagefile("img/0.jpg",scx*150,scy*100,scx*350,scy*500);
    readimagefile("img/11.jpg",scx*450,scy*100,scx*650,scy*500);
    readimagefile("img/next.jpg",scx*360,scy*498,scx*428,scy*554);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);
                case 9:numerele2();

        }

    }while(1);
    closegraph();
}
void alfabetul()
{
    bar("alfabetul");
    buton(1,1,1);
    readimagefile("img/a.jpg",scx*150,scy*100,scx*350,scy*500);
    readimagefile("img/m.jpg",scx*450,scy*100,scx*650,scy*500);
    mousetrece();
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 12:ajutor();
                case 13:meniu();
                case 11:exit(1);

        }

    }while(1);
    closegraph();
}
void meniu2()
{

    bar("meniu 2/2");
    buton(1,1,0);
    readimagefile("img/corpul.jpg",scx*20,scy*110,scx*297,scy*187);
    readimagefile("img/haine.jpg",scx*20,scy*207,scx*297,scy*284);
    readimagefile("img/culorile.jpg",scx*20,scy*304,scx*297,scy*381);
    readimagefile("img/vremea.jpg",scx*20,scy*401,scx*297,scy*478);
    readimagefile("img/zile.jpg",scx*500,scy*110,scx*777,scy*187);
    readimagefile("img/ora.jpg",scx*500,scy*207,scx*777,scy*284);
    readimagefile("img/intrebari.jpg",scx*500,scy*304,scx*777,scy*381);
    readimagefile("img/expresi.jpg",scx*500,scy*401,scx*777,scy*478);

    readimagefile("img/prev.jpg",scx*360,scy*498,scx*428,scy*554);
    readimagefile("img/test2.jpg",scx*600,scy*500,scx*800,scy*600);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {

       int x=mousex();
       int  y=mousey();
        int zona1=unde_meniu(x,y);
        switch(zona1)
        {
                case 11:readimagefile("img/exitactiv.jpg",scx*747,scy*15,scx*787,scy*45);break;
                case 12:readimagefile("img/helpactiv.jpg",scx*700,scy*15,scx*740,scy*45);;break;
                case 0:readimagefile("img/exit.jpg",scx*747,scy*15,scx*787,scy*45),readimagefile("img/help.jpg",scx*700,scy*15,scx*740,scy*45);break;

        }
    }
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 1:lectie2("Partile corpului","img/corp.jpg");break;
                case 2:lectie2("Imbrcaminte","img/imbracaminte.jpg");break;
                case 3:lectie2("Culorile","img/culoare.jpg");break;
                case 4:lectie2("Vremea","img/vreme.jpg");break;
                case 5:lectie2("Lunile & Zilele","img/zi.jpg");break;
                case 6:lectie2("Ora","img/timp.jpg");break;
                case 7:lectie2("Intrebari","img/intrebare.jpg");break;
                case 8:lectie2("Expresi","img/expresie.jpg");break;
                case 11:exit(1);
                case 12:ajutor();
                case 9:meniu();

        }

    }while(1);
    closegraph();
}
void load()
{
    readimagefile("img/atestat.jpg",scx*0,scy*0,scx*800,scy*600);
    readimagefile("img/logo.jpg",scx*280,scy*50,scx*520,scy*90);
    readimagefile("img/load/incarca.jpg",scx*200,scy*380,scx*600,scy*480);
    readimagefile("img/load/logoextend.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/a.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/b.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextenda.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/c.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/d.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextendb.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/e.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/f.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextendc.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/g.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/h.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextendd.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/i.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/j.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/k.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextende.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/l.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/m.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextendf.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/n.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/o.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextendg.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/p.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/q.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/logoextendh.jpg",scx*250,scy*100,scx*550,scy*400);
    readimagefile("img/load/r.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/s.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(400);
    readimagefile("img/load/t.jpg",scx*200,scy*485,scx*600,scy*500);
    delay(1000);
    cleardevice();
    meniu();
}
void meniu()
{
    bar("meniu 1/2");
    buton(1,1,0);
    readimagefile("img/alfabetul.jpg",scx*20,scy*110,scx*297,scy*187);
    readimagefile("img/numerele.jpg",scx*20,scy*207,scx*297,scy*284);
    readimagefile("img/prezentarea.jpg",scx*20,scy*304,scx*297,scy*381);
    readimagefile("img/familia.jpg",scx*20,scy*401,scx*297,scy*478);
    readimagefile("img/pronumele.jpg",scx*500,scy*110,scx*777,scy*187);
    readimagefile("img/alimentatie.jpg",scx*500,scy*207,scx*777,scy*284);
    readimagefile("img/animale.jpg",scx*500,scy*304,scx*777,scy*381);
    readimagefile("img/plante.jpg",scx*500,scy*401,scx*777,scy*478);
    readimagefile("img/next.jpg",scx*360,scy*498,scx*428,scy*554);
    readimagefile("img/test.jpg",scx*600,scy*500,scx*800,scy*600);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {

       int x=mousex();
       int  y=mousey();
        int zona1=unde_meniu(x,y);
        switch(zona1)
        {
                case 11:readimagefile("img/exitactiv.jpg",scx*747,scy*15,scx*787,scy*45);break;
                case 12:readimagefile("img/helpactiv.jpg",scx*700,scy*15,scx*740,scy*45);;break;
                case 0:readimagefile("img/exit.jpg",scx*747,scy*15,scx*787,scy*45),
                readimagefile("img/help.jpg",scx*700,scy*15,scx*740,scy*45);break;
        }
    }
    do
     {
        while(!ismouseclick(WM_LBUTTONDOWN));
        int x=mousex();
        int  y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        clearmouseclick(WM_LBUTTONDOWN);
        int zona=unde_meniu(x,y);
        switch(zona)
        {
                case 1:alfabetul();break;
                case 2:numerele();break;
                case 3:prezentarea();break;
                case 4:familia();break;
                case 5:pronumele();break;
                case 6:alimentatie();break;
                case 7:animalele();break;
                case 8:plante();break;
                case 9:meniu2();break;
                case 14:testtraducere();break;
                case 11:exit(1);
                case 12:ajutor();
        }

    }while(1);
    closegraph();
}
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    closegraph();
    initwindow(scx*800,scy*600,"",getmaxwidth()/2-scx*400,getmaxheight()/2-scy*300);
    load();
}
