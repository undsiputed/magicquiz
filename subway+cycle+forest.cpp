#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Achievement {
private:
    string name;
    bool achieved;

public:
    Achievement(string n) {
        name = n;
        achieved = false;
    }

    string getName() const {
        return name;
    }

    bool isAchieved() const {
        return achieved;
    }

    void setAchieved(bool status) {
        achieved = status;
    }
};

class Game {
private:
    int score;
    int energy;
    int money;
    vector<string> inventory;
    vector<Achievement> achievements;

    // Game-specific booleans
    bool hasOmnyCard;
    bool hasNavigated;

    // Forest-specific booleans
    bool escapedCave;
    bool survivedSnake;
    bool escapedBeehive;
    bool escapedBear;
    bool navigatedJungle;

public:
    Game() {
        score = 0;
        energy = 100;
        money = 20;

        inventory.push_back("Backpack");
        inventory.push_back("Christmas Gift List");

        achievements.push_back(Achievement("First_Card"));
        achievements.push_back(Achievement("Navigator_Pro"));
        achievements.push_back(Achievement("Escape_Artist"));
        achievements.push_back(Achievement("Helpful_Stranger"));
        achievements.push_back(Achievement("Torchbearer"));
        achievements.push_back(Achievement("Snake_Survivor"));
        achievements.push_back(Achievement("Bee_Escaper"));
        achievements.push_back(Achievement("Bear_Evader"));
        achievements.push_back(Achievement("Jungle_Navigator"));

        hasOmnyCard = false;
        hasNavigated = false;
        escapedCave = false;
        survivedSnake = false;
        escapedBeehive = false;
        escapedBear = false;
        navigatedJungle = false;
    }

    void displayStatus() {
        cout << "\n====== CURRENT GAME STATUS ======\n";
        cout << "Score: " << score << endl;
        cout << "Energy: " << energy << "%" << endl;
        cout << "Money: $" << money << endl;

        cout << "\nInventory:\n";
        for (size_t i = 0; i < inventory.size(); ++i) {
    cout << "- " << inventory[i] << endl;
}


        cout << "\nAchievements:\n";
       for (size_t i = 0; i < achievements.size(); ++i) {
    cout << (achievements[i].isAchieved() ? "🌟 " : "❄️ ") << achievements[i].getName() << endl;
}

        cout << "=================================\n\n";
    }

    void startAdventure() {
        cout << "\n🎄 === SUBWAY ADVENTURE === 🎄\n";
        omnyCardChallenge();
        if (hasOmnyCard) {
            routeNavigator();
            if (hasNavigated) {
                giftWrappingChallenge();
                exitFinder();
            }
        }
    }

    void startBicycleAdventure() {
        cout << "\n🚴 === BICYCLE ADVENTURE === 🚴\n";
        daredevilStunt();
        trafficWeave();
        trickShowdown();
    }

    void startForestAdventure() {
    cout << "\n🌲 === ADIRONDACK FOREST ADVENTURE === 🌲\n";


        caveEscape();
        if (escapedCave) {
            snakeEscape();
            if (survivedSnake) {
                beehiveEscape();
                if (escapedBeehive) {
                    bearEscape();
                    if (escapedBear) {
                        jungleNavigation();
                    }
                }
            }
        }
    }

    void displayFinalResults() {
        cout << "\n🎉 === FINAL GAME RESULTS === 🎉\n";
        displayStatus();
        cout << "Congratulations on completing the game! Your total score is: " << score << endl;
    }

private:
    void omnyCardChallenge() {
        vector<string> steps = {
            "Which button do you press first? (info/start/menu)",
            "What type of card do you want? (single/weekly/monthly)",
            "How much money to insert? ($2.90/$3.50/$4.00)",
            "Where to insert money? (slot1/slot2/slot3)",
            "Which verification button? (green/red/blue)",
            "Where to collect card? (left/center/right)",
            "Final step - activate card where? (top/bottom/side)",
            "Select payment method (cash/card/coins)",
            "Confirm purchase? (yes/no/cancel)"
        };

        vector<string> correctAnswers = {"start", "single", "2.90", "slot2", "green", "center", "top", "card", "yes"};

        for (int i = 0; i < steps.size(); i++) {
            displayStatus();
            cout << steps[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 10;
                energy -= 5;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 10;
                money -= 1;
                i--;
            }

            if (money <= 0) {
                cout << "🎁 A kind stranger helps you with some spare change!\n";
                money += 10;
            }
        }

        cout << "🎉 You successfully obtained the OMNY card!\n";
        hasOmnyCard = true;
        score += 50;
        inventory.push_back("OMNY Card");
    }

    void routeNavigator() {
        vector<string> questions = {
            "You're at the entrance. Which direction? (left/right/straight)",
            "Follow which sign? (green/red/blue)",
            "Which way to the 6? (uptown/downtown)",
            "Intersection: Follow which line? (4/5/6)",
            "Take which staircase? (left/right)",
            "Platform signs: Which side? (local/express)",
            "6 Train direction? (north/south)",
            "Preferred car position? (front/middle/back)",
            "Waiting spot? (pillar/open space/stairs)"
        };

        vector<string> correctAnswers = {"right", "green", "uptown", "6", "left", "local", "north", "middle", "stairs"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 15;
                energy -= 5;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 10;
                i--;
            }
        }

        cout << "🎉 You successfully navigated to the 6 Train platform!\n";
        hasNavigated = true;
        score += 50;
    }

    void giftWrappingChallenge() {
        vector<string> questions = {
            "Wrapping paper color? (red/green/gold)",
            "Ribbon type? (satin/velvet/sparkly)",
            "Bow style? (classic/fancy/simple)",
            "Gift tag design? (santa/tree/star)",
            "Corner folding style? (triangle/diagonal/square)",
            "Tape placement? (visible/hidden)",
            "Final decoration? (sticker/charm/none)",
            "Box size? (small/medium/large)",
            "Tissue paper color? (white/silver/gold)"
        };

        vector<string> correctAnswers = {"red", "sparkly", "classic", "star", "triangle", "hidden", "sticker", "medium", "silver"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 20;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 All gifts wrapped beautifully!\n";
        score += 75;
    }

    void exitFinder() {
        vector<string> questions = {
            "Which exit sign to follow? (1/2/3)",
            "Correct escalator? (up/down/stationary)",
            "Correct turnstile? (emergency/regular/special)",
            "Exit direction? (northwest/northeast/southwest)",
            "Which street exit? (42nd/43rd/44th)",
            "Exit side? (east/west)",
            "Final door type? (revolving/regular/emergency)",
            "Crossing signal? (walk/don't walk/flashing)",
            "Exit path? (main/side/emergency)"
        };

        vector<string> correctAnswers = {"2", "up", "regular", "northeast", "43rd", "east", "regular", "walk", "main"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 25;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 10;
                i--;
            }
        }

        cout << "🎉 You successfully exited the station!\n";
        score += 100;
    }

    void daredevilStunt() {
        vector<string> questions = {
            "Stunt to perform? (wheelie/flip/360)",
            "Ramp type? (wood/metal/concrete)",
            "Landing style? (smooth/bounce/side)",
            "Outfit color? (red/black/blue)",
            "Helmet style? (aero/full-face/open)",
            "Stunt difficulty? (easy/medium/hard)",
            "Crowd location? (square/park/path)",
            "Finishing move? (wave/salute/spin)"
        };

        vector<string> correctAnswers = {"360", "metal", "smooth", "red", "full-face", "hard", "square", "spin"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 20;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Daredevil stunts complete!\n";
    }

    void trafficWeave() {
        vector<string> questions = {
            "Direction? (left/right/straight)",
            "Speed? (slow/medium/fast)",
            "Vehicle to avoid? (car/truck/bike)",
            "Pedestrian signal? (walk/don't walk/wait)",
            "Time of day? (morning/afternoon/evening)",
            "Side of street? (left/right/middle)",
            "Weather condition? (clear/rainy/foggy)",
            "Bike gear? (low/medium/high)"
        };

        vector<string> correctAnswers = {"left", "medium", "truck", "walk", "morning", "right", "clear", "medium"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 15;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Traffic weave complete!\n";
    }

    void trickShowdown() {
        vector<string> questions = {
            "Trick? (manual/tailwhip/barspin)",
            "Landing spot? (ramp/ground/hill)",
            "Rival's move? (spin/flip/jump)",
            "Jump height? (low/medium/high)",
            "Pedal type? (flat/clip-on/spiked)",
            "Crowd cheer level? (low/medium/high)",
            "Rival reaction? (jealous/angry/amazed)",
            "Celebration move? (wave/bow/cheer)"
        };

        vector<string> correctAnswers = {"tailwhip", "ramp", "jump", "high", "clip-on", "high", "amazed", "bow"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 25;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Trick showdown complete!\n";
    }

    void caveEscape() {
        vector<string> questions = {
           "You see items: rope, stick, torch. What do you pick? (a) Rope, (b) Stick, (c) Torch",
  "Solve this riddle to light the torch: What has keys but can't open locks? (a) Keyboard, (b) Map, (c) Chest",
  "Where do you search for the map? (a) Under rocks, (b) Inside planks, (c) Look elsewhere","Two paths: (a) Left (dark/quiet), (b) Right (bright/noisy). Which do you take?",
  "Path blocked by rocks. Use: (a) Hands, (b) Rope, (c) Pickaxe",
   "You see a pit ahead. Do you: (a) Jump, (b) Look for a plank, (c) Go back?","The wall has symbols. Which do you touch? (a) Star, (b) Sun, (c) Moon","What gets wetter as it dries? (a) Sponge, (b) Towel, (c) Water","Follow faint light or sounds? (a) Light, (b) Sounds"

  };

        vector<string> correctAnswers = { "torch","keyboard","inside planks","left","pickaxe","look for a plank","sun","water","towel","light"
        };

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 15;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Cave escape complete!\n";
        escapedCave = true;
    }

    void snakeEscape() {
        vector<string> questions = {
            "You see items: rope, stick, tree. What do you pick? (a) Rope, (b) Stick, (c) Tree",
      "The lowest branch is out of reach. What do you do? (a) Jump to grab it, (b) Use a stick to pull it down, (c) Look for a nearby rock",
      "You start climbing, but the branch is slippery. How do you hold on? (a) Wrap both arms around it tightly, (b) Grip with just your hands, (c) Use your legs to secure yourself",
      "The snake is getting closer! What’s your next move? (a) Climb higher quickly, (b) Stay still and hope it loses interest, (c) Throw something at the snake",
      "You step on a branch, and it starts to crack. What do you do? (a) Jump to the next branch, (b) Move back to a stronger branch, (c) Hold still and hope it doesn’t break",
      "You see a safe spot below. What do you do? (a) Jump down and run to safety, (b) Wait for the snake to leave, (c) Shout to scare it away"
        };

        vector<string> correctAnswers = { "tree",  // You pick the tree to climb
      "look for a nearby rock",  // To reach the branch
      "wrap both arms around it tightly",  // To hold on
      "climb higher quickly",  // To escape the snake
      "move back to a stronger branch",  // To avoid breaking the branch
      "jump down and run to safety" };
       

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 15;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Snake escape complete!\n";
        survivedSnake = true;
    }

    void beehiveEscape() {
        vector<string> questions = {
            "You spot a beehive ahead. What do you do first? (a) Walk quietly, (b) Run past it, (c) Throw a rock at it",
      "The path splits into two: (a) A narrow trail closer to the hive, (b) A longer trail away from the hive. Which do you choose?",
      "A bee starts hovering near you. What do you do? (a) Swat it away, (b) Stay calm and still, (c) Run fast",
      "You see flowers near the hive. Do you: (a) Pick the flowers, (b) Stay far away, (c) Step on them accidentally",
      "A swarm starts buzzing louder. Do you: (a) Hide behind a tree, (b) Crouch and stay still, (c) Wave your hands to scare them off",
      "You reach a clearing, but a bee is following you. Do you: (a) Keep walking calmly, (b) Run to the nearest bush, (c) Lie down flat"
        };

        vector<string> correctAnswers =  {"walk quietly",  // To avoid disturbing the bees
      "a longer trail away from the hive",  // To stay safe
      "stay calm and still",  // To avoid provoking the bee
      "stay far away",  // To avoid attracting the swarm
      "crouch and stay still",  // To avoid triggering a chase
      "keep walking calmly"  // To avoid alarming the bee further;
        };

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 15;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Beehive escape complete!\n";
        escapedBeehive = true;
    }

    void bearEscape() {
        vector<string> questions = {
            "You see the bear charging! What do you do first? (a) Scream, (b) Run immediately, (c) Stay still",
      "The path splits into two: (a) A rocky uphill trail, (b) A flat open field. Which do you take?",
      "A fallen tree blocks your path. Do you: (a) Jump over it, (b) Crawl under it, (c) Go around it?",
      "You spot a river ahead. Do you: (a) Swim across, (b) Run along the bank, (c) Look for a bridge?",
      "The bear is gaining on you! How do you increase your speed? (a) Drop your backpack, (b) Take longer strides, (c) Zigzag to confuse it",
      "You reach a steep hill. Do you: (a) Climb up, (b) Slide down, (c) Stay and hide?",
      "The bear seems distracted by something. Do you: (a) Keep running, (b) Slow down, (c) Stop to catch your breath?"
        };

        vector<string> correctAnswers = {   "run immediately",          
      "a rocky uphill trail",    
      "jump over it",            
      "look for a bridge",       
      "drop your backpack",       
      "climb up",                 
      "keep running"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 15;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Bear escape complete!\n";
        escapedBear = true;
    }

    void jungleNavigation() {
        vector<string> questions = {
           "You see a fallen tree blocking your path. Do you: (a) Jump over it, (b) Crawl under it, (c) Climb over it?",
      "There’s a large rock in your way. How do you handle it? (a) Jump over it, (b) Run around it, (c) Slide down it",
      "Thick vines hang in your way. What do you do? (a) Duck under them, (b) Grab them and swing, (c) Push them aside",
      "A narrow path opens up between two trees. What’s your move? (a) Jump through the gap, (b) Run around the trees, (c) Squeeze through",
      "There’s a large gap ahead. What do you do? (a) Jump, (b) Look for another route, (c) Stop and assess"
        };

        vector<string> correctAnswers = {"jump over it",
      "jump over it",
      "duck under them",
      "jump through the gap",
      "jump"};

        for (int i = 0; i < questions.size(); i++) {
            displayStatus();
            cout << questions[i] << endl;
            string answer;
            getline(cin, answer);

            if (answer == correctAnswers[i]) {
                score += 15;
            } else {
                cout << "❄️ Incorrect! Try again.\n";
                energy -= 5;
                i--;
            }
        }

        cout << "🎉 Jungle navigation complete!\n";
        navigatedJungle = true;
    }
};

int main() {
    Game game;

    // Subway Adventure
    game.startAdventure();

    // Bicycle Adventure
    game.startBicycleAdventure();

    // Forest Adventure
    game.startForestAdventure();

    // Display Results
    game.displayFinalResults();

    return 0;
}
