/**********************************************************************************
// Level2 (Arquivo de Cabeçalho)
//
// Criação:     27 Set 2021
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 2 do jogo
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_LEVEL2_H_
#define _DIMENSIONFIGHTER_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"
#include "Platform.h"

// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
    Sprite* backg = nullptr;   // pano de fundo animado
    Platform* platform_1 = nullptr;
    Platform* platform_2 = nullptr;
    Platform* platform_3 = nullptr;
    Platform* platform_4 = nullptr;
    Platform* platform_5 = nullptr;
    Platform* platform_6 = nullptr;
    Platform* platform_7 = nullptr;
    Platform* platform_8 = nullptr;

public:
    static Scene* scene;           // cena do nível

    void Init();                    // inicialização do nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nível
};

// -----------------------------------------------------------------------------

#endif