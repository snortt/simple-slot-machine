#include "slot.hpp"
#include "game.hpp"
#include <iostream>

Game::Game() 
: money(1000) {}

Game::Game(int _m)
: money(_m) {}

int Game::newGame(void) {

    SlotMachine s;
    int grana;
    int aposta;
    int resultado;
    
    std::cout << "Caça níqueis \"Tudo ou nada!\"" << std::endl;
    std::cout << "3 números iguais a 7: ganha 10x aposta" << std::endl;
    std::cout << "3 números iguais: ganha 5x aposta" << std::endl;
    std::cout << "2 números iguais: ganha 3x aposta" << std::endl;
    std::cout << "Demais casos: perde a aposta" << std::endl;
    std::cout << "Iniciando novo jogo. Para sair, digite \"0\"" << std::endl;

    while (true) {
        // Limpar a tela
        //std::cout << "\x1B[2J\x1B[H";

        // Abrir a sua carteira ;)
        std::cout << "--------------" << std::endl;
        std::cout << "Sua carteira: ";
        grana = this->getMoney();
        std::cout << grana << std::endl;

        // Testar se a grana dá pra jogar...
        if ( grana <= 0 ) {
            std::cout << "Infelizmente você está duro! Não dá para jogar! :-(" << std::endl;
            return -1;
        }
        else { 
            std::cout << "Quanto você quer apostar?" << std::endl;
            std::cin >> aposta;
            // Veja se o cara é 171
            if ( aposta > grana || aposta < 0 ) {
                std::cout << "Você não tem essa grana!" << std::endl;
            }
            else if ( aposta == 0 ) {
                std::cout << "Obrigado por jogar!" << std::endl;
                return -2;
            }
            else { 
                resultado = s.MakeBet(aposta);
                if ( resultado == 0 ) {
                    std::cout << "Mais sorte na próxima vez." << std::endl;
                    this->setMoney(grana - aposta);
                }
                else {
                    std::cout << "Parabéns! =)" << std::endl;
                    this->setMoney(grana + resultado);
                }
            }   
        }
    }    
        
    return 0;
}

int Game::getMoney(void) const { return money; }
void Game::setMoney(int _m) { money = _m; }


