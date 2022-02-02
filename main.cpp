#include <iostream>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<fstream>
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
{0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,0,0,1,0,1},
{0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,0,0,1,0,1},
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
    string usuario="";
    int personal=0,password=0,nuevo=0;
    int curso=0,cursoex=0,remplazo=0;
    string nombrecurso,texto,rem;
    //docente y administrador
    cout<<"1.Docente"<<endl;
    cout<<"2.Administrador"<<endl;
    cout<<endl;
    cin>>personal;
    if (personal==1){
        system("cls");//Limpia la consola
        cout<<"*Ingreso al sistema como docente*"<<endl;//si el usuario coloca 1 ingresa al if e imprimirá el cout
        cout<<endl;
        cout<<"\t=================="<<endl;
        cout<<"\t|Login de docencia|"<<endl;
        cout<<"\t=================="<<endl;
        cout<<endl;
        cout<<"Usuario: ";//Se solicita al usuario ingresar el usuario precisamente, en este caso es "Docente".
        cin.ignore();
        getline(cin,usuario);
        cout<<endl;
        cout<<endl;
        cout<<"Password: ";
        cin>>password;//Igualmente aquí con la diferencia de que esta vez será con la contraseña.
    }else{
        if(personal==2){
            system("cls");
            cout<<"Ingreso del sistema como administrador"<<endl;//si el usuario coloca 2 ingresa al if e imprimira el cout
            cout<<endl;
            cout<<"Usuario: ";//Se solicita al usuario ingresar el usuario precisamente, en este caso es "Docente".
            cin.ignore();
            getline(cin,usuario);
            cout<<endl;
            cout<<endl;
            cout<<"Password: ";
            cin>>password;//Igualmente aquí con la diferencia de que esta vez será con la contraseña.
        }else{
            cout<<"Datos Incorrectos"<<endl;//si el usurio escribe un numero diferente a 1 o 2
        }

    }
    //crear curso
    cout<<"Desa cerar un nuevo curso 1,2 para crear un nuevo alumno,3 crear nueva nota,4 modificar:";
    cin>>curso;//variable para tipo entero que servira para el condicionla en la parte inferior
    if(curso==1){
        ofstream archivo1;//declarar la variabe de un archivo para ingresar datos
        archivo1.open("cursos.txt",ios::app);//abrir el archivo tipo app para incluir cosas
        if(archivo1.fail()){
            cout<<"No se pudo abrir el archivo";
            exit(1);
            }
        cout<<"Ingrese el nombre del curso:";
        cin.ignore();
        getline(cin,nombrecurso);
        archivo1<<nombrecurso<<endl;//se almacenaran que que el ususario ingrese en la variabe
        archivo1.close();
        cout<<"Desa saber los cursos existentes 1 si 0 no:";
        cin>>cursoex;//variable tipo int que sirve para el bucle
        if(cursoex==1){
            ifstream archivo2;//variabel de archivo tipo lectura
            archivo2.open("cursos.txt",ios::in);//abrir el archivo , ios::in para lectura
            if(archivo2.fail()){
            cout<<"No se pudo abrir el archivo";//en caso de error
            exit(1);}
            while(!archivo2.eof()){
                getline(archivo2,texto);
                if(texto==nombrecurso){
                    //eliminar el ultimo curso ingrsado PENDIENTE
                    cout<<"Pendiente";
                }
                cout<<texto<<endl;//Imprime en pantalla lo que se encuneta en cursos.txt
            }
             archivo2.close();
        }
    }







    //registrar nota




    //modificar





    //crear curso




    getch();
    return 0;
}
