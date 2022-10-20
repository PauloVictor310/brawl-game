/**********************************************************************************
// Select Screen (Código Fonte)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de seleção de personagens do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "DimensionFighter.h"
#include "Home.h"
#include "SelectScreen.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void SelectScreen::Init()
{
    backg = new Sprite("Resources/TitleScreen.png");
}

// ------------------------------------------------------------------------------

void SelectScreen::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    // se a tecla ENTER for pressionada
    if (window->KeyPress(VK_RETURN))
    {
        DimensionFighter::audio->Stop(MENU);
        DimensionFighter::NextLevel<Level1>();
    }
    else
    {
        //anim->NextFrame();
    }
}

// ------------------------------------------------------------------------------

void SelectScreen::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------

void SelectScreen::Finalize()
{
    delete backg;
    delete Home::audio;
}

// ------------------------------------------------------------------------------