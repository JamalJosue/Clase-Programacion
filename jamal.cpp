#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Registro {
    char nombre[50];
    char apellido[50];
    
};

void insertar(vector<Registro> &registros) {
    Registro nuevo;
    cout << "\nIngrese Nombre: ";
    cin >> nuevo.nombre;
    cout << "\nIngrese Apellido: ";
    cin >> nuevo.apellido;
    registros.push_back(nuevo);
    cout << "\nRegistro agregado correctamente.\n" << endl;
}

void buscar(vector<Registro> registros) {
    string nombre,apellido;
    cout << "\nIngrese nombre a buscar: \n";
    cin >> nombre;
     cout << "\nIngrese apellido a buscar:\n ";
    cin >> nombre;
    for (char i = 0; i < registros.size(); i++) {
        if (registros[i].nombre == nombre,registros[i].apellido == apellido) {
            cout << "Nombre: " << registros[i].nombre << endl;
            cout << "Apellido: " << registros[i].apellido << endl;
            return;
        }
    }
    cout << "\nNo se encontró el registro buscado.\n" << endl;
}

void guardar(vector<Registro> registros) {
    ofstream archivo("registros.txt");
    for (char i = 0; i < registros.size(); i++) {
        archivo << registros[i].nombre << "," << registros[i].apellido << endl;
    }
    archivo.close();
    cout << "\nRegistros guardados correctamente.\n" << endl;
}

void borrar(vector<Registro> &registros) {
    string nombre, apellido;
    cout << "\nIngrese nombre a eliminar: ";
    cin >> nombre;
    cout << "\nIngrese apellido a eliminar: ";
    cin >> apellido;
    for (char i = 0; i < registros.size(); i++) {
        if (registros[i].nombre == nombre,registros[i].apellido == apellido) {
            registros.erase(registros.begin() + i);
            cout << "\nRegistro eliminado correctamente.\n" << endl;
            return;
        }
    }
    cout << "\nNo se encontro el registro buscado.\n" << endl;
}

int main() {
    vector<Registro> registros;
    int opcion = -1;
    while (opcion != 0) {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Agregar registro" << endl;
        cout << "2. Buscar registro" << endl;
        cout << "3. Guardar registros" << endl;
        cout << "4. Eliminar registro" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: \n";
        cin >> opcion;
        switch (opcion) {
            case 1:
                insertar(registros);
                break;
            case 2:
                buscar(registros);
                break;
            case 3:
                guardar(registros);
                break;
            case 4:
                borrar(registros);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
    return 0;
}
