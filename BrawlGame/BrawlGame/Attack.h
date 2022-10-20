/**********************************************************************************
// Attack (Arquivo de Cabeçalho)
//
// Criação:     18 Set 2022
//
// Compilador:  Visual C++ 2019
//
// Descrição:   Bullets do Etther
//
**********************************************************************************/

#ifndef _DF_Attack_H_
#define _DF_Attack_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                        // tipos especúŸicos da engine
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

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    void OnCollision(Object* obj);               // desenho
};

inline void Attack::Draw()
{
    
}
// ---------------------------------------------------------------------------------

#endif