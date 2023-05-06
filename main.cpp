#include <iostream>
#include <fstream>
#include <string>
#include "filesystem"
#include <windows.h>

using namespace std;

int main() {
    int n;
    string nombre;
    int edad;
    string tipo;

    string direccion1 = "C:/Users/HUAWEI/Desktop/Impar";
    string direccion2 = "C:/Users/HUAWEI/Documents/Par";

    cout << "Cuantos archivos quieres crear:" << endl;
    cin >> n;

    if (n%2==0) {
        for (int i = 1; i <= n; i++) {
            string archivo = "documento" + to_string(i) + ".txt";
            string ruta = direccion2 + "/" + archivo;
            ofstream salida(ruta);

            if (salida.is_open()) {
                salida <<endl<<i;
                salida.close();
                cout << "Se creo el archivo " << archivo << endl;
                ShellExecute(NULL, "open", ruta.c_str(), NULL, NULL, SW_SHOWNORMAL);
            } else {
                cout << "No se pudo crear el archivo " << archivo << endl;
            }

        }

    } else {

        for (int i = 1; i <= n; i++) {
            string archivo = "documento" + to_string(i) + ".txt";
            string ruta = direccion1 + "/" + archivo;
            ofstream salida(ruta);

            if (salida.is_open()) {
                salida << endl<<i;
                salida.close();
                cout << "Se creo el archivo " << archivo << endl;
                ShellExecute(NULL, "open", ruta.c_str(), NULL, NULL, SW_SHOWNORMAL);
            } else {
                cout << "No se pudo crear el archivo " << archivo << endl;
            }

        }

    }

    //INTENTO DE REALIZAR LA FUNCION DE BUSCAR EL ARCHIVO MAS PEQUEÑO
/*
    string buscarArchivoMasPequeno(int n) {
        // Variable para almacenar el nombre del archivo más pequeño
        string nombreArchivo = "";
        // Variable para almacenar el tamaño del archivo más pequeño
        uintmax_t tamanoArchivo = UINTMAX_MAX;
        // Variable para almacenar la ruta de la carpeta a buscar
        string carpeta = "";
        // Si n es par, usar la carpeta "Par"
        if (n % 2 == 0) {
            carpeta = "C:/Users/HUAWEI/Documents/Par";
        }
            // Si n es impar, usar la carpeta "Impar"
        else {
            carpeta = "C:/Users/HUAWEI/Desktop/Impar";
        }
        // Crear un objeto de la clase recursive_directory_iterator para iterar sobre los archivos de la carpeta y sus subcarpetas
        filesystem::recursive_directory_iterator iterador(carpeta);
        // Recorrer los archivos de la carpeta y sus subcarpetas
        for (const auto& entrada : iterador) {
            // Obtener la ruta del archivo como una cadena
            string ruta = entrada.path().string();
            // Si el archivo es un archivo regular (no una carpeta ni un enlace simbólico)
            if (filesystem::is_regular_file(ruta)) {
                // Obtener el tamaño del archivo en bytes
                uintmax_t tamano = filesystem::file_size(ruta);
                // Si el tamaño es menor que el tamaño del archivo más pequeño encontrado hasta ahora
                if (tamano < tamanoArchivo) {
                    // Actualizar el nombre y el tamaño del archivo más pequeño
                    nombreArchivo = entrada.path().filename().string();
                    tamanoArchivo = tamano;
                }
            }
        }
        // Devolver el nombre del archivo más pequeño o una cadena vacía si no se encontró ninguno
        return nombreArchivo;
    }
    */
}
