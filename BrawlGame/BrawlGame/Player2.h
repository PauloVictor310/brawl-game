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

#ifndef _DIMENSIONFIGHTER_PLAYER2_H_
#define _DIMENSIONFIGHTER_PLAYER2_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos especúƒicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Player.h"

// ------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------

class Player2 : public Object
{
private:
    TileSet* tileset;                // folha de sprites do personagem
    Animation* anim;                   // animação do personagem
    uint        gravity;                // gravidade atuando sobre o jogador
    int         level;                  // nú“el finalizado
    float       speed;                  // velocidade do personagem

public:
    uint state;                         // estado atual do personagem

    Player2();                           // construtor
    ~Player2();                          // destrutor

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

inline int Player2::Level()
{
    return level;
}

inline float Player2::Bottom()
{
    return y + tileset->Height() / 2;
}

inline float Player2::Top()
{
    return y - tileset->Height() / 2;
}

inline void Player2::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif