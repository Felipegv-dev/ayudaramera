#include "Video.hpp"

void mostrarMenu();
void cargarCatalogo(Video**& catalogo, int& size);
void mostrarVideosPorGenero(const Video* const catalogo[], int size, const std::string& genero);
void mostrarSeriesMenosCapitulos(const Video* const catalogo[], int size, int maxCapitulos);
void mostrarPeliculasPorCalificacion(const Video* const catalogo[], int size, double minCalificacion);
void calificarVideo(Video* const catalogo[], int size);
void mostrarCatalogo(const Video* const catalogo[], int size);