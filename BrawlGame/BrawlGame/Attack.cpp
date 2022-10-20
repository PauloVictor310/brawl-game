/**********************************************************************************
// Attack (CÛdigo Fonte)
//
// CriaÁ„o:     18 Set 2022
//
// Compilador:  Visual C++ 2019
//
// DescriÁ„o:   Bullets do Etther
//
**********************************************************************************/

#include "DimensionFighter.h"
#include "Scene.h"
#include "Level1.h"
#include "Attack.h"

// ---------------------------------------------------------------------------------

Attack::Attack(float vx, float vy, int dmg)
{
    velX = vx;
    velY = vy;
    damage = dmg;

    BBox(new Point());
    type = ATTACK;
}

// ---------------------------------------------------------------------------------

Attack::~Attack()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Attack::Update() {
    // m˙êsil se move apenas no eixo y
    Translate(velX * gameTime, velY * gameTime);


}

void Attack::OnCollision(Object* obj)
{
    
}