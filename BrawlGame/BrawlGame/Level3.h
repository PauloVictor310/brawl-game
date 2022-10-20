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
#include "Platform.h"
#include "Audio.h"

// ------------------------------------------------------------------------------

class Level3 : public Game
{
private:
    Sprite* backg = nullptr;        // background

    Platform* platform_1 = nullptr;
    Platform* platform_2 = nullptr;
    Platform* platform_3 = nullptr;
    Platform* platform_4 = nullptr;
    Platform* platform_5 = nullptr;
    Platform* platform_6 = nullptr;
    Platform* platform_7 = nullptr;
    Platform* platform_8 = nullptr;
    Platform* platform_9 = nullptr;
    Platform* platform_10 = nullptr;

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