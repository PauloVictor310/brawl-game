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

#ifndef _DIMENSIONFIGHTER_PLAYER2_H_
#define _DIMENSIONFIGHTER_PLAYER2_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec��icos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
#include "Player.h"

// ------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------

class Player2 : public Object
{
private:
    TileSet* tileset;                // folha de sprites do personagem
    Animation* anim;                   // anima��o do personagem
    uint        gravity;                // gravidade atuando sobre o jogador
    int         level;                  // n��el finalizado
    float       speed;                  // velocidade do personagem

public:
    uint state;                         // estado atual do personagem

    Player2();                           // construtor
    ~Player2();                          // destrutor

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