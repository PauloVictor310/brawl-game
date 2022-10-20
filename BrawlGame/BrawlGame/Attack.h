/**********************************************************************************
// Attack (Arquivo de Cabe�alho)
//
// Cria��o:     18 Set 2022
//
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bullets do Etther
//
**********************************************************************************/

#ifndef _DF_Attack_H_
#define _DF_Attack_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                        // tipos espec��icos da engine
#include "Object.h"      
#include "Scene.h"
#include "Sprite.h"

// ---------------------------------------------------------------------------------

class Attack : public Object
{
private:
    Sprite* sprite = nullptr;

public:

    Attack(float x, float y, int dmg);                // construtor
    ~Attack();                               // destrutor

    float velX; // velocidade no eixo X
    float velY; // velocidade no eixo Y]
    int damage; // velocidade no eixo Y]

    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
    void OnCollision(Object* obj);               // desenho
};

inline void Attack::Draw()
{
    
}
// ---------------------------------------------------------------------------------

#endif