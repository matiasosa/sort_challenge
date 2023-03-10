#include <iostream>

using namespace std;

// ESTRUCTURA

struct Registro
{
    int edad;
    string nombre;
};

// FUNCIONES DE COMPARACION

int compararInt09(int a, int b)
{
    return a - b;
}

int compararInt90(int a, int b)
{
    return b - a;
}

int compararStringAZ(string a, string b) 
{ 
	return a > b? 1: b > a? -1: 0; 
}

int compararStringZA(string a, string b) 
{ 
	return b > a? 1: a > b? -1: 0;
}

// OTROS

void mostrarArrayDeRegistro(Registro v[], int n)
{
    for (int i = 0; i < 4; i++)
    {
        cout<< v[i].c1 << ": " << v[i].c2 << endl;
    }
    cout << endl;
}

// PRUEBAS

template <typename T>
void mostrarArray(T v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int length(string s)
{
    int i;
    for(i = 0; s[i] != '\0'; i++);

    return i;
}

string toLowerCase(string s)
{
    string ret = "";
    for (int i = 0; i < length(s); i++)
    {
        s[i] >= 65 && s[i] <= 90? ret += (s[i] += 32): ret +=s[i]; 
    }
    return ret;
}