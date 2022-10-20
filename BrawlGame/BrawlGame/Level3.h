/**********************************************************************************
// Level3 (Arquivo de Cabe�alho)
//
// Cria��o:     16 Out 2022
// Atualiza��o: 16 Out 2022
// Compilador:  Visual C++ 2019
//
// Descri��o:   N��el 3 do jogo
//
**********************************************************************************/

#ifndef _DIMENSIONFIGHTER_LEVEL3_H_
#define _DIMENSIONFIGHTER_LEVEL3_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Naruto.h"
#include "Background.h"
#include "Audio.h"

// ------------------------------------------------------------------------------

class Level3 : public Game
{
private:
    Sprite* backg = nullptr;        // background

public:
    static Scene* scene;            // cena do n��el
    static Audio* audio;

    void Init();                    // inicializa��o do n��el
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n��el
};

// -----------------------------------------------------------------------------

#endif