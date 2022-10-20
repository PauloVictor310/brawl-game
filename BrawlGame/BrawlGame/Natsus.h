/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_NATSU_H_
#define _DIMENSIONFIGHTER_NATSU_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos especúƒicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "PlayerInterface.h"

// ------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------

class Natsus : public PlayerInterface
{
public:
    Natsus();                           // construtor
    ~Natsus();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nú“el finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

// ---------------------------------------------------------------------------------

#endif