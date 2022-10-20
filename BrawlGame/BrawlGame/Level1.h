/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nú“el 1 do jogo
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_LEVEL1_H_
#define _DIMENSIONFIGHTER_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "Naruto.h"
#include "Background.h"
#include "Platform.h"
#include "Audio.h"
#include "PlayerInterface.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite* backg = nullptr;   // pano de fundo animado

    Platform* platform_1 = nullptr;
    Platform* platform_2 = nullptr;
    Platform* platform_3 = nullptr;
    Platform* platform_4 = nullptr;
    Platform* platform_5 = nullptr;
    Platform* platform_6 = nullptr;

    PlayerInterface* player1 = nullptr;
    PlayerInterface* player2 = nullptr;

public:
    static Scene* scene;           // cena do nú“el
    static Audio* audio;

    int life1;
    int life2;

    void Init();                    // inicialização do nú“el
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nú“el
};

// -----------------------------------------------------------------------------

#endif