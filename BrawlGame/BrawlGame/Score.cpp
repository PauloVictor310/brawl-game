/**********************************************************************************
// Score (Código Fonte)
//
// Criação:     18 Set 2022
//
// Compilador:  Visual C++ 2019
//
// Descrição:   Bullets do Etther
//
**********************************************************************************/

#include "DimensionFighter.h"
#include "Scene.h"
#include "Level1.h"
#include "Score.h"

// ---------------------------------------------------------------------------------
Score::Score(int l, bool p)
{
    life = l;
    p1 = p;
}

// ---------------------------------------------------------------------------------

Score::~Score()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Score::Update() {
    // músil se move apenas no eixo y
}

void Score::OnCollision(Object* obj)
{

}

void Score::Draw() {
     
    //DimensionFighter::bit->Draw(x, y, std::to_string(life), p1 ? red : blue, Layer::FRONT, 0.6f);
}