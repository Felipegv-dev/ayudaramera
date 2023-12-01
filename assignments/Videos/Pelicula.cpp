#include "Pelicula.hpp"
#include<iostream>

Pelicula::Pelicula(std::string _tipoVideo, std::string _nombreVideo, std::string _genero, int _calificacion, int _anioLanzamiento, int _duracion, std::string _director, std::string _estudio)
    : Video(_tipoVideo, _nombreVideo, _genero, _calificacion, _anioLanzamiento, _duracion), director(_director), estudio(_estudio) {}
void Pelicula::reproducir() const {
    std::cout << "Reproduciendo pelicula: " << getNombreVideo() << std::endl;
}
std::string Pelicula::getDirector() const {
    return director;
}

void Pelicula::setDirector(const std::string& _director) {
    director = _director;
}

std::string Pelicula::getEstudio() const {
    return estudio;
}

void Pelicula::setEstudio(const std::string& _estudio) {
    estudio = _estudio;
}

std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula) {
    os << static_cast<const Video&>(pelicula); // Imprime la parte de Video
    os << "- Director: \t\t" << pelicula.director << std::endl;
    os << "- Estudio: \t\t" << pelicula.estudio << std::endl;
    return os;
}
void Pelicula::muestraDatos() const {
    Video::muestraDatos(); 
    std::cout << "- Director: \t\t" << director << std::endl;
    std::cout << "- Estudio: \t\t" << estudio << std::endl;
}