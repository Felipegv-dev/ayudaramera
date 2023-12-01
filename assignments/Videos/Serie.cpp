#include "Serie.hpp"
#include <iostream>

Serie::Serie(std::string _tipoVideo, std::string _nombreVideo, std::string _genero, int _anioLanzamiento, int _duracion, int _numTemporadas, std::string _productor, int _numEpisodios)
: Video(_tipoVideo, _nombreVideo, _genero, 0, _anioLanzamiento, _duracion), numTemporadas(_numTemporadas), productor(_productor), numEpisodios(_numEpisodios) {}
void Serie::reproducir() const {
    std::cout << "Reproduciendo serie: " << getNombreVideo() << std::endl;
}
int Serie::getNumTemporadas() const {
    return numTemporadas;
}

void Serie::setNumTemporadas(int _numTemporadas) {
    numTemporadas = _numTemporadas;
}

std::string Serie::getProductor() const {
    return productor;
}

void Serie::setProductor(const std::string& _productor) {
    productor = _productor;
}

int Serie::getNumEpisodios() const {
    return numEpisodios;
}

void Serie::setNumEpisodios(int _numEpisodios) {
    numEpisodios = _numEpisodios;
}

std::ostream& operator<<(std::ostream& os, const Serie& serie) {
    os << static_cast<const Video&>(serie); // Imprime la parte de Video
    os << "- Número de Temporadas: \t" << serie.numTemporadas << std::endl;
    os << "- Productor: \t\t\t" << serie.productor << std::endl;
    os << "- Número de Episodios: \t\t" << serie.numEpisodios << std::endl;
    return os;
}
void Serie::muestraDatos() const {
    Video::muestraDatos(); // Llama a la implementación de la clase base
    std::cout << "- Número de Temporadas: \t" << numTemporadas << std::endl;
    std::cout << "- Productor: \t\t\t" << productor << std::endl;
    std::cout << "- Número de Episodios: \t\t" << numEpisodios << std::endl;
}