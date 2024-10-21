# BrainBuster

**BrainBuster** is a fun and interactive pop quiz game where you answer five riddle-style questions. For each question, you will be given multiple options, and you need to select the correct answer to score points. It's a great way to test your brainpower!

## How to Play

- The game consists of **5 questions**.
- Each question will have **numbered options** from which you need to select the correct answer.
- After selecting an option by entering the corresponding number, the game will let you know if your answer is correct.
- The game continues through all 5 questions.
- At the end of the game, your score is displayed based on how many correct answers you provided.

## Questions and Categories

- All the questions in **BrainBuster** are riddles.

## Game Flow

- The game will not stop after a wrong answer. It continues until all 5 questions are answered.
- Once all questions are answered, the game will display your total score based on the number of correct answers.

## Compilation Instructions

To compile and run the game, use the provided `Makefile` with the following commands:

1. **Compile for regular use:**

   ```bash
   make
   ```

   This will compile the game and create an executable in the `build` directory called `BrainBuster`.

2. **Compile with strict error checking (production mode):**

   ```bash
   make prod
   ```

   This command includes extra warnings and treats them as errors for stricter compilation.

3. **Run the game:**

   ```bash
   make run
   ```

   This will run the `BrainBuster` game executable after compiling it.

4. **Clean build artifacts:**
   ```bash
   make clean
   ```
   This command will clean up the compiled files and remove the build directory.

## Dependencies

- No external dependencies are required to compile or run this project.
- You only need a C compiler (such as GCC) installed on your system.

## Folder Structure

```
.
├── build               # Directory for the compiled executable
│   └── BranBuster.exe  # The game executable after compilation
├── lib                 # Library folder containing the core game logic
│   ├── questions.c     # Question-related logic
│   ├── questions.h     # Header file for questions
│   ├── utility.c       # Utility functions used in the game
│   └── utility.h       # Header file for utility functions
├── main.c              # Main entry point for the game
├── Makefile            # Makefile for compiling the project
└── .gitignore          # Git ignore file
```

## Contribution Guidelines

This project is a **college assignment**, and therefore, no contributions or pull requests are being accepted at this time.

## License

This project is for academic purposes, so no formal license is provided.
