
/**********************************************************************************
// PlayerInterface (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_PLAYERINT_H_
#define _DIMENSIONFIGHTER_PLAYERINT_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec��icos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------

class PlayerInterface : public Object
{
protected:
    TileSet*    tileset;                // folha de sprites do personagem
    Animation*  anim;                   // anima��o do personagem
    uint        gravity;                // gravidade atuando sobre o jogador
    int         level;                  // n��el finalizado
    int         life;
    float       speed;                  // velocidade do personagem

public:
    uint state;                         // estado atual do personagem

    PlayerInterface();                           // construtor
    ~PlayerInterface();                          // destrutor

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

inline int PlayerInterface::Level()
{
    return level;
}

inline float PlayerInterface::Bottom()
{
    return y + tileset->Height() / 2;
}

inline float PlayerInterface::Top()
{
    return y - tileset->Height() / 2;
}

inline void PlayerInterface::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif