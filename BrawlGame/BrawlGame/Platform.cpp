/**********************************************************************************
// Platform (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"
#include "DimensionFighter.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float x1, float x2, float y1, float y2)
{
    // bbox das plataformas
    BBox(new Rect(x1, x2, y1, y2));
    type = PLATFORM;
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{

}

// -------------------------------------------------------------------------------

void Platform::Update()
{

}

void Platform::Draw()
{

}

void Platform::OnCollision(Object* obj)
{

}

// -------------------------------------------------------------------------------
