# Oregon-Trail-Remake
 
 > Author: [Freddy Dong](https://github.com/Monker2578)

 ## Expectations
* We expect to use C++ for backend development
* We are expecting to produce a text styled rpg that has multiple checkpoints along the way
* If we have extra time, we would implement game libraries to enhance the game to become a 2D game. For example, player icons, images, and etc.
* We will utilize Scrum framework to maximize productivity and output.
* Every member of the group will contribute equally to the project.
* Every member will contribute in areas they are proficient in
* We will implement unit testing, Github project board, and utilize Github issue systems.
* The final project will be fully reviewed and each individual pull request will be examined carefully

## Input and Output
This game is a text-based RPG played entirely through the terminal. The user interacts with the program by reading men prompts and entering a number. Most user inputs will be simple menu choices such as "1" continue on the trail, "2" check supplies, "3" view the map, "4" change the pace, "5" change rations, "6" rest, "7" attempt to trade, or "8" hunt. 

The game will output text directly to the terminal. These outputs may include status updates, travel summaries, remaining supplies, current pace and ration settings and will output event descriptions, encounters, or tragedies that occur after the player's decisions.

For example, after choosing to continue on the trail, the output on th eterminal will display how many miles the party traveled, how much food was used and how much food remains. It may also trigger an event or encounter in which the user is prompted to make additional decisions that may determine the fate of their party.

## Project Description
Oregon Trail is a text style RPG in which the user plays as a wagon leader guiding a party from Independence, Missouri to the fertile Willamette Valley in Oregon in 1848-1849. This game will prompt the user to make choices as wagon leader on the journey. The user will make decisions on supplies, departure time, wagon setup, food rationing, travel pace, but will also face random encounters, tragedy, sickness and death. There are endless possibilites and opportunities for features to strain our software programming knowledge. As well as collaboration experience in a group.

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
* Dollars

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
* Camps

 > ## Phase II
## User Interface Specification
### Navigation Diagram
The navigation diagram illustrates the user flow for the Oregon Trail game. The game begins at the Game Start Title Screen and moves into Character Selection. During character selection, the player creates the 5 characters of their wagon by give each of them names. Then, the player proceed to the Starting Setup. In there, the player chooses his/her profession, traveling time choice, and the starter shop. After setup is complete, the player reaches the Status Header and Main Menu, which serves as the central hub for gameplay. 

From the main menu, the user can select options such as continue on the trail, checking supplies, viewing the map, changing pace, changing food rations, resting, or hunting for food.

Each menu option leads to a related screen or submenu. For example, checking supplies opens the wagon inventory, looking at the map opens the map interface, and hunting for food leads to a mini game with a success or failure outcome. While traveling, random events or encounters may occur, such as reaching forts or landmarks, trading, river crossings, bandit raids, delays, sickness, or death. Afer the user completes an action, event, or submenu, the game updates the player's status and returns them to the main menu so they can choose their next action. This diagram represents the overall screen navigation and decision flow the player follows throughout the game. 
><img width="4943" height="2645" alt="Navigation Diagram Oregon Trail" src="https://github.com/user-attachments/assets/74a5e14f-0dbd-4145-be04-7f7aa8350b9b" />

### Screen Layouts
Oregon Trail game is designed as a terminal-based program, all screens will be displayed through console. The player will interact with the game by reading text-based menus and entering numbered choices or typed responses (such as character names) when prompted. Most screens share a similar layout that includes a header, game information, menu options, and an input prompt.  
>Title Screen
><img width="1796" height="530" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/b48ef2cc-b903-43a6-a7e0-e0cf32a513d7" />
>Choose your Difficulty
><img width="732" height="464" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/9a75af38-3638-41b9-bebe-9bf92269981b" />
>Character Setup
><img width="1486" height="628" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/7ec635f2-e831-45f0-9d1c-608a4634fcfa" />
><img width="762" height="346" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/32a87aea-dbae-4536-a664-cea2de886f3b" />
>Status Header and Main Menu
><img width="778" height="1054" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/a51d57a1-19cc-42ca-9740-3835821e7ff0" />
>Change Pace menu
><img width="1924" height="634" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/d6113a03-e2bb-405b-b3ae-770c4adb82dd" />
>Change Rations menu
><img width="1000" height="542" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/1811ded5-334f-48fc-9a1f-e70df2ab0632" />




## Class Diagram
The class diagram represents major classes planned for the Oregon Trail game and how they interact with eachother during gameplay. The Main Menu acts as the Game Controller, as it is where the player will begin the game, view status information, change settings, check their inventory, engage with traders, initiate hunting, and traveling.

The Travel class manages the player's progress along the trail, including miles traveled, miles remaining, and food usage. It uses values from the SetSettings class, such as pace, and food rations, to determine how travel affects the party's health and food supply. Travel also updates the Wagon/Inventory class as resouces are consumed during movement.

The Wagon/Inventory class stores the player's supplies, including food, money, ammuniation, clothing, and spare parts. This class is affected by shopping, travel and random events. the Shop allows the player to purchase supplies and updates the wagon inventory.Which can happen when the party reaches forts, trading stations or encounters traders.

The Health and Character classes track the condition of each member the player's party. Each chracter has information such as name, age, health and whether they are alive. The Health class manages overall party health, rest, and party size, while events and challenges can rduce health or cause characters to die.

The Events/Challenges/Checkpoints section represents those random encounters, or planned gameplay situtations that may occur while traveling. These events may affect the player's inventory, health, travel progress, or access to shops and traders. 

Overall, this diagram shows how the main systems of the game are connected to hopefully help you understand how the Oregon Trail game is played. 
><img width="2496" height="1842" alt="Oregon Trail UML Oregon Trail" src="https://github.com/user-attachments/assets/49b7b369-534d-460d-949d-b3ff9898a1aa" />
Updated UML diagram.
<img width="2102" height="1212" alt="umltesting" src="https://github.com/user-attachments/assets/7274fe7e-1d39-4d2f-bc6f-829fbb32145e" />


 > ## Phase III

Character: For characters, I applied the SRP and the Open/Closed SOLID principles. The class is constructed so that it can be scaled anytime. Additionally, the class only handles character related issues such as the health system. This change made sure my code is easily readable and changed in reaction to future updates.

Wagon: For wagon, I applied SRP. The class is made so that the inventory and the wagon behavioral system are separated. Moreover, all functions are made so that their mechanics is clear. This change helped me make my code's structure clear and effortless to future changes.

Shop: For Shop, I applied SRP and DIP. The class is made so that it will only handle shop related mechanics (utilizing private helper functions too). Additionally, the shop only takes in a wagon reference and does not directly manipulate (owning) the wagon item. This change helped my code become clearer and less prone to errors from future object ownership conflicts.

Hunting: For the hunting system, I applied SRP, the Open/Closed, and LSP. The system is made to only handle the hunting game mechanic and is separated into classes of animal, player, and game itself. Animal (has virtual functions) is further divided into 4 subclasses. The change helped improve my code structure and make sure everything is easily scalable and still remain clear from confusion.

MainMenu: Was one giant file doing a bit of everything. (It had terminal effects and output, displayed menu, displayed a status header, it setup the title scren of the game, the initial party setup including names, it set up difficulty, and contained the rest screen. The main principle I applied was SRP. The mainMenu now only handles displaying the main menu and returning the player's choice through a menuchoice enum. It does not call travel, shop, rest, etc directly. This makes the code easier because adding or changing menu options doesnt extend outside of what the choices are within the enum and it no longer worries about calling. SRP, and Open/closed principle. 

TerminalIO (input/output) This was also SRP, the first thing was to split the terminal effects into a file with its own terminal specific utility functions such as the type writer effect, and clear screen. The main menu no longer needs to know how text is printed, delayed, or how the screen is cleared. TerminalIO can be used or prompted to include the effect to any part of the game. The effect speeds are in one place. 

StatusHeader: SRP. moved statusHeader and the related party status out of the menu and now its only responsible for showing the player's current game information, from miles, pace, rations, food, money an party health. It displays what is without worrying about the implications. 

PartySetup: SRP: Is now resonspible for creating the player's party, validating names, using preset names, an returning vector<Character>. The party creation is seperate as well as the rules within it including max name length, preset party names, and number of party members without affecting the main game loop. 

DifficultySetup: SRP & DIP. I moved difficulty/proffesion selection into its own file. The old way created its own local wagon to apply profession bonuses onto it. But in this way the setup is seperate and if we need to modify or test the professions it can be done on its own. 

Rest Screen: SRP. The rest screen is on its own like the other menu options. This one is responsible only for asking whether the player wants the wagon party to rest, choosing how many days, and healing the party. Resting is its own feature isntead of being buried inside the menu. Resting consumes food and perhaps triggers encounters, it'll be easier to manage these possibilities without touching the main menu. 

Encounters: SRP. The encounters is solely responsible for the randomization logic of the game. It determines what encounters happen as well as the logic within each encounter, i.e. event outcomes and play choices. OCP. Things are structured in a way in which events can be added without changing the existing game.

Map: SRP. It handles checkpoint data, location, and route. All of which are relevant. OCP. Checkpoints can be added without changing map logic. 
 
 > ## Final deliverable
 
 ## Screenshots
 >Title Screen
><img width="1796" height="530" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/b48ef2cc-b903-43a6-a7e0-e0cf32a513d7" />
>Choose your Difficulty
><img width="732" height="464" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/9a75af38-3638-41b9-bebe-9bf92269981b" />
>Character Setup
><img width="1486" height="628" alt="image" style="width:50%; height:auto;" src="https://github.com/user-attachments/assets/7ec635f2-e831-45f0-9d1c-608a4634fcfa" />

>Rest Menu
><img width="1476" height="870" alt="image" style="width:50%; height: auto;" src="https://github.com/user-attachments/assets/35344764-9193-41b0-bbaa-22bdb7229961" />
>Hunting
><img width="655" height="797" alt="huntimage" src="https://github.com/user-attachments/assets/3d72cb87-11fc-4e70-b2f7-5faa153a5f47" />
>Encounter
><img width="545" height="330" alt="encounter" src="https://github.com/user-attachments/assets/1cffc78e-001c-444e-88f9-1073b820053d" />
>River
><img width="397" height="457" alt="riveroptions" src="https://github.com/user-attachments/assets/8870c5a3-7112-41f6-8572-46fd5fc74776" />
<img width="406" height="291" alt="riveer choices" src="https://github.com/user-attachments/assets/d2ee38eb-ebfe-4585-a431-3a81e0f98610" />
>Shop
><img width="707" height="411" alt="shop" src="https://github.com/user-attachments/assets/c3770ccc-7c8e-4610-b7f7-82d92fb19641" />
><img width="637" height="307" alt="readytoleave" src="https://github.com/user-attachments/assets/a3378f7b-3af9-444f-a76c-93b2d032319b" />





 ## Installation/Usage
 > Download files. In VsCode run cmake and execute the ./Oregon_Trail exe.
> <img width="835" height="32" alt="installation" src="https://github.com/user-attachments/assets/2fa30a62-69dc-435f-92df-8b10ebaf3dc7" />

 ## Testing
 > We ran valgrind and unit tests
> <img width="1067" height="685" alt="test2" src="https://github.com/user-attachments/assets/aec544a7-5dd5-4f56-962a-f6c5cedf480f" />
<img width="1055" height="361" alt="test" src="https://github.com/user-attachments/assets/4cc21136-7839-4b88-9a41-ff7afd24ca49" />
<img width="771" height="227" alt="valgrind" src="https://github.com/user-attachments/assets/50cf7ee9-b319-4415-8182-a032ca22770d" />

 
