// Dynamic array Inversion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* array;          // Puntero para almacenar el array en memoria dinámica
    int currentSize;     // Número de elementos actualmente almacenados en el array
    int capacity;        // Capacidad máxima del array

public:
    // Constructor: Inicializa el array con una capacidad dada
    DynamicArray(int initialCapacity) {
        capacity = initialCapacity; // Establecemos la capacidad inicial
        currentSize = 0;            // Comenzamos con tamaño actual en 0
        array = new int[capacity];  // Reservamos memoria dinámica para el array
    }

    // Destructor: Libera la memoria dinámica reservada
    ~DynamicArray() {
        delete[] array; // Liberamos la memoria del array
    }

    // Función para añadir un elemento al array
    void add(int value) {
        if (currentSize < capacity) {
            array[currentSize++] = value; // Añadimos el valor y aumentamos el tamaño actual
        }
        else {
            cout << "El array está lleno, no se pueden añadir más elementos." << endl;
        }
    }

    // Función para invertir el orden de los elementos del array
    void invert() {
        for (int i = 0; i < currentSize / 2; i++) {
            // Intercambiamos los elementos en las posiciones i y (currentSize - 1 - i)
            int temp = array[i];
            array[i] = array[currentSize - 1 - i];
            array[currentSize - 1 - i] = temp;
        }
    }

    // Función para imprimir los elementos del array
    void print() const {
        cout << "[ ";
        for (int i = 0; i < currentSize; i++) {
            cout << array[i] << " "; // Mostramos cada elemento del array
        }
        cout << "]" << endl;
    }
};

int main() {
    // Creamos una instancia de DynamicArray con capacidad de 10
    DynamicArray myArray(10);

    // Añadimos elementos al array
    for (int i = 1; i <= 5; i++) {
        myArray.add(i); // Añadimos los números del 1 al 5
    }

    // Imprimimos el array antes de invertirlo
    cout << "Array antes de invertir: ";
    myArray.print();

    // Invertimos el array
    myArray.invert();

    // Imprimimos el array después de invertirlo
    cout << "Array despues de invertir: ";
    myArray.print();

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
