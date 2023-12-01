#include "Video.hpp"
#include <string>
#include <iostream>

Video::Video(std::string _tipoVideo, std::string _nombrevideo, std::string _genero, int _calificacion, int _anioLanzamiento, int _duracion)
    : tipoVideo(_tipoVideo), nombreVideo(_nombrevideo), genero(_genero), calificacion(_calificacion), anioLanzamiento(_anioLanzamiento), duracion(_duracion), totalCalificaciones(1) {}
Video::Video(std::string _tipoVideo, std::string _nombrevideo, std::string _genero, int _anioLanzamiento, int _duracion)
    : tipoVideo(_tipoVideo), nombreVideo(_nombrevideo), genero(_genero), calificacion(0), anioLanzamiento(_anioLanzamiento), duracion(_duracion){}
void Video::calificaVideo(int nuevaCalificacion) {
    if (nuevaCalificacion < 0 || nuevaCalificacion > 10) {
        throw std::invalid_argument("La calificación debe estar en el rango de 0 a 10.");
    }
    double sumaCalificaciones = calificacion * totalCalificaciones;
    sumaCalificaciones += nuevaCalificacion;
    totalCalificaciones++;
    calificacion = sumaCalificaciones / totalCalificaciones;
}
std::string Video::getGenero() const {
    return genero;
}
double Video::getCalificacion() const {
    return calificacion;
}
std::ostream& operator<<(std::ostream& os, const Video& video) {
    os << "\n- Tipo de Video: \t" << video.tipoVideo << std::endl;
    os << "- Nombre del Video: \t" << video.nombreVideo << std::endl;
    os << "- Género del video: \t" << video.genero << std::endl;
    os << "- Calificación: \t" << video.calificacion << "/10" << std::endl;
    os << "- Año de lanzamiento: \t" << video.anioLanzamiento << std::endl;
    os << "- Duracion: \t\t" << video.duracion << " minutos" << std::endl;
    return os;
}
void Video::muestraDatos() const {
    std::cout << "\n- Tipo de Video: \t" << tipoVideo << std::endl;
    std::cout << "- Nombre del Video: \t" << nombreVideo << std::endl;
    std::cout << "- Género del video: \t" << genero << std::endl;
    std::cout << "- Calificación: \t" << calificacion << "/10" << std::endl;
    std::cout << "- Año de lanzamiento: \t" << anioLanzamiento << std::endl;
    std::cout << "- Duracion: \t\t" << duracion << " minutos" << std::endl;
}

std::string Video::getTipoVideo() const {
    return tipoVideo;
}

std::string Video::getNombreVideo() const {
    return nombreVideo;
}