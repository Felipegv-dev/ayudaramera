#ifndef SERIE_H
#define SERIE_H
#pragma once
#include "Video.hpp"

class Serie:public Video{
    private:
        int numTemporadas, numEpisodios;
        std::string productor;

    public:
        Serie(std::string, std::string, std::string, int, int, int,std::string, int);
        void reproducir() const override;
        int getNumTemporadas() const;
        void setNumTemporadas(int);
        std::string getProductor() const;
        void setProductor(const std::string&);
        int getNumEpisodios() const;
        void setNumEpisodios(int);
        friend std::ostream& operator<<(std::ostream& os, const Serie& serie);
        void muestraDatos() const;
};
#endif