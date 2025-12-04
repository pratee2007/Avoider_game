# # Lane Runner

A simple console-based lane dodging game written in **C**.  
The player controls a character that moves left and right to avoid falling obstacles.  
Score increases as you successfully dodge obstacles, and difficulty rises as the game speeds up over time.

---

## 🎮 Gameplay
- Use **Left Arrow (←)** to move left.
- Use **Right Arrow (→)** to move right.
- Avoid obstacles falling from the top.
- Score increases each time an obstacle passes safely.
- Difficulty level increases every 5 points (speed gets faster).
- Game ends when the player collides with an obstacle.
- After Game Over, you can **restart** without closing the program.

---

## ✨ Features
- **Scoreboard**: Tracks your current score.
- **Difficulty Scaling**: Speed increases as score rises.
- **Restart Option**: Play again without restarting the program.
- **Simple Controls**: Just arrow keys to move.

---

## 🛠 Requirements
- Windows OS (uses `<conio.h>` and `<windows.h>`).
- A C compiler (e.g., GCC, MinGW, Turbo C).

---

## ▶️ How to Run
1. Save the code as `lane_runner.c`.
2. Compile using:
   ```bash
   gcc lane_runner.c -o lane_runner
