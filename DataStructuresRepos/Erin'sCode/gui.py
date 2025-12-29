# Name: Ahmed Kiel-Kamil
import tkinter as tk
import random

def play_game():
    """Handle the game logic when the user clicks the Play button."""
    user_choice = choice_var.get()

    # If nothing selected, show a simple message in the result label
    if user_choice == "":
        result_label.config(text="Please select Rock, Paper, or Scissors first.")
        computer_choice_label.config(text="Computer's choice: ---")
        return

    # Computer randomly picks one of the three options
    options = ["Rock", "Paper", "Scissors"]
    computer_choice = random.choice(options)

    # Show computer's choice in the GUI
    computer_choice_label.config(text=f"Computer's choice: {computer_choice}")

    # Decide the winner
    if user_choice == computer_choice:
        result_text = "It's a tie!"
    elif (
        (user_choice == "Rock" and computer_choice == "Scissors") or
        (user_choice == "Paper" and computer_choice == "Rock") or
        (user_choice == "Scissors" and computer_choice == "Paper")
    ):
        result_text = "You win!"
    else:
        result_text = "Computer wins!"

    # Show result in the GUI
    result_label.config(text=result_text)


# ----------------- GUI SETUP -----------------

# Create the main window
root = tk.Tk()
root.title("Rock Paper Scissors")

# Variable that will hold the user's radio button selection
choice_var = tk.StringVar(value="")  # start with no selection

# Instruction label
instruction_label = tk.Label(root, text="Choose Rock, Paper, or Scissors:")
instruction_label.pack(pady=10)

# Radio buttons for the user's choice
rock_radio = tk.Radiobutton(root, text="Rock", value="Rock", variable=choice_var)
paper_radio = tk.Radiobutton(root, text="Paper", value="Paper", variable=choice_var)
scissors_radio = tk.Radiobutton(root, text="Scissors", value="Scissors", variable=choice_var)

rock_radio.pack()
paper_radio.pack()
scissors_radio.pack()

# Play button
play_button = tk.Button(root, text="Play", command=play_game)
play_button.pack(pady=10)

# Label to show the computer's choice
computer_choice_label = tk.Label(root, text="Computer's choice: ---")
computer_choice_label.pack(pady=5)

# Label to show the result
result_label = tk.Label(root, text="Result will appear here.")
result_label.pack(pady=5)

# Start the main event loop
root.mainloop()

# 1. Create the main window using tkinter.
# 2. Add three radio buttons so the user can choose Rock, Paper, or Scissors.
# 3. Add a "Play" button that will:
#       a. Read the user's choice from the radio buttons.
#       b. Randomly choose Rock, Paper, or Scissors for the computer.
#       c. Compare the two choices to decide if the user wins, loses, or ties.
#       d. Update labels on the screen to show the computer's choice and the result.
# 4. Keep the window open so the user can play as many times as they want.