#include <iostream>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <cstdlib>
#define docente "Juan Torres"
#define admin "Juliana Zambrano"
#define contradocen 123456
#define contraadmin 123456
using namespace std;

void crearcurso();//para definir la funci�n en scope global

void crearNuevoAlumno();//--->se define funci�n crearNuevoAlumno en scope global

void crearNuevaNota();//para definir la funci�n en scope global

void eliminar();//-->Para eliminar curso y alumno

void modifica();

void CorreNota();

void leerArchivo2();

void RenombrarAlumno();

void renombrarArchivo();

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
        cout<<"\tSistema de uso academico para docencia y administracion"<<endl;
        cout<<endl;
        //docente y administrador
        cout<<"\n\n\t1.Docente"<<endl;
        cout<<"\n\n\t2.Administrador"<<endl;
        cout<<"\n\n\t3.Salir"<<endl;
        cout<<"\n\n\t->";cin>>personal;
        if(personal==3){
            cout<<"\n\n\tSaliendo.."<<endl;
            break;
            getch();
        }
        if(personal!=1 && personal!=2){
            cout<<"\n\n\tLos datos ingresados son incorrectos, vuelva a iniciar el programa"<<endl;
            break;
            getch();
        }
        if (personal==1){
            system("cls");//Limpia la consola
            cout<<"\t=================="<<endl;
            cout<<"\t|Login de docencia|"<<endl;
            cout<<"\t=================="<<endl;
            cout<<endl;
            cout<<"\n\tUsuario: ";//Se solicita al usuario ingresar el usuario precisamente, en este caso es "Docente".
            cin.ignore();
            getline(cin,usuario);
            cout<<endl;
            cout<<endl;
            cout<<"\tPassword: ";
            cin>>password;//Igualmente aqu� con la diferencia de que esta vez ser� con la contrase�a.
        }else{
            if(personal==2){
                system("cls");
                cout<<"\t========================"<<endl;
                cout<<"\t|Login de administrador|"<<endl;
                cout<<"\t========================"<<endl;
                cout<<"\tUsuario: ";//Se solicita al usuario ingresar el usuario precisamente, en este caso es "Docente".
                cin.ignore();
                getline(cin,usuario);
                cout<<endl;
                cout<<endl;
                cout<<"\tPassword: ";
                cin>>password;//Igualmente aqu� con la diferencia de que esta vez ser� con la contrase�a.
            }else{
                cout<<"\n\tDatos Incorrectos"<<endl;//si el usurio escribe un numero diferente a 1 o 2
            }
        }
        while(s<=3){
            if (usuario==docente && password==contradocen){
                s=4;
                system("cls");
                cout<<"\n\t\t1. Crear un nuevo curso"<<endl;
                cout<<"\t\t2. Crear un nuevo alumno"<<endl;
                cout<<"\t\t3. Crear nueva nota"<<endl;
                cout<<"\t\t4. Modificar"<<endl;
                cout<<"\t\t5. Eliminar"<<endl;
                cout<<"\t\t6. Salir"<<endl;
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
                        modifica();//modificar
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
                if(usuario==admin && password==contraadmin){
                    s=4;
                    string nombrecurso,texto;
                    cout<<"Ingrese el curso para ver un informe de los alumnos:"<<endl;
                    cin>>nombrecurso;
                    ifstream archivo;
                    archivo.open(nombrecurso.c_str(),ios::in);
                    if(archivo.fail()){
                        cout<<"No se pudo abrir el archivo";
                        exit(1);}
                    system("cls");
                    while(!archivo.eof()){
                        getline(archivo,texto);
                        cout<<texto<<endl;
                    }
                getch();
                }else{
                    system("cls");
                    cout<<endl;
                    cout<<"\n\tDatos incorrectos...\n"<<endl;
                    cout<<"\tUsuario: ";
                    cin.ignore();
                    getline(cin,usuario);
                    cout<<"\n";
                    cout<<"\tPassword: ";
                    cin>>password;//Igualmente aqu� con la diferencia de que esta vez ser� con la contrase�a.
                    s++;
                }
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
    cout<<"\n\t\tIngrese el nombre del curso:";
    cin.ignore();
    getline(cin,nombrecurso);

    archivo1.open(nombrecurso.c_str(),ios::out);//abrir el archivo tipo app para incluir cosas

    if(archivo1.fail()){
        cout<<"\n\t\tNo se pudo abrir el archivo";
        exit(1);
    }
    cout<<"Curso creado...";
    system("cls");
    cout<<"\n\t\tCurso creado...";
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
    cout<<"\n\t\tIngrese el nombre del curso:"<<endl;
    cin>>nombrecurso;
    archivo.open(nombrecurso.c_str(), ios::app);//-->se declara app para agregar m�s datos

    if(archivo.fail()){
        cout<<"\n\t\tArchivo invalido";
        exit(1);
    }
    cout<<"\t\tIngrese el nombre del alumno: "<<endl;
    cin.ignore();
    getline(cin,nombreAlumno);
    archivo<<nombreAlumno<<endl;
    do{
        system("cls");
        cout<<"\t\t1. Para ingresar otro alumno:\n 2.Para finalzar el programa."<<endl;
        cin>>otroAlumno;

        if(otroAlumno==1){
            cout<<"\t\tIngrese el nombre del alumno: "<<endl;
            cin.ignore();
            getline(cin,nombreAlumno);
            archivo<<nombreAlumno<<endl;
            x++;
        }else{
            x=1000;
            cout<<"\t\tFin del programa...";
        }
    }while(x<999);
    archivo.close();
    system("cls");
}
void crearNuevaNota(){
    system("cls");
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,14);
    double notas=0;
    string texto,nombrecurso,resultado;
    ifstream archivo;

    cout<<"\n\t\tIngrese el nombre del curso:"<<endl;
    cin>>nombrecurso;

    archivo.open(nombrecurso.c_str(),ios::in);
    if(archivo.fail()){
        cout<<"\n\t\tArchivo invalido";
        exit(1);}
    cout<<"\n\t\tIngrese las notas de los alumnos:"<<endl;
    while(!archivo.eof()){
        getline(archivo,texto);
        ofstream archivo2;
        archivo2.open("temp.txt",ios::app);
        if(archivo2.fail()){
            cout<<"\n\t\tArchivo invalido";
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
    string nomaux,estado;
    estado="a";
    double nota;
    int opcion=0;
    cout<<"\n\t\t1.Eliminar curso\n2.Eliminar alumno"<<endl;
    cin>>opcion;
    ofstream archivo;
    ofstream temp;
    ifstream salida;
    if(opcion==1){
        cout<<"\n\t\tIngrese el nombre del curso que desea eliminar:"<<endl;
        cin>>nombrecurso;
        archivo.open(nombrecurso.c_str(), ios::out);
        if(archivo.fail()){
        cout<<"Archivo invalido";
        exit(1);
        }
        archivo.close();
        remove(nombrecurso.c_str());
        cout<<"\n\t\tCurso eliminado..."<<endl;
        getch();
        system("cls");
    }if(opcion==2){
        system("cls");
        string nombrecurso;
        string nom;
        double nota;
        cout<<"\n\t\tIngrese el nombre del curso, donde se encuentra el alumno a eliminar:"<<endl;
        cin>>nombrecurso;
        salida.open(nombrecurso.c_str(), ios::in);
        temp.open("Temp.txt", ios::out);
        if(salida.is_open()){
            cout<<"\n\t\tNombre a eliminar: ";
            cin.ignore();
            getline(cin,nomaux);
            while(!salida.eof()){
                getline(salida,texto);
                if(nomaux==texto){
                    cout<<"Eliminado..."<<endl;
                    cout<<"\n\t\tEliminado correctamente..."<<endl;
                    Sleep(1500);//--->Permite hacer una pausa por una cantidad determinada de segundos al programa
                }else{
                    temp<<texto<<endl;
                }
            }
        }

    }
}
bool existeArchivo(char nombreA[100])
{
    fstream archivo;
    archivo.open(nombreA,std::ios::in);
    if(archivo.good()==true)
    {
        return true;
    }else
    {
        return false;
    }

}
void modifica(){
    system("cls");
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,1005);
    int op=0;
    cout<<"\n\t\t�Que parte desea modificar?"<<endl;
    cout<<"1. Un curso"<<endl;
    cout<<"2. Un alumno"<<endl;
    cout<<"3. Una nota"<<endl;
    cin>>op;
    if (op==1)
    {renombrarArchivo();}
    if (op==2)
    {RenombrarAlumno();}
    if (op=3)
    {CorreNota();}
}
void renombrarArchivo()
{
    char originalN[100],nuevoN[100];
    cout<<"\n\t\tIngrese el nombre del curso a buscar:"<<endl;
    cin>>originalN;
    if(existeArchivo(originalN)==true)
    {
        cout<<"Ingrese el nuevo nombre: "<<endl;
        cin>>nuevoN;
        if(rename(originalN,nuevoN)==0)
        {
            cout<<"El archivo {"<<originalN<<"} Fue renombrado como: {"<<nuevoN<<"}"<<endl;
            system("pause");
        }
    }else{
        cout<<"El archivo {"<<originalN<<"} No existe"<<endl;
    }

}

void RenombrarAlumno()
{
    system("cls");
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,3);
    fstream archivo;
    string nombrecurso, texto;
    cout<<"\n\t\tIngrese el nombre del curso del alumno:"<<endl;
    cin>>nombrecurso;
    void leerArchivo2();
    system("pause");
}

void leerArchivo2()
{
    fstream archivo;
    string nombrecurso, texto;
    archivo.open(nombrecurso.c_str(),ios::in);
    if(archivo.is_open()){
        char c;
        while(!archivo.eof())
        {
            c=archivo.get();
            cout<<c;
        }
        archivo.close();
    }else{cout<<"No se encontro el archivo"<<endl;}
    system("pause");
}
void CorreNota()
{
    system("cls");
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//Cambio de color
    SetConsoleTextAttribute(hConsole,8);
    fstream archivo;
    string nombrecurso, texto;
    cout<<"\n\t\tIngrese el nombre del curso del alumno:"<<endl;
    cin>>nombrecurso;
    void leerArchivo2();
    system("pause");
}
