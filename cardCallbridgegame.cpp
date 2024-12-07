#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Card suits and ranks
const string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

// Struct to represent a card
struct Card {
    string suit;
    string rank;

    // Display card as "Rank of Suit"
    string toString() {
        return rank + " of " + suit;
    }

    // Traditional comparison method
    bool isEqual(string cardSuit, string cardRank) {
        if (suit == cardSuit && rank == cardRank) {
            return true;
        }
        return false;
    }
};

// Create a deck of 52 cards
vector<Card> createDeck() {
    vector<Card> deck;
    for (int i = 0; i < 4; i++) {  // Loop through suits
        for (int j = 0; j < 13; j++) {  // Loop through ranks
            Card card;
            card.suit = suits[i];
            card.rank = ranks[j];
            deck.push_back(card);
        }
    }
    return deck;
}

// Shuffle the deck using the Fisher-Yates algorithm
void shuffleDeck(vector<Card>& deck) {
    srand(time(0)); // Seed for randomness
    for (int i = deck.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Random index between 0 and i
        // Swap cards deck[i] and deck[j]
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal cards to 4 players
vector<vector<Card>> dealCards(vector<Card>& deck) {
    vector<vector<Card>> hands(4, vector<Card>());
    for (int i = 0; i < deck.size(); i++) {
        hands[i % 4].push_back(deck[i]);
    }
    return hands;
}

// Generate a random trivia question
bool askQuestion() {
    vector<pair<string, string>> questions = {
        {"What is 12 * 7?", "84"},
        {"What is the square root of 144?", "12"},
        {"What is 15% of 200?", "30"},
        {"Solve: (25 + 5) * 2 - 10", "50"},
        {"How many suits are in a deck of cards?", "4"},
        {"What is 2^6?", "64"},
        {"What is the capital of France?", "Paris"},
        {"What is the atomic number of Hydrogen?", "1"}
    };

    int questionIndex = rand() % questions.size();
    cout << "\nQuestion: " << questions[questionIndex].first << "\nYour Answer: ";
    string answer;
    cin >> answer;

    if (answer == questions[questionIndex].second) {
        cout << "Correct!\n";
        return true;
    } else {
        cout << "Incorrect! The correct answer is " << questions[questionIndex].second << ".\n";
        return false;
    }
}

// Find rank index in the `ranks` array
int getRankIndex(const string& rank) {
    for (int i = 0; i < 13; i++) {
        if (ranks[i] == rank) {
            return i;
        }
    }
    return -1; // Return -1 if rank is not found
}

// Play the game
void callBridgeWithQuestions() {
    srand(time(0));

    // Create, shuffle, and deal the deck
    vector<Card> deck = createDeck();
    shuffleDeck(deck);
    vector<vector<Card>> hands = dealCards(deck);

    // Player's hand
    vector<Card>& playerHand = hands[0];
    string trumpSuit = suits[rand() % 4]; // Random trump suit
    int stamina = 10;

    // Display player's hand and trump suit
    cout << "Your hand:\n";
    for (int i = 0; i < playerHand.size(); i++) {
        cout << playerHand[i].toString() << "\n";
    }
    cout << "\nTrump suit: " << trumpSuit << "\n";

    // Simulate 13 tricks
    int playerTricks = 0;
    for (int trickNum = 1; trickNum <= 13; trickNum++) {
        if (stamina <= 0) {
            cout << "\nYou ran out of stamina. Game Over.\n";
            return;
        }

        cout << "\n--- Trick " << trickNum << " ---";
        cout << "\nStamina: " << stamina;

        // Ask a question
        bool answeredCorrectly = askQuestion();

        // Player's card for this trick
        Card playerCard;
        if (answeredCorrectly) {
            // Player selects a card
            int cardIndex;
            cout << "\nSelect a card to play (0 to " << playerHand.size() - 1 << "): ";
            cin >> cardIndex;
            playerCard = playerHand[cardIndex];
            // Remove the selected card by shifting elements
            for (int i = cardIndex; i < playerHand.size() - 1; i++) {
                playerHand[i] = playerHand[i + 1];
            }
            playerHand.pop_back();
        } else {
            // Random card is selected as penalty
            int randomIndex = rand() % playerHand.size();
            playerCard = playerHand[randomIndex];
            // Remove the random card by shifting elements
            for (int i = randomIndex; i < playerHand.size() - 1; i++) {
                playerHand[i] = playerHand[i + 1];
            }
            playerHand.pop_back();
            stamina -= 1; // Lose stamina for incorrect answer
        }
        cout << "\nYou played: " << playerCard.toString() << "\n";

        // Simulate opponents' plays
        vector<Card> trick(4);
        trick[0] = playerCard; // Player's card
        for (int i = 1; i < 4; i++) {
            int randomIndex = rand() % hands[i].size();
            Card opponentCard = hands[i][randomIndex];
            // Remove the opponent's card by shifting elements
            for (int j = randomIndex; j < hands[i].size() - 1; j++) {
                hands[i][j] = hands[i][j + 1];
            }
            hands[i].pop_back();
            trick[i] = opponentCard;
            cout << "Player " << i + 1 << " played: " << opponentCard.toString() << "\n";
        }

        // Determine winner
        string leadSuit = trick[0].suit;
        int winner = 0;
        for (int i = 1; i < 4; i++) {
            int leadRank = getRankIndex(trick[winner].rank);
            int currentRank = getRankIndex(trick[i].rank);

            if (trick[i].suit == trumpSuit || (trick[i].suit == leadSuit && currentRank > leadRank)) {
                winner = i;
            }
        }
        cout << "Player " << winner + 1 << " won the trick.\n";

        if (winner == 0) {
            playerTricks++;
        }
    }

    // Display results
    cout << "\nYou won " << playerTricks << " tricks.\n";
    if (playerTricks >= 7) {
        cout << "Congratulations! You performed well!\n";
    } else {
        cout << "Better luck next time!\n";
    }
}

int main() {
    callBridgeWithQuestions();
    return 0;
}
