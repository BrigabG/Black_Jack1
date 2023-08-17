#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int generateCard()              //Aca genero TODAS MIS CARTAS
{
    return rand() % 11 + 1;
} 

int calculateTotal(const vector<int>& hand)       //Calculo mis cartas evaluando las posibilidades de AS :D
{
    int total = 0;
    int numAces = 0;

    for (int card : hand)
    {
        if (card == 1)
        {
            numAces++;
            total += 11;
        }
        else if (card > 10)     //Estas son la figuras, (K,Q,J)
        {
            total += 10;
        }
        else
        {
            total += card;
        }
    }

    while (total > 21 && numAces > 0)  // Mi AS vale 1
    {
        total -= 10;
        numAces--;
    }

    return total;
}

int main()
{
    srand(time(0));             //mi pseudoramdomizador

    vector<int> player;         //Almaceno las cartas de Jugador
    vector<int> dealer;         //Almaceno las cartas del Estafador

    player.push_back(generateCard());
    player.push_back(generateCard());

    dealer.push_back(generateCard());

    cout << "Welcome to Blackjack!" << endl;

    while (true)      //Bucle hasta que; o pierda; o decida no querer mas cartas
    {
        cout << "Your cards: ";
        for (int card : player)
        {
            cout << card << " ";
        }
        cout << "Total: " << calculateTotal(player) << endl;  //Agrego la suma de tus cartas, hace mas ameno el juego

        cout << "Dealer's card: " << dealer[0] << endl;    //muestro la unica carta de dealer

        if (calculateTotal(player) == 21)                 //SUERTUDO JIJE
        {
            cout << "Blackjack! You win!" << endl;
            break;                                          //termino el bucle todo LO QUE ESCRIBI ABAJO POPO
        }

        if (calculateTotal(player) > 21)                  //:(
        {
            cout << "You went over 21. Dealer wins!" << endl;
            break;                                          //SAME SHIT
        }

        cout << "Do you want another card? (y/n): ";
        string choice;
        cin >> choice;

        if (choice == "y")
        {
            player.push_back(generateCard());
        }
        else
        {
            while (calculateTotal(dealer) < 17)            //El "estafador" por regla tiene que pedir cartas hasta tener 17 o mas
            {
                dealer.push_back(generateCard());
            }

            cout << "Dealer's hand: ";                      
            for (int card : dealer)
            {
                cout << card << " ";
            }
            cout << "Total: " << calculateTotal(dealer) << endl;

            if (calculateTotal(dealer) > 21 || calculateTotal(player) > calculateTotal(dealer))  //A continuacion simplemente comparamos las manos y en base a eso habras ganado o perdido
            {
                cout << "You win!" << endl;
            }
            else if (calculateTotal(player) == calculateTotal(dealer))
            {
                cout << "It's a tie." << endl;
            }
            else
            {
                cout << "Dealer wins." << endl;
            }

            break;
        }
    }
    cout << "Press Enter to exit..."; // Espera a que el usuario presione Enter para cerrar la consola
    cin.ignore(); // Ignora cualquier entrada pendiente 
    cin.get(); // Espera a que el usuario presione Enter
    
    return 0;
}
