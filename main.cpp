y6h #include <iostream>
#include ".funciones/funciones.hpp"
using namespace std;

//  PUNTO 1
void burbujaMejorado(int v[], int n)
{
    int i, j, aux;

    for (int i = 1; i < n; i++)
    {
        int cont = 0;
        for (int j = 1; j < n; j++)
        {
            if (v[j - 1] > v[j])
            {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;        
            }
            else
            {
                cont++;
            }
        }
        
        if (cont == n - 1)
        {
            break;
        }
    }
}

// PUNTO 2
void burbujaMejoradoCadena(string s[], int n)
{
    string aux;

    for (int i = 1; i < n; i++)
    {
        int cont = 0;
        for (int j = 1; j < n; j++)
        {
            if (toLowerCase(s[j - 1]) < toLowerCase(s[j]))
            {
                aux = s[j];
                s[j] = s[j - 1];
                s[j - 1] = aux;        
            }
            else
            {
                cont++;
            }
        }
        
        if (cont == n - 1)
        {
            break;
        }
    }
}

// PUNTO 3
void cambiarRegistros(Registro r[], int j)
{
    Registro aux;

    aux.c1 = r[j].c1;
    r[j].c1 = r[j - 1].c1;
    r[j - 1].c1 = aux.c1;  

    aux.c2 = r[j].c2;
    r[j].c2 = r[j - 1].c2;
    r[j - 1].c2 = aux.c2;   
}

void ordenarPorDosCampos(Registro r[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int cont = 0;
        for (int j = 1; j < n; j++)
        {
            if (r[j - 1].c1 > r[j].c1)
            {
                cambiarRegistros(r, j);
            }
            else
            {
                if (r[j - 1].c1 == r[j].c1)
                {   
                    if (r[j - 1].c2 > r[j].c2)
                    {
                        cambiarRegistros(r, j);
                    }
                    else
                    {
                        cont++;
                    }
                }
                else
                {
                    cont++;
                }
            }
        }
      
        if (cont == n - 1)
        {
            break;
        }
    }  
}

// PUNTO 4
template <typename T> 
void ordenarVectorT(T v[], int n) 
{
    for (int i = 1; i < n; i++)
    {
        int cont = 0;

        // ------------------------------------------------
        for (int j = 1; j < n; j++)
        {
            if (v[j-1].c1 > v[j].c1)
            {
                T aux1 = v[j];
                v[j] = v[j-1];
                v[j-1] = aux1;
            }
            else
            { 
                if (v[j-1].c1 == v[j].c1)
                {
                    if(v[j-1].c2 > v[j].c2)
                    {
                        T aux2 = v[j];
                        v[j] = v[j - 1];
                        v[j - 1] = aux2;  
                    }
                    else
                    {
                        cont++;
                    }
                }
                else
                {
                    cont++;
                }
            }
        }
        // ------------------------------------------------
        
        if (cont == n - 1)
        {
            break;
        }
    }
}

// PUNTO 5 

template <typename T, typename K, typename V> 
void ordenarVectorTC(T v[], int n, int criterio1(K, K), int criterio2(V, V)) 
{
    for (int i = 1; i < n; i++)
    {
        int cont = 0;

        for (int j = 1; j < n; j++)
        {
            if (criterio1(v[j-1].c1, v[j].c1) > 0)
            {
                T aux1 = v[j];
                v[j] = v[j-1];
                v[j-1] = aux1;
            }
            else
            { 
                if (criterio1(v[j-1].c1, v[j].c1) == 0)
                {
                    if(criterio2(v[j-1].c2, v[j].c2) > 0)
                    {
                        T aux2 = v[j];
                        v[j] = v[j - 1];
                        v[j - 1] = aux2;  
                    }
                    else
                    {
                        cont++;
                    }
                }
                else
                {
                    cont++;
                }
            }
        }
        
        if (cont == n - 1)
        {
            break;
        }
    }
}

// El usuario provee funciones con tipos de datos declarados

int main(){

    Registro r[4];

    r[0].edad = 10;
    r[0].nombre = "Juan";

    r[1].edad = 43;
    r[1].nombre = "Maria";

    r[2].edad = 22;
    r[2].nombre = "Carlos";

    r[3].edad = 43;
    r[3].nombre = "Jose";


    cout << "Vector original:" << endl;
    mostrarArrayDeRegistro(r, 4);

    ordenarVectorTC(r, 4, compararInt09, compararStringAZ);

    cout << "Vector ordenado:" << endl;
    mostrarArrayDeRegistro(r, 4);
    
    return 0;
}
