/**********************************************************************************
// Home (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_HOME_H_
#define _DIMENSIONFIGHTER_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Audio.h"
#include "Platform.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite * backg = nullptr;         // pano de fundo
    Platform* platform_1 = nullptr;
    //TileSet * tileset = nullptr;    // tileset da anima��o
    //Animation * anim = nullptr;     // anima��o do menu

public:
    static Audio* audio;
    static Scene* scene;           // cena do n��el

    void Init();                    // inicia n��el
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n��el
};

// -----------------------------------------------------------------------------

#endif