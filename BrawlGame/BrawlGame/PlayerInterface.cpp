/**********************************************************************************
// PlayerInterface (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "PlayerInterface.h"
#include "DimensionFighter.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

PlayerInterface::PlayerInterface()
{
    tileset = nullptr;                // folha de sprites do personagem
    anim = nullptr;                   // animação do personagem
    gravity = NORMAL;
    level = 0;
    state = STILL;
    speed = 300.0f;
    life = 100;
}

// ---------------------------------------------------------------------------------

PlayerInterface::~PlayerInterface()
{
}

// ---------------------------------------------------------------------------------

void PlayerInterface::Reset()
{
}


// ---------------------------------------------------------------------------------

void PlayerInterface::OnCollision(Object* obj)
{
}

// ---------------------------------------------------------------------------------

void PlayerInterface::Update()
{
}

// ---------------------------------------------------------------------------------