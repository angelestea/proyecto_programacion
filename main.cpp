#include <iostream>
#include <windows.h>
#include <conio.h>
#include<windows.h>
#include<conio.h>



#define user "Administrador" //Se inicializa el usuario
#define pass "prueba" //Se inicializa la contraseña
#define user2 "Docente"
#define pass2 "prueba2"


using namespace std;

int main()
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,2);//Cambio de color ejemplo de conflicto
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
    for(int i=0;i<20;i++){//conflicto ejemplo
        for(int j=0;j<20;j++){
            if(logo[i][j]==1)cout<<char(219);//logo con matriz
            else cout<<" ";
        }
        cout<<endl;
    }
    string usuario, password;
    int personal;
    //docente y administrador
    cout<<"1.Docente"<<endl;
    cout<<"2.Administrador"<<endl;
    cout<<endl;
    cin>>personal;
    if (personal==1){
        system("cls");//Limpia la consola
        cout<<"*Ingreso al sistema como docente*"<<endl;//si el usuario coloca 1 ingresa al if e imprimirá el cout
        cout<<endl;
        //cout<<endl;
        cout<<"\t=================="<<endl;
        cout<<"\t|Login de docencia|"<<endl;
        cout<<"\t=================="<<endl;
        cout<<"Usuario: ";//Se solicita al usuario ingresar el usuario precisamente, en este caso es "Docente".
        getline(cin, usuario);//getline lee el usuario digitado.
        cout<<"Password: ";
        getline(cin, password);//Igualmente aquí con la diferencia de que esta vez será con la contraseña.
    }else{
        if(personal==2){
            system("cls");
            cout<<"Ingreso del sistema como administrador"<<endl;//si el usuario coloca 2 ingresa al if e imprimira el cout
        }else{
            cout<<"Datos Incorrectos"<<endl;//si el usurio escribe un numero diferente a 1 o 2
        }

    }
    //crear curso





    //registrar nota




    //modificar





    //crear curso




    getch();
    return 0;
}
