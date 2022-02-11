#include <iostream>
#include <windows.h>
#include <conio.h>


#define user "Administrador" //Se inicializa el usuario
#define pass "prueba" //Se inicializa la contraseña
#define user2 "Docente"
#define pass2 "prueba2"

#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<fstream>
#define docente "Juan Torres"
#define admin "Juliana Zambrano"
#define contradocen 546756
#define contraadmin 987654


using namespace std;

void crearcurso();//para definir la función en scope global

void crearNuevoAlumno();//--->se define función crearNuevoAlumno en scope global

void crearNuevaNota();//para definir la función en scope global

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
    int opcion=0,cursoex=0;
    cout<<"Sistema de uso academico para docente y administrador..."<<endl;
    cout<<endl;
    //docente y administrador
    cout<<"1.Docente"<<endl;
    cout<<"2.Administrador"<<endl;
    cout<<endl;
    cin>>personal;
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
    if (usuario==docente && contradocen==password||usuario==admin && contraadmin==password){
        cout<<"1. cerar un nuevo curso"<<endl;
        cout<<"2. crear un nuevo alumno"<<endl;
        cout<<"3. crear nueva nota"<<endl;
        cout<<"4. modificar"<<endl;
        cin>>opcion;//variable para tipo entero que servira para el condicionla en la parte inferior

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
                    remove("alumnos.txt");
                    rename("temp.txt","alumnos.txt");
             //registrar nota
            break;
            }
            case 4:{
            //modificar
            break;
            }

        }
    }else{
        cout<<endl;
        cout<<"Datos incorrectos..."<<endl;
    }

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
    string texto;
    ifstream archivo;
    archivo.open("alumnos.txt",ios::in);
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
            cout<<texto<<" : ";
            cin>>notas;
            if(notas>=7 && notas<=10){
                archivo2<<texto<<"---"<<notas<<"---aprobado"<<endl;
            }else if(notas>6&&notas<5){
                archivo2<<texto<<"---"<<notas<<"---reprobado"<<endl;
            }else{
                archivo2<<texto<<"---"<<notas<<"---remedial"<<endl;
            }
            archivo2.close();
    }
    archivo.close();
}
