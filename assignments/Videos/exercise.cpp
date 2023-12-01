#include "Pelicula.hpp"
#include "Video.hpp"
#include "Serie.hpp"
#include "Funciones.hpp"
#include <iostream>
#include <fstream>
#include <limits>

void limpiarBufferEntrada() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Video** catalogo = nullptr;
    int size = 10; // cantidad de videos igual al numero de lineas o mas grande

    cargarCatalogo(catalogo, size);

    if (!catalogo) {
        return 1;
    }
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        limpiarBufferEntrada();

        switch (opcion) {
            case 1: {
                std::string genero;
                std::cout << "Ingrese el género: ";
                std::cin >> genero;
                mostrarVideosPorGenero(catalogo, size, genero);
                break;
            }
            case 2: {
                int maxCapitulos;
                std::cout << "Ingrese la cantidad máxima de capítulos: ";
                std::cin >> maxCapitulos;
                mostrarSeriesMenosCapitulos(catalogo, size, maxCapitulos);
                break;
            }
            case 3: {
                double minCalificacion;
                std::cout << "Ingrese la calificación mínima: ";
                std::cin >> minCalificacion;
                mostrarPeliculasPorCalificacion(catalogo, size, minCalificacion);
                break;
            }
            case 4:
                calificarVideo(catalogo, size);
                break;
            case 5:
                mostrarCatalogo(catalogo, size);
                break;
            case 6:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cerr << "Opción no válida.\n";
        }
    } while (opcion != 6);

    for (int i = 0; i < size; ++i) {
        delete catalogo[i];
    }
    delete[] catalogo;

    return 0;
}

