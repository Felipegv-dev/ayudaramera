#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>  // Añadir para la sobrecarga de operadores

class Video {
private:
    std::string tipoVideo, nombreVideo, genero;
    int calificacion, anioLanzamiento, duracion, totalCalificaciones;

public:
    Video(std::string, std::string, std::string, int, int, int);
    Video(std::string, std::string, std::string, int, int);
    virtual ~Video() = default;
  
    virtual void reproducir() const = 0;

    void calificaVideo(int nuevaCalificacion);
    void muestraDatos() const;

    std::string getTipoVideo() const;
    std::string getNombreVideo() const;
    std::string getGenero() const;
    double getCalificacion() const;

    bool operator==(const Video& otro) const;
    friend std::ostream& operator<<(std::ostream& os, const Video& video);
};

#endif