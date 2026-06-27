\# Wordle Clone (C++)



A console-based implementation of the popular \*\*Wordle\*\* game built using \*\*C++17\*\* and the Standard Template Library (STL). The game randomly selects a five-letter word from a dictionary and gives the player six attempts to guess it.



\---



\## Features



\- Random 5-letter word selection

\- Dictionary loading from `words.txt`

\- Six attempts per game

\- Input validation

\- Correct duplicate-letter handling

\- Colored terminal feedback

\- Replay option

\- Clean and modular implementation



\---



\## Technologies Used



\- C++17

\- Standard Template Library (STL)

\- `vector`

\- `string`

\- `unordered\_map`

\- File I/O (`ifstream`)

\- Random Number Generation (`std::mt19937`)



\---



\## Project Structure



```

Wordle/

├── wordle.cpp

├── words.txt

├── README.md

└── .gitignore

```



\---



\## Compilation



Compile using \*\*g++\*\*:



```bash

g++ wordle.cpp -std=c++17 -o wordle

```



\---



\## How to Play



1\. The program selects a random five-letter word.

2\. You have \*\*6 attempts\*\* to guess the word.

3\. After every guess:

&#x20;  - 🟩 Green = Correct letter in the correct position.

&#x20;  - 🟨 Yellow = Correct letter in the wrong position.

&#x20;  - ⬜ Gray = Letter is not present in the word.

4\. Guess the word before your attempts run out.



\---



\## Concepts Demonstrated



\- String manipulation

\- STL containers

\- Hash maps (`unordered\_map`)

\- File handling

\- Random number generation

\- Algorithms

\- Input validation

\- Modular programming



\---



\## Future Improvements



\- Colored on-screen keyboard

\- Statistics (Games Played, Win %, Streak)

\- Daily Wordle mode

\- Hard mode

\- Save/Load game statistics

\- Larger official dictionary



\---



\## Author



\*\*Rishi Trivedi\*\*

