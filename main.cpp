#include <iostream>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#define docente "Juan Torres"//------
#define admin "Juliana Zambrano"//----
#define contradocen 123456//---------->Constantes para el ingreso de profesores y contraseña respectiva
#define contraadmin 123456//---------


using namespace std;

void crearcurso();//para definir la función en scope global

void crearNuevoAlumno();//--->se define función crearNuevoAlumno en scope global

void crearNuevaNota();//para definir la función en scope global

void eliminar();//-->Para eliminar curso y alumno

int main()
{
    int x=0;
    string usuario;
    int personal=0,password=0,nuevo=0;
    int opcion=0,cursoex=0;
    do{
        int s=1;
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
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(logo[i][j]==1)cout<<char(219);//logo con matriz
                else cout<<" ";
            }
            cout<<endl;
        }
        cout<<"Sistema de uso academico para docente y administrador..."<<endl;
        cout<<endl;
        //docente y administrador
        cout<<"1.Docente"<<endl;
        cout<<"2.Administrador"<<endl;
        cout<<endl;
        cin>>personal;
        if(personal!=1 || personal!=2){
            cout<<"\nLos datos ingresados son incorrectos, vuelva a iniciar\n el programa para volver a internar su ingreso"<<endl;
            break;
            getch();
        }
        if (personal==1){
            system("cls");//Limpia la consola
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
                cout<<"\t========================"<<endl;
                cout<<"\t|Login de administrador|"<<endl;
                cout<<"\t========================"<<endl;
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
        while(s<=3){
            if (usuario==docente && contradocen){
                s=4;
                system("cls");
                cout<<"1. Crear un nuevo curso"<<endl;
                cout<<"2. Crear un nuevo alumno"<<endl;
                cout<<"3. Crear nueva nota"<<endl;
                cout<<"4. Modificar"<<endl;
                cout<<"5. Eliminar"<<endl;
                cout<<"6. Salir"<<endl;
                cin>>opcion;//variable para tipo entero que servira para el condicionla en la parte inferior
                system("cls");
                switch(opcion){
                    case 1:{
                        crearcurso();
                        break;
                    }
                    case 2:{
                        crearNuevoAlumno();
                        break;
                    }
                    case 3:{
                        crearNuevaNota();
                        break;
                    }
                    case 4:{
                    //modificar
                        break;
                    }
                    case 5:{
                        eliminar();
                        break;
                    }
                    default:{
                        x=999;
                        cout<<"Programa finalizado..."<<endl;
                    }

                }
            }else{
                system("cls");
                cout<<endl;
                cout<<"Datos incorrectos...\n"<<endl;
                cout<<"Usuario: ";
                cin.ignore();
                getline(cin,usuario);
                cout<<"\n";
                cout<<"Password: ";
                cin>>password;//Igualmente aquí con la diferencia de que esta vez será con la contraseña.
                s++;
            }
        }
    }while(x<999);
    getch();
    return 0;
}
void crearcurso(){
    system("cls");
        HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,7);
    int cursoex=0;
    string nombrecurso,texto;
    ofstream archivo1;//declarar la variabe de un archivo para ingresar datos
    cout<<"Ingrese el nombre del curso:";
    cin.ignore();
    getline(cin,nombrecurso);

    archivo1.open(nombrecurso.c_str(),ios::out);//abrir el archivo tipo app para incluir cosas

    if(archivo1.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    cout<<"Curso creado...";
}

void crearNuevoAlumno(){
    system("cls");
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,3);
    char alumnosExistentes;
    int otroAlumno=0,x=0;
    string nombrecurso;
    string nombreAlumno, texto;
    ofstream archivo;//--->Declara la variable de archivo2 para ingresas datos
    cout<<"Ingrese el nombre del curso:"<<endl;
    cin>>nombrecurso;
    archivo.open(nombrecurso.c_str(), ios::app);//-->se declara app para agregar más datos

    if(archivo.fail()){
        cout<<"Archivo invalido";
        exit(1);
    }
    cout<<"Ingrese el nombre del alumno: "<<endl;
    cin.ignore();
    getline(cin,nombreAlumno);
    archivo<<nombreAlumno<<endl;
    do{
        system("cls");
        cout<<"1. Para ingresar otro alumno:\n 2.Para finalzar el programa."<<endl;
        cin>>otroAlumno;

        if(otroAlumno==1){
            cout<<"Ingrese el nombre del alumno: "<<endl;
            cin.ignore();
            getline(cin,nombreAlumno);
            archivo<<nombreAlumno<<endl;
            x++;
        }else{
            x=1000;
            cout<<"Fin del programa...";
        }
    }while(x<999);
    archivo.close();
}
void crearNuevaNota(){
    system("cls");
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,14);
    double notas=0;
    string texto,nombrecurso,resultado;
    ifstream archivo;

    cout<<"Ingrese el nombre del curso:"<<endl;
    cin>>nombrecurso;

    archivo.open(nombrecurso.c_str(),ios::in);
    if(archivo.fail()){
        cout<<"Archivo invalido";
        exit(1);}
        cout<<"Ingrese las notas de los alumnos:"<<endl;
    while(!archivo.eof()){
        getline(archivo,texto);
        ofstream archivo2;
        archivo2.open("temp.txt",ios::app);
        if(archivo2.fail()){
            cout<<"Archivo invalido";
            exit(1);}
            cout<<texto<<" : ";//escribira el nombre de las personas
            cin>>notas;//el susario podra ingresar notas
            if(notas>=7 && notas<=10){
                archivo2<<texto<<endl;//si esta entre 10 y 7 agrega al archivo lo que esta el la variable texto y lo nota que se encuntra
                archivo2<<notas<<endl;
                archivo2<<"Aprobado"<<endl;
                archivo2<<"-------------------------"<<endl;
            }else if(notas>=6&&notas<=4){
                archivo2<<texto<<endl;//si esta entre 10 y 7 agrega al archivo lo que esta el la variable texto y lo nota que se encuntra
                archivo2<<notas<<endl;
                archivo2<<"Remedial"<<endl;
                archivo2<<"-------------------------"<<endl;
            }else{
                archivo2<<texto<<endl;//si esta entre 10 y 7 agrega al archivo lo que esta el la variable texto y lo nota que se encuntra
                archivo2<<notas<<endl;
                archivo2<<"Reprobado"<<endl;
                archivo2<<"-------------------------"<<endl;
            }
    archivo2.close();
    }
    archivo.close();
    remove(nombrecurso.c_str());
    rename("temp.txt",nombrecurso.c_str());
}
void eliminar(){
    string nombrecurso,texto;
    string nomaux,nota;
    int opcion=0;
    cout<<"1.Eliminar curso\n2.Eliminar alumno"<<endl;
    cin>>opcion;
    ofstream archivo;
    ofstream temp;
    ifstream salida;
    if(opcion==1){
        cout<<"Ingrese el nombre del curso que desea eliminar:"<<endl;
        cin>>nombrecurso;
        archivo.open(nombrecurso.c_str(), ios::out);
        if(archivo.fail()){
        cout<<"Archivo invalido";
        exit(1);
        }
        archivo.close();
        remove(nombrecurso.c_str());
        cout<<"Curso eliminado..."<<endl;
        getch();
        system("cls");
    }if(opcion==2){
        system("cls");
        string nombrecurso;
        string nom;
        double nota;
        cout<<"Ingrese el nombre del curso, donde se encuentra el alumno a eliminar:"<<endl;
        cin>>nombrecurso;
        salida.open(nombrecurso.c_str(), ios::in);
        temp.open("Temp.txt", ios::out);
        if(salida.is_open()){
            cout<<"Nombre a eliminar: ";
            cin.ignore();
            getline(cin,nomaux);
            while(!salida.eof()){
                getline(salida,texto);
                if(nomaux==texto){
                    cout<<"Eliminado correctamente..."<<endl;
                    Sleep(1500);//--->Permite hacer una pausa por una cantidad determinada de segundos al programa
                }else{
                    temp<<texto<<endl;
                }
            }
        }

    }
}
