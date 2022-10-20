/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_NATSU_H_
#define _DIMENSIONFIGHTER_NATSU_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec��icos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
#include "PlayerInterface.h"

// ------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------

class Natsus : public PlayerInterface
{
public:
    Natsus();                           // construtor
    ~Natsus();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // �ltimo n��el finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

// ---------------------------------------------------------------------------------

#endif