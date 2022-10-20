/**********************************************************************************
// DimensionFighter (Código Fonte)
// 
// Criação:     05 Out 2011
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "DimensionFighter.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros estáticos da classe
Game*   DimensionFighter::level = nullptr;
PlayerInterface* DimensionFighter::player = nullptr;
PlayerInterface* DimensionFighter::player2 = nullptr;
Audio*  DimensionFighter::audio = nullptr;
bool    DimensionFighter::viewBBox = false;

// ------------------------------------------------------------------------------

void DimensionFighter::Init() 
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(MENU, "Resources/Menu.wav");
    audio->Add(MUSIC, "Resources/Music.wav");
    audio->Add(TRANSITION, "Resources/Transition.wav");

    // bounding box não visú“el
    viewBBox = false;

    // cria jogador
    player = new Naruto();
    // cria jogador
    player2 = new Alex();

    // inicializa nú“el de abertura do jogo
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void DimensionFighter::Update()
{
    // habilita/desabilita visualização da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;    

    // atualiza nú“el
    level->Update();
} 

// ------------------------------------------------------------------------------

void DimensionFighter::Draw()
{
    // desenha nú“el
    level->Draw();
} 

// ------------------------------------------------------------------------------

void DimensionFighter::Finalize()
{
    level->Finalize();

    delete player;
    delete player2;
    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1100, 600);
    engine->window->Color(30, 50, 80);
    engine->window->Title("Dimension Fighter");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new DimensionFighter());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

