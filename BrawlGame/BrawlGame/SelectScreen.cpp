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
#include "Scene.h"

// ------------------------------------------------------------------------------

Scene* SelectScreen::scene = nullptr;

void SelectScreen::Init()
{
    scene = new Scene();
    backg = new Sprite("Resources/choose/choose.png");

    platform_1 = new Platform(-550, -23, 549, 23);
    platform_1->MoveTo(window->CenterX(), 565);
    scene->Add(platform_1, STATIC);
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
    if (DimensionFighter::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void SelectScreen::Finalize()
{
    delete backg;
    delete scene;
    delete Home::audio;
}

// ------------------------------------------------------------------------------