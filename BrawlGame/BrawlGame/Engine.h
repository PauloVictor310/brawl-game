/**********************************************************************************
// Engine (Arquivo de CabeÁalho)
//
// CriaÁ„o:     15 Mai 2014
// AtualizaÁ„o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// DescriÁ„o:   A funÁ„o da Engine ÅErodar jogos criados a partir da classe 
//              abstrata Game. Todo jogo deve ser uma classe derivada de Game 
//              e portanto deve implementar as funÁıes membro Init, Update, Draw 
//              e Finalize, que ser„o chamadas pelo motor em um laÁo de tempo real. 
//              Para usar a classe Engine, o programador deve criar uma inst‚ncia 
//              e chamar o mÈtodo Start(), passando um objeto derivado de Game.
//
**********************************************************************************/

#ifndef _PROGJOGOS_ENGINE_H_
#define _PROGJOGOS_ENGINE_H_

// ---------------------------------------------------------------------------------

#include "Game.h"                        // implementaÁ„o do jogo
#include "Window.h"                      // janela do jogo
#include "Graphics.h"                    // hardware gr·fico
#include "Renderer.h"                    // renderizador de sprites
#include "Timer.h"                       // medidor de tempo

// ---------------------------------------------------------------------------------

class Engine
{
private:
    static Timer timer;                  // medidor de tempo
    static bool paused;                  // estado do jogo

    float FrameTime();                   // calcula o tempo do quadro
    int   Loop();                        // inicia execuÁ„o do jogo

public:
    static Game     * game;              // jogo a ser executado
    static Window   * window;            // janela do jogo
    static Graphics * graphics;          // dispositivo gr·fico
    static Renderer * renderer;          // renderizador de sprites
    static float      frameTime;         // tempo do quadro atual

    Engine();                            // construtor
    ~Engine();                           // destrutor

    int Start(Game* level);              // inicia a execuÁ„o do jogo
    
    static void Pause();                 // pausa o jogo
    static void Resume();                // reinicia o jogo

    template<class T>
    static void Next()                   // muda para prÛximo n˙ìel do jogo
    {
        if (game)
        {
            game->Finalize();
            delete game;
            game = new T();
            game->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif