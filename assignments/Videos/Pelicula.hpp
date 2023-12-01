#ifndef PELICULA_H
#define PELICULA_H
#pragma once
#include "Video.hpp"

class Pelicula:public Video{
    private:
        std::string director, estudio;
    public:
        Pelicula(std::string, std::string, std::string, int, int, int, std::string, std::string);
        void reproducir() const override;
        std::string getDirector() const;
        void setDirector(const std::string&);
        std::string getEstudio() const;
        void setEstudio(const std::string&);
        friend std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula);
        void muestraDatos() const;
};
#endif