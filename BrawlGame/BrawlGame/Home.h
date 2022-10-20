/**********************************************************************************
// Home (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_HOME_H_
#define _DIMENSIONFIGHTER_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

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
    //TileSet * tileset = nullptr;    // tileset da animação
    //Animation * anim = nullptr;     // animação do menu

public:
    static Audio* audio;
    static Scene* scene;           // cena do nú“el

    void Init();                    // inicia nú“el
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza nú“el
};

// -----------------------------------------------------------------------------

#endif