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
    int cursoex=0;

    string nombrecurso,texto;
    ofstream archivo1;//declarar la variabe de un archivo para ingresar datos

    archivo1.open("cursos.txt",ios::app);//abrir el archivo tipo app para incluir cosas

    if(archivo1.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    system("cls");

    cout<<"Ingrese el nombre del curso:";
    cin.ignore();
    getline(cin,nombrecurso);

    archivo1<<nombrecurso<<endl;//se almacenará lo que el ususario ingrese en la variabe
    archivo1.close();

    cout<<"Desea saber los cursos existentes 1 si 0 no:";
    cin>>cursoex;//variable tipo int que sirve para el condicional

    if(cursoex==1){
        ifstream archivo2;//variable de archivo tipo de lectura
        archivo2.open("cursos.txt",ios::in);//abrir el archivo, ios::in para lectura

        if(archivo2.fail()){
        cout<<"No se pudo abrir el archivo";//en caso de error
        exit(1);}

        while(!archivo2.eof()){
            getline(archivo2,texto);
            cout<<texto<<endl;//Imprime en pantalla lo que se encuentra en cursos.txt
        }
             archivo2.close();
    }
}

void crearNuevoAlumno(){
    char alumnosExistentes;
    char otroAlumno;
    string nombreAlumno, texto;
    ofstream archivo;//--->Declara la variable de archivo2 para ingresas datos

    archivo.open("alumnos.txt", ios::app);//-->se declara app para agregar más datos

    if(archivo.fail()){
        cout<<"Archivo invalido";
        exit(1);
    }

    system("cls");

    cout<<"Ingrese el nombre del alumno: "<<endl;
    cin.ignore();
    getline(cin,nombreAlumno);

    archivo<<nombreAlumno<<endl;
    archivo.close();

    cout<<"Desea ingresar otro alumno? (S/N)"<<endl;
    cin>>otroAlumno;

    while(otroAlumno=='s'||otroAlumno=='S'){
    cout<<"Ingrese el nombre del alumno"<<endl;
    cin.ignore();
    getline(cin,nombreAlumno);

    archivo<<nombreAlumno<<endl;
    archivo.close();
    system("cls");//--->Sirve para limpiar pantalla

    cout<<"Desea ingresar otro alumno? (S/N)"<<endl;
    cin>>otroAlumno;
    };

    cout<<"Escriba 'S' si desea ver los alumnos existentes";
    cin>>alumnosExistentes;//---->se recepta la variable de tipo char para cumplir con la condicional a declarar a continuación

    if(alumnosExistentes=='S'|| alumnosExistentes=='s'){
        ifstream archivo1;//-->ifstream servirá para la lectura del file
        archivo1.open("alumnos.txt", ios::in);//--->Abrirá el archivo de alumnos creador previamente

        if(archivo1.fail()){
            cout<<"Archivo invalido";
            exit(1);
        }

        while(!archivo1.eof()){
            getline(archivo1,texto);
            cout<<texto<<endl;//--->imprimirá en pantalla el contenido del documento
        }
    }
}
