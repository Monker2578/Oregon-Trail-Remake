# Oregon-Trail-Remake
 
 > Author: [Freddy Dong](https://github.com/Monker2578), Co-author: [Varun] 

 ## Expectations
* Utilization of C++ for backend development
* Expecting to produce a text styled rpg with multiple checkpoints along the way
* After first version, implement game libraries to transform the game into a 2D game. (Ex: player icons, images, and etc.)
* Utilize Scrum framework to maximize productivity and output.
* Implementation of unit testing, Github Kanban board, and Github issue systems.

## Input and Output
This game is a text-based RPG played entirely through the terminal. The user interacts with the program by reading prompts and entering decision inputs (mostly in the format of numbers and characters). For example, menu options are displayed as enter "1" continue on the trail, "2" check supplies, "3" view the map, "4" change the pace, "5" change rations, "6" rest, "7" attempt to trade, or "8" hunt. 

The game will output text directly to the terminal. These outputs may include status updates, travel summaries, remaining supplies, current pace, ration settings, event descriptions, encounters, or tragedies that occur after the player's decisions.

For example, after choosing to continue on the trail, the terminal will display how many miles the wagon traveled, how much food was used, and how much food remains. It may also trigger an event or encounter in which the user is prompted to make additional decisions that may determine the fate of their party.

## Project Description
Oregon Trail is a RPG in which the user plays as a wagon leader guiding a party from Independence, Missouri to the fertile Willamette Valley in Oregon between 1848-1849. This game will prompt the user to make choices as wagon leader on the journey. The user will make decisions on supplies, departure time, wagon setup, food rationing, travel pace, and etc. Moreover, these decisions will have an impact throughout the game and provide each run a unique experience.

Proposed features:

Map:
* Distance
* Locations
* Current position
* Routes
* Date

Character:
* Profession
* Names
* Health
* Consumption rate

Economy:
* Shops
* Food
* Trading

Encounters:
* Weather
* Bandits
* Traders

Events:
* Hunting
* River Crossing
* Berry Picking

Checkpoints:
* Forts 
* Landmarks
* Rivers

> ## User Interface Specification
### Navigation Diagram
The navigation diagram illustrates the user flow for the Oregon Trail game. The game begins at the Game Start Title Screen and moves into Character Selection. During character selection, the player creates the 5 characters of their wagon by give each of them names. Then, the player proceed to the Starting Setup. In there, the player chooses his/her profession, traveling time choice, and the starter shop. After setup is complete, the player reaches the Travel Screen and Main Menu, which serves as the central hub for gameplay. 

From the main menu, the user can select options such as continue on the trail, checking supplies, viewing the map, changing pace, changing food rations, resting, or hunting for food.

Each menu option leads to a related screen or submenu. For example, checking supplies opens the wagon inventory, looking at the map opens the map interface, and hunting for food leads to a mini game with a success or failure outcome. While traveling, random events or encounters may occur, such as reaching forts or landmarks, trading, river crossings, bandit raids, delays, sickness, or death. Afer the user completes an action, event, or submenu, the game updates the player's status and returns them to the main menu so they can choose their next action. This diagram represents the overall screen navigation and decision flow the player follows throughout the game.
><img width="3258" height="1720" alt="Navigation Diagram Oregon Trail" src="https://github.com/user-attachments/assets/5da29ee6-9889-4b18-b05d-2eda571bf720" />

### Screen Layouts
Oregon Trail game is designed as a terminal-based program, all screens will be displayed through console. The player will interact with the game by reading text-based menus and entering numbered choices or typed responses (such as character names) when prompted. Most screens share a similar layout that includes a header, game information, menu options, and an input prompt.  


## Class Diagram
The class diagram represents major classes planned for the Oregon Trail game and how they interact with eachother during gameplay. The Main Menu acts as the Game Controller, as it is where the player will begin the game, view status information, change settings, check their inventory, engage with traders, initiate hunting, and traveling.

The Date system contains the time the player is in and it is in relation with weather. The class determines the terrain and the weather that the player experiences during their journey. Moreover, the weather also has an effect on the random encounters. For example, being in march will be cold and the player might experience frostbite.

The Wagon/Inventory class stores the player's supplies, including food, money, ammuniation, clothing, and spare parts. This class is affected by shopping, travel and random events. the Shop allows the player to purchase supplies and updates the wagon inventory.Which can happen when the party reaches forts, trading stations or encounters traders.

The Map system represents the whole journey of the game. It is composed of a linked list that is initialized by parsing through a CSV file. This class allows the player to visualize their journey and give them a reference on how to manage their resources so they can make it to the end of the game. The Map system holds different locations that have different events upon the play triggering it by arriving on the location.

The Character classes track the condition of each member the player's party. Each character has information such as name, age, health and whether they are alive. The party class manages overall party health, rest, and party size, while events and challenges can reduce health or cause characters to die.

Overall, this diagram shows how the main systems of the game are connected to hopefully help you understand how the Oregon Trail game is played. 
><img width="2260" height="880" alt="image" src="https://github.com/user-attachments/assets/f4a0c8bf-193e-4a16-9b32-66874f46f44c" />


 > ## Structure Design

Character: For characters, I applied the SRP and the Open/Closed SOLID principles. The class is constructed so that it can be scaled anytime. Additionally, the class only handles character related issues such as the health system. This change made sure my code is easily readable and changed in reaction to future updates.

Wagon: For wagon, I applied SRP. The class is made so that the inventory and the wagon behavioral system are separated. Moreover, all functions are made so that their mechanics is clear. This change helped me make my code's structure clear and effortless to future changes.

Shop: For Shop, I applied SRP and DIP. The class is made so that it will only handle shop related mechanics (utilizing private helper functions too). Additionally, the shop only takes in a wagon reference and does not directly manipulate (owning) the wagon item. This change helped my code become clearer and less prone to errors from future object ownership conflicts.

Hunting: For the hunting system, I applied SRP, the Open/Closed, and LSP. The system is made to only handle the hunting game mechanic and is separated into classes of animal, player, and game itself. Animal (has virtual functions) is further divided into 4 subclasses. The change helped improve my code structure and make sure everything is easily scalable and still remain clear from confusion.

Locations: For Locations, I applied SRP and OCP. The class only stores data about a single checkpoint, such as its name, its distance from the start, and its type (fort, landmark, or river). It does not decide when the player arrives or what happens there. Because each location is its own data entry, new checkpoints can be added without changing any existing location code. This keeps the trail data in one place and out of the travel and event logic.

Map: For Map, I applied SRP and OCP. The class handles the route: the ordered list of locations, the player's current position, and the distance remaining to the next checkpoint. It does not move the wagon, consume food, or trigger events. Checkpoints can be added or reordered without changing the map logic. This keeps route tracking separate from the travel system, so changes to pacing or events never touch it.

Date/Weather: For Date/Weather, I applied SRP. The class tracks the in-game date and advances it as days pass, and it determines the current weather from the date or season. It only reports this information. How weather affects travel speed or party health is decided by the classes that read it. This keeps the time and weather rules in one place, so adjusting the calendar or adding weather types doesn't ripple through the rest of the game.
 
> ## Final deliverable
 
## Screenshots
Still in Production

## Installation/Usage
Still in Production

## Testing
Currently using unit testing and plan to add Valgrind later
