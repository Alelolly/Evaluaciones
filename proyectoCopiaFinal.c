#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct fecha
{
    int dia;
    char mes[50];
    int anyo;
};

struct trabajador
{
    int cedula;
    char nombre[100];
    int departamento;
    int cargo;
    float sueldo;
    struct fecha ingreso;
};

void menu();
void ingresar(struct trabajador _trabajadores[], int* _size);
void consultar(struct trabajador _trabajadores[], int _size);
void modificar(struct trabajador _trabajadores[], int _size);
void eliminar(struct trabajador _trabajadores[], int* _size);

int cargar_empleados(struct trabajador _trabajadores[], char* filename);
void guardar_empleados(struct trabajador _trabajadores[], int _size, char* filename);
void agregar_empleados(struct trabajador _trabajadores[], int* size);
void mostrar_empleado(struct trabajador _trabajadores[], int size);

int consulta_cedula(struct trabajador _trabajadores[], int _size);
int consulta_departamento(struct trabajador _trabajadores[], int _size, int dept, float* sueldos);
int consulta_cargo(struct trabajador _trabajadores[], int _size, int carg, float* sueldos);
void consulta_sueldo(struct trabajador _trabajadores[], int _size);

int v; //Variable de control
bool corriendo;

int main()
{
    struct trabajador trabajadores[100];
    int size = cargar_empleados(trabajadores, "trabajadores.in");
    v = 0;
    corriendo = true;
    while(corriendo == true)
    {
        switch (v)
        {
        case 1:
            //system("clr");
            ingresar(trabajadores, &size);
            break;
        case 2:
            //system("clr");
            consultar(trabajadores, size);
            break;
        case 3:
            //system("clr");
            modificar(trabajadores, size);
            break;
        case 4:
            //system("clr");
            eliminar(trabajadores, &size);
            break;
        case 5:
            //system("clr");
            guardar_empleados(trabajadores, size, "trabajadores.in");
            corriendo = false;
            break;
        case 6:
            for (int i = 0 ; i < size ; i++)
            {
                mostrar_empleado(trabajadores, i);
            }
            v = 0;
            break;
        default:
            //system("clr");
            menu();
            break;
        }
    }
}

//**************** Funciones Principales ****************//

//Esta funcion se encarga de abrir el menu del programa, y nada mas
void menu()
{
    printf("1.- Ingresar\n");
    printf("2.- Consultar\n");
    printf("3.- Modificar\n");
    printf("4.- Eliminar\n");
    printf("5.- Salir\n");
    printf("6.- Listar empleados\n");
    scanf("%d", &v);
}

void ingresar(struct trabajador _trabajadores[], int* _size)
{
    printf("---Agregando empleado---\n\n\n");
    agregar_empleados(_trabajadores,_size);
    v = 0;
}

void consultar(struct trabajador _trabajadores[], int _size)
{
    int w = 0; //Variable de control
    bool consultando = true;
    while(consultando == true)
    {
        printf("1.- Consulta por cedula\n");
        printf("2.- Consulta por departamento\n");
        printf("3.- Consulta por cargo\n");
        printf("4.- Consulta por mayor y menor sueldo\n");
        printf("5.- Cancelar consulta\n");
        scanf("%d", &w);
        float sueldos_totales = 0;
        int tamanyo;
        switch(w)
        {
            case 1:
                consultando = false;
                int indice = consulta_cedula(_trabajadores, _size);
                if(indice == -1)
                {
                    printf("Cedula no encontrada.\n");
                }
                else
                {
                    mostrar_empleado(_trabajadores, indice);
                }
                break;
            case 2:
                consultando = false;
                int dept;
                printf("\n 1. RRHH\t 2. Consultoria\t 3. Diseno\n 4. Producion\t 5. Calidad\t 6. Distribucion\n Ingrese el departamento: ");
                scanf("%d", &dept);
                sueldos_totales = 0;
                tamanyo = consulta_departamento(_trabajadores, _size, dept, &sueldos_totales);
                if(tamanyo > 0)
                {
                    printf("Hay %d empleados en el departamento.\n", tamanyo);
                    printf("El sueldo total del departamento es de %.2f$\n", sueldos_totales);
                }
                else
                {
                    printf("No hay empleados en el departamento.\n");
                }
                break;
            case 3:
                consultando = false;
                int carg;
                printf("\n 1. Gerente\t 2. Supervisor\t 3.Analista\n 4.Diseñador\t 5.Desarrollador\t 6. Auditor\n Ingrese el cargo: ");
                scanf("%d", &carg);
                sueldos_totales = 0;
                tamanyo = consulta_cargo(_trabajadores, _size, carg, &sueldos_totales);
                if(tamanyo > 0)
                {
                    printf("Hay %d empleados que poseen el cargo.\n", tamanyo);
                    printf("El sueldo total del cargo es de %.2f$\n", sueldos_totales);
                }
                else
                {
                    printf("No hay empleados que posean el cargo.\n");
                }
                break;
            case 4:
                consultando = false;
                consulta_sueldo(_trabajadores, _size);
                break;
            case 5:
                consultando = false;
                break;
            default:
                break;
        }
    }
    //mostrar_empleado(_trabajadores, _size);
    v = 0;
}

// Modulo 'Modificar'
void modificar(struct trabajador _trabajadores[], int _size)
{
    int ced;
    printf("Ingrese la cedula del empleado que desea alterar: ");
    scanf("%d", &ced);
    bool existe = false;
    int op;
    /*Vamos a recorrer a todos los trabajadores y encontrar el que tiene la cedula
    que buscamos*/
    int i = -1; //Iniciamos en -1 para poder guardar el indice en i
    while(!existe && i < _size)
    {
        i++; //Aumentamos i inmediatamente para no tirar un error
        if (_trabajadores[i].cedula == ced)
        {
            existe = true;
        }
    }
    bool seleccion_valida = false;
    //Si existe, le preguntamos al usuario que quiere hacer:
    while (existe && !seleccion_valida)
    {
        //Mostrar empleado en el arreglo de trabajadores, indice i
        mostrar_empleado(_trabajadores, i);
        printf("Seleccione que desea modificar:\n");
        printf("1. Nombre y apellido\t 2. Departamento\t 3. Cargo\t 4.Sueldo\n");
        scanf("%i",&op);
        switch (op)
        {
        case 1:
            printf("Ingrese nuevo nombre:");
            scanf("%s", _trabajadores[i].nombre);
            seleccion_valida = true;
            break;
        case 2:
            printf("Ingrese nuevo departamento:");
            scanf("%d", &_trabajadores[i].departamento);
            seleccion_valida = true;
            break;
        case 3:
            printf("Ingrese nuevo cargo:");
            scanf("%d", &_trabajadores[i].cargo);
            seleccion_valida = true;
            break;    
        case 4:
            printf("Ingrese nuevo sueldo:");
            scanf("%f", &_trabajadores[i].sueldo);
            seleccion_valida = true;
            break;
        default:
            break;
        }
    }
    if (!existe)
    {
        printf("No existe cedula registrada\n");
    }
    v = 0;
}

void eliminar(struct trabajador _trabajadores[], int* _size)
{
    FILE *fp2;
    struct fecha fechita;
    int decision, elim;
    int indice = consulta_cedula(_trabajadores, *_size);
    if(indice == -1)
    {
        printf("Cedula no encontrada.\n");
        v = 0;
        return 0;
    }
    else
    {
        mostrar_empleado(_trabajadores, indice);
    }
    printf("¿Seguro que desea eliminarlo? \nSi= 1/No= 2\n");
    scanf("%d", &decision);
    switch(decision){
        case 1:
        // agregando a los extrabajadores
            fp2 = fopen("extrabajadores.txt", "a");
            if(fp2==NULL)
            {
                printf("\nGenerando archivo..\n");
            }
            fprintf(fp2,"%s ", _trabajadores[indice].nombre);
            fprintf(fp2, "%d ", _trabajadores[indice].cedula);
            switch(_trabajadores[indice].departamento){
                case 1:
                    fprintf(fp2,"RRHH ");
                break;
                case 2:
                   fprintf(fp2,"Consultoria ");
                    break;
                case 3:
                    fprintf(fp2,"Diseño ");
                    break;
                case 4:
                    fprintf(fp2,"Produccion ");
                    break;
                case 5:
                    fprintf(fp2,"Calidad ");
                    break;
                case 6:
                    fprintf(fp2,"Distribucion ");
                    break;
                default:
                    break;
            }
            switch(_trabajadores[indice].cargo)
            {
                case 1:
                    fprintf(fp2,"Gerente ");
                    break;
                case 2:
                    fprintf(fp2,"Supervisor ");
                    break;
                case 3:
                    fprintf(fp2,"Analista ");
                    break;
                case 4:
                    fprintf(fp2,"Diseñador ");
                    break;
                case 5:
                    fprintf(fp2,"Desarrollador ");
                    break;
                case 6:
                    fprintf(fp2, "Auditor ");
                    break;
                default:
                    break;
            }
            fprintf(fp2,"%.2f$ ", _trabajadores[indice].sueldo);
            fprintf(fp2,"%d - %s - %d ", _trabajadores[indice].ingreso.dia, _trabajadores[indice].ingreso.mes, _trabajadores[indice].ingreso.anyo);
            printf("ingrese el motivo de eliminación:\n 1:Traslado, 2:Renuncia, 3:Despido, 4:Otro\n");
            scanf("%d", &elim);
            switch(elim)
            {
                case 1:
                    fprintf(fp2,"Traslado ");
                    break;
                case 2:
                    fprintf(fp2,"Renuncia ");
                    break;
                case 3:
                    fprintf(fp2,"Despido ");
                    break;
                case 4:
                    fprintf(fp2,"Caso Particular ");
                    break;
                default:
                    printf("VALOR INVALIDO\n\n");
                    break;
            }
            printf("ingrese la fecha de eliminacion:\n\n");
            printf("\n año:");
            scanf("%d", &fechita.anyo);
            printf("\n mes:");
            scanf("%s", &fechita.mes);
            printf("\n dia:");
            scanf("%d", &fechita.dia);
            fprintf(fp2, "%d - %s - %d", fechita.dia, fechita.mes, fechita.anyo);
            fclose(fp2);
            //borrando del archivo original
            for(int i = indice ; i < *_size -1; i++)
            {
                //eliminamos al trabajador
                for(int j=1;j < 100; j++)
                {
                    _trabajadores[i].nombre[j]= _trabajadores[i+1].nombre[j];
                }
                _trabajadores[i].cedula= _trabajadores[i+1].cedula;
                _trabajadores[i].departamento= _trabajadores[i+1].departamento;
                _trabajadores[i].cargo= _trabajadores[i+1].cargo;
                _trabajadores[i].sueldo= _trabajadores[i+1].sueldo;
                _trabajadores[i].ingreso.dia=_trabajadores[i+1].ingreso.dia;
                for(int k=1; k<50; k++)
                {
                    _trabajadores[i].ingreso.mes[k]=_trabajadores[i+1].ingreso.mes[k];
                }
                _trabajadores[i].ingreso.anyo=_trabajadores[i+1].ingreso.anyo;
            }
            (*_size)--;
            guardar_empleados(_trabajadores, *_size, "trabajadores.in");
            break;
        case 2:
            break;
        default:
            printf("VALOR INVALIDO\n\n");
            break;
        }
    v = 0;
}

//**************** Funciones Secundarias ****************//

int cargar_empleados(struct trabajador _trabajadores[], char* filename)
{
    FILE *fp; //Creamos un puntero de archivos
    fp = fopen("trabajadores.in", "r"); //Abrimos nuestro archivo en modo escritura
    if(fp == NULL) //Si el archivo no existe
    {
        printf("Generando nuevo archivo...\n");
        return 0; //Retorna 0, para asi saber que el arreglo no contiene nada
    }
    int _size; //Si no, crea una variable entera
    /*En esta variable vamos a leer el primer elemento de nuestro archivo, que debe ser la
    cantidad de empleados, es decir, el tamanyo del arreglo de trabajadores*/
    fread(&_size, sizeof(int), 1, fp);
    //Luego, leemos el segundo elemento del archivo, que es el arreglo de trabajadores en si
    fread(_trabajadores, sizeof(struct trabajador), 1, fp);
    //Y cerramos el archivo:
    fclose(fp);
    return _size;
}

void guardar_empleados(struct trabajador _trabajadores[], int _size, char* filename)
{
    FILE *fp; //Creamos un puntero de archivos
    fp = fopen("trabajadores.in", "w"); //Abrimos un archivo
    if(fp == NULL) //Si no existe, hubo un error
    {
        printf("Error abriendo archivo");
        exit(1);
    }
    /*Escribimos en la primera posicion de nuestro archivo el tamanyo del
    arreglo de trabajadores para si poder leerlo despues*/
    fwrite(&_size, sizeof(int), 1, fp);
    /*Escribimos en la segunda posicion del archivo, nuestro arreglo de
    trabajadores:*/
    fwrite(_trabajadores, sizeof(struct trabajador), _size, fp);
    //Cerramos nuestro archivo
    fclose(fp);
}

void agregar_empleados(struct trabajador _trabajadores[], int* size)
{
    /*Leemos en la ultima posicion del arreglo de trabajadores (size)
    los datos del nuevo trabajador:*/
    printf("    Ingrese la cedula del empleado: ");
    scanf("%d", &_trabajadores[*size].cedula);

    fgets(_trabajadores[*size].nombre,50,stdin); // ¿Porque dos veces? - Cesar
    printf("\n    Ingrese el nombre del empleado: ");
    fgets(_trabajadores[*size].nombre,50,stdin); //Ahora se puede escribir con espacios

    //1=RRHH 2=Consultoria 3=Diseño 4=Produccion 5=Calidad 6=Distribucion
    printf("\n    1. RRHH\t 2. Consultoria\t 3. Diseno\n 4. Producion\t 5. Calidad\t 6. Distribucion\n Ingrese el departamento del empleado:"); 
    scanf("%d", &_trabajadores[*size].departamento); 
    
    //1=Gerente 2=Supervisor 3=Analista 4=Diseñador 5=Desarrollador 6=Auditor
    printf("\n   1. Gerente\t 2. Supervisor\t 3.Analista\n 4.Diseñador\t 5.Desarrollador\t 6. Auditor\n Ingrese el cargo del empleado: \n"); 
    scanf("%d", &_trabajadores[*size].cargo);
    
    printf("\n    Ingrese el sueldo del empleado: ");
    scanf("%f", &_trabajadores[*size].sueldo);

    /*Aqui leemos la siguiente estructura, fecha, que guarda
    el anyo, mes y dia en que se empleo el nuevo trabajador.*/
    printf("\n    Ingrese el año en que se empleo: "); //anyo es de tipo entero
    scanf("%d", &_trabajadores[*size].ingreso.anyo);
    printf("\n    Ingrese el mes en que se empleo: "); //Mes es de tipo cadena
    scanf("%s", _trabajadores[*size].ingreso.mes);
    printf("\n    Ingrese el dia en que se empleo: "); //Dia es de tipo entero
    scanf("%d", &_trabajadores[*size].ingreso.dia);
    (*size)++; //Aumentamos la dimension de nuestro arreglo de trabajadores en uno
}

void mostrar_empleado(struct trabajador _trabajadores[], int indice)
{
    printf("\nNombre: %s\n", _trabajadores[indice].nombre);
    printf("Cedula: %d\n", _trabajadores[indice].cedula);
    printf("Departamento: ");
    switch(_trabajadores[indice].departamento)
    {
        case 1:
            printf("RRHH\n");
            break;
        case 2:
            printf("Consultoria\n");
            break;
        case 3:
            printf("Diseño\n");
            break;
        case 4:
            printf("Produccion\n");
            break;
        case 5:
            printf("Calidad\n");
            break;
        case 6:
            printf("Distribucion\n");
            break;
        default:
            printf("VALOR INVALIDO\n");
            break;
    }
    printf("Cargo: ");
    switch(_trabajadores[indice].cargo)
    {
        case 1:
            printf("Gerente\n");
            break;
        case 2:
            printf("Supervisor\n");
            break;
        case 3:
            printf("Analista\n");
            break;
        case 4:
            printf("Diseñador\n");
            break;
        case 5:
            printf("Desarrollador\n");
            break;
        case 6:
            printf("Auditor\n");
            break;
        default:
            printf("VALOR INVALIDO\n");
            break;
    }
    printf("Sueldo: %.2f$\n", _trabajadores[indice].sueldo);
    printf("Empleado el dia %d del mes %s del año %d\n\n", _trabajadores[indice].ingreso.dia, _trabajadores[indice].ingreso.mes, _trabajadores[indice].ingreso.anyo);
}

int consulta_cedula(struct trabajador _trabajadores[], int _size)
{
    int CI;
    printf("Ingrese la cedula a buscar: ");
    scanf("%d", &CI);
    for(int i = 0 ; i < _size ; i++)
    {
        if(CI == _trabajadores[i].cedula)
        {
            return i;
        }
    }
    return -1;
}

int consulta_departamento(struct trabajador _trabajadores[], int _size, int dept, float* sueldos)
{
    struct trabajador trabajadores_dept[100]; //Crea un arreglo de trabajadores, del departamento
    int size_dept = 0; //Aqui guardamos la cantidad de empleados en el departamento
    for(int i = 0 ; i < _size ; i++) //Recorremos todos los empleados
    {
        if(dept == _trabajadores[i].departamento) //Si esta en el departamento
        {
            //Copia sus datos en el arreglo de trabajadores en el departamento
            trabajadores_dept[i].cedula = _trabajadores[i].cedula;
            for(int t ; t < 100 ; t++)
            {
                trabajadores_dept[i].nombre[t] = _trabajadores[i].nombre[t];
            }
            trabajadores_dept[i].departamento = _trabajadores[i].departamento;
            trabajadores_dept[i].cargo = _trabajadores[i].cargo;
            trabajadores_dept[i].sueldo = _trabajadores[i].sueldo;
            trabajadores_dept[i].ingreso.anyo = _trabajadores[i].ingreso.anyo;
            for(int t ; t < 100 ; t++)
            {
                trabajadores_dept[i].ingreso.mes[t] = _trabajadores[i].ingreso.mes[t];
            }
            trabajadores_dept[i].ingreso.dia = _trabajadores[i].ingreso.dia;
            size_dept++;
            //Agrega su sueldo a los sueldos totales
            *sueldos += _trabajadores[i].sueldo;
        }
    }
    //Guarda a los empleados en departamento.txt
    guardar_empleados(trabajadores_dept, size_dept, "departamento.txt");
    return size_dept;
}

int consulta_cargo(struct trabajador _trabajadores[], int _size, int carg, float* sueldos)
{
    struct trabajador trabajadores_dept[100]; //Crea un arreglo de trabajadores, que posean el cargo
    int size_carg = 0; //Aqui guardamos la cantidad de empleados que poseen el cargo
    for(int i = 0 ; i < _size ; i++) //Recorremos todos los empleados
    {
        if(carg == _trabajadores[i].cargo) //Si posee el cargo
        {
            //Copia sus datos en el arreglo de trabajadores que poseen el cargo
            trabajadores_dept[i].cedula = _trabajadores[i].cedula;
            for(int t ; t < 100 ; t++)
            {
                trabajadores_dept[i].nombre[t] = _trabajadores[i].nombre[t];
            }
            trabajadores_dept[i].departamento = _trabajadores[i].departamento;
            trabajadores_dept[i].cargo = _trabajadores[i].cargo;
            trabajadores_dept[i].sueldo = _trabajadores[i].sueldo;
            trabajadores_dept[i].ingreso.anyo = _trabajadores[i].ingreso.anyo;
            for(int t ; t < 100 ; t++)
            {
                trabajadores_dept[i].ingreso.mes[t] = _trabajadores[i].ingreso.mes[t];
            }
            trabajadores_dept[i].ingreso.dia = _trabajadores[i].ingreso.dia;
            size_carg++;
            //Agrega su sueldo a los sueldos totales
            *sueldos += _trabajadores[i].sueldo;
        }
    }
    //Guarda a los empleados en departamento.txt
    guardar_empleados(trabajadores_dept, size_carg, "cargo.txt");
    return size_carg;
}

void consulta_sueldo(struct trabajador _trabajadores[], int _size)
{
    //Dos indices, uno para el mayor sueldo y uno para el menor
    int mayor = 0;
    int menor = 0;
    //Recorremos a todos los trabajadores uno por uno
    for(int i = 0 ; i < _size ; i++)
    {
        //Si el trabajador i tiene mas sueldo que el mayor, toma su lugar
        if (_trabajadores[i].sueldo > _trabajadores[mayor].sueldo)
        {
            mayor = i;
        }
        //Si el trabajador i tiene menos sueldo que el menor, toma su lugar
        if (_trabajadores[i].sueldo < _trabajadores[menor].sueldo)
        {
            menor = i;
        }
    }
    //Mostramos por pantalla a los trabajadores
    printf("Trabajador con mayor sueldo:");
    mostrar_empleado(_trabajadores, mayor);
    printf("Trabajador con menor sueldo:");
    mostrar_empleado(_trabajadores, menor);
}