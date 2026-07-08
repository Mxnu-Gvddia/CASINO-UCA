#ifndef CASINO_H
#define CASINO_H

// Indice de juegos: cada uno esta en su propio archivo 
// El saldo se pasa por referencia y para que todos usen el mismo dinero.
void jugarTragamonedas(float& saldo);
void jugarRuleta(float& saldo);
void jugarBlackjack(float& saldo);

#endif
