#include <iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

int main()
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,2);//Cambio de color
    int logo[20][20]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1},
{0,1,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1},
{0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1},
{0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1},
{0,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,0,1,0,1},
{0,1,1,1,0,1,1,1,0,0,1,0,0,1,0,0,0,1,0,1},
{0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1},
{0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1},
{0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1},
{0,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1},
{0,1,0,1,0,1,1,1,0,0,1,1,0,1,0,0,0,1,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(logo[i][j]==1)cout<<char(219);//logo con matriz
            else cout<<" ";
        }
        cout<<endl;
    }
    int personal;
    //docente y administrador
    cout<<"1.Docente"<<endl;
    cout<<"2.Administrador"<<endl;
    cout<<endl;
    cin>>personal;
    if (personal==1){
        system("cls");
        cout<<"Ingreso del sistema como docente"<<endl;
    }else{
        if(personal==2){
            system("cls");
            cout<<"Ingreso del sistema como administrador"<<endl;
        }else{
            cout<<"Datos Incorrectos"<<endl;
        }

    }
    //crear curso





    //registrar nota




    //modificar







    getch();
    return 0;
}
