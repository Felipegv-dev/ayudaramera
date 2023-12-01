#include "Funciones.hpp"
#include "Video.hpp"
#include "Pelicula.hpp"
#include "Serie.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>  // Para formateo de salida

void mostrarMenu() {
    std::cout << "Menú de opciones:\n";
    std::cout << "1. Mostrar videos por género\n";
    std::cout << "2. Mostrar series con menos de X capítulos\n";
    std::cout << "3. Mostrar películas por calificación\n";
    std::cout << "4. Calificar video\n";
    std::cout << "5. Mostrar catálogo completo\n";
    std::cout << "6. Salir\n";
    std::cout << "Ingrese su opción: ";
}

void cargarCatalogo(Video**& catalogo, int& size) {
    std::ifstream archivo("catalogo.txt");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    catalogo = new Video*[size];

    //lee todas las lineas del archivo
    std::string linea;
    int i = 0;

    while (std::getline(archivo, linea)) {
        std::string tipoVideo, nombreVideo, genero;
        int calificacion, anioLanzamiento, duracion;

        std::stringstream ss(linea);
        ss >> tipoVideo;
        ss >> nombreVideo >> genero;

        if (tipoVideo == "Pelicula") {
            std::string director, estudio;
            ss >> calificacion >> anioLanzamiento >> duracion >> director >> estudio;
            catalogo[i] = new Pelicula(tipoVideo, nombreVideo, genero, calificacion, anioLanzamiento, duracion, director, estudio);
        } else if (tipoVideo == "Serie") {
            int durep, cantep;
            std::string productor;
            ss >> anioLanzamiento >> duracion >> durep >> productor >> cantep;
            catalogo[i] = new Serie(tipoVideo, nombreVideo, genero, anioLanzamiento, duracion, durep, productor, cantep);
        } else {
            std::cerr << "Error: Tipo de video no reconocido. Tipo: " << tipoVideo << std::endl;
            delete[] catalogo;
            catalogo = nullptr;
            size = 0;
            return;
        }
        i++;
    }


    /* for (int i = 0; i < size; ++i) {
        std::string tipoVideo, nombreVideo, genero;
        int calificacion, anioLanzamiento, duracion;
        
        archivo >> tipoVideo;
        archivo >> nombreVideo >> genero >> calificacion >> anioLanzamiento >> duracion;

        if (tipoVideo == "Pelicula") {
            std::string director, estudio;
            archivo >> director >> estudio;
            catalogo[i] = new Pelicula(tipoVideo, nombreVideo, genero, calificacion, anioLanzamiento, duracion, director, estudio);
        } else if (tipoVideo == "Serie") {
            int numTemporadas, numEpisodios;
            std::string productor;
            archivo >> numTemporadas >> productor >> numEpisodios;
            catalogo[i] = new Serie(tipoVideo, nombreVideo, genero, anioLanzamiento, duracion, numTemporadas, productor, numEpisodios);
        } else {
            std::cerr << "Error: Tipo de video no reconocido. Tipo: " << tipoVideo << std::endl;
            delete[] catalogo;
            catalogo = nullptr;
            size = 0;
            return;
        }
    }
 */
    archivo.close();
}

void mostrarVideosPorGenero(const Video* const catalogo[], int size, const std::string& genero) {
    std::cout << "\n--- Videos del género " << genero << " ---\n";
    for (int i = 0; i < size; ++i) {
        if (catalogo[i]->getGenero() == genero) {
            catalogo[i]->muestraDatos();
            std::cout << std::endl;
        }
    }
}

void mostrarSeriesMenosCapitulos(const Video* const catalogo[], int size, int maxCapitulos) {
    std::cout << "\n--- Series con menos de " << maxCapitulos << " capítulos ---\n";
    for (int i = 0; i < size; ++i) {
        const Serie* serie = dynamic_cast<const Serie*>(catalogo[i]);
        if (serie && serie->getNumEpisodios() < maxCapitulos) {
            catalogo[i]->muestraDatos();
            std::cout << std::endl;
        }
    }
}

void mostrarPeliculasPorCalificacion(const Video* const catalogo[], int size, double minCalificacion) {
    std::cout << "\n--- Películas con calificación mayor o igual a " << minCalificacion << " ---\n";
    for (int i = 0; i < size; ++i) {
        const Pelicula* pelicula = dynamic_cast<const Pelicula*>(catalogo[i]);
        if (pelicula && pelicula->getCalificacion() >= minCalificacion) {
            catalogo[i]->muestraDatos();
            std::cout << std::endl;
        }
    }
}

void calificarVideo(Video* const catalogo[], int size) {
    std::string titulo;
    std::cout << "Ingrese el título del video a calificar: ";
    std::cin >> titulo;

    for (int i = 0; i < size; ++i) {
        if (catalogo[i]->getNombreVideo() == titulo) {
            int nuevaCalificacion;
            std::cout << "Ingrese la nueva calificación (0-10): ";
            std::cin >> nuevaCalificacion;

            try {
                catalogo[i]->calificaVideo(nuevaCalificacion);
                std::cout << "Calificación actualizada con éxito.\n";
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

            return;
        }
    }

    std::cerr << "Video no encontrado.\n";
}

void mostrarCatalogo(const Video* const catalogo[], int size) {
    std::cout << "\n--- Catálogo completo ---\n";
    for (int i = 0; i < size; ++i) {
        catalogo[i]->muestraDatos();
        std::cout << std::endl;
    }
}
