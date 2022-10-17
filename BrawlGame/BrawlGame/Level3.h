/**********************************************************************************
// Level3 (Arquivo de Cabeçalho)
//
// Criação:     16 Out 2022
// Atualização: 16 Out 2022
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 3 do jogo
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_LEVEL3_H_
#define _DIMENSIONFIGHTER_LEVEL3_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"

// ------------------------------------------------------------------------------

class Level3 : public Game
{
private:
    Sprite* backg = nullptr;        // background

public:
    static Scene* scene;            // cena do nível

    void Init();                    // inicialização do nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nível
};

// -----------------------------------------------------------------------------

#endif