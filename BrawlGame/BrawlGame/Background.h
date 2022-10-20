/**********************************************************************************
// Background (Arquivo de CabeÁalho)
// 
// CriaÁ„o:     21 Abr 2012
// AtualizaÁ„o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// DescriÁ„o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_BACKGROUND_H_
#define _DIMENSIONFIGHTER_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec˙Éicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background ÅEcomposto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float xF, xB;                       // posiÁ„o horizontal dos sprites
    Image * imgF;                       // imagem de fundo frontal
    Image * imgB;                       // imagem de fundo traseira    

    Sprite * sky;                       // fundo est·tico
    Sprite * backgF1;                   // pano de fundo din‚mico (frontal 1)
    Sprite * backgF2;                   // pano de fundo din‚mico (frontal 2)
    Sprite * backgB1;                   // pano de fundo din‚mico (traseiro 1)
    Sprite * backgB2;                   // pano de fundo din‚mico (traseiro 2)

    Color color;                        // cor do pano de fundo

public:
    Background(Color tint);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualizaÁ„o do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif