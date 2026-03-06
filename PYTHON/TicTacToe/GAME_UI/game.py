# %% [markdown]
# ##### Author: Mohamed Newir
# ##### Date: 2 March 2026
# ##### File: TicTacToe.ipynb
# ##### Description: 
#             - Implementing TicTacToe class 
#             - Ensure methods and attributes apply the game logic

# %%
# used libraries
import numpy as np # to create array to store lists of the board elements 
from enum import Enum # to create enum data types

# %%
# Enum definitions

# Board Symbols
class Symbols(Enum):
    X = "X"
    O = "O"
    EMPTY_CELL = "."
    
    
# Board State
class State(Enum):
    X_WIN = "X"
    O_WIN = "O"
    IN_GOING = "IN_GOING"
    TIE = "TIE"
    

# %%
class TicTacToe:
    """
    TicTacToe Class implementing the game logic
    """
    # TicTacToe constructor
    def __init__(self):
        """
        Initialize TicTacToe Attributes
        """        
        self.__board = np.full((3, 3), Symbols.EMPTY_CELL.value)
        
        self.__player1 = " "
        self.__player1Choice = " "
        self.__player1Turn = " "
        
        self.__player2 = " "
        self.__player2Choice = " "
        self.__player2Turn = " "
        
        self.__playerMap = {}
        
    # Getter Method for board
    @property
    def board(self):
        """
        Return Board Data
        """
        return self.__board
    
    # Setter method for board
    def __setBoard(self, symbol : Symbols, pos : tuple): 
        """
        Set Board Values
        """
        row, col = pos
        self.__board[row][col] = symbol
                            
        
    # player 1 getter method 
    @property
    def player1(self):
        """
        Return Player 1 Name
        """
        return self.__player1
        
    # Player 1 setter method
    @player1.setter
    def player1(self, player1):
        """
        Set Player 1 Name
        """
        self.__player1 = player1
    
    # player 2 getter method 
    @property
    def player2(self):
        """
        Return Player 2 Name
        """
        return self.__player2
    
    # Player 2 setter method
    @player2.setter
    def player2(self, player2):
        """
        Set Player 2 Name
        """
        self.__player2 = player2
    
    def __is_completed(self):
        """
        Method Check If the Game Completed
        """
        count_X = 0
        count_Y = 0
        
        # Check Horizontal Rows
        for row in range(3):
            for col in range(3):
                if(self.board[row][col] == State.X_WIN.value):
                    count_X +=1
                if(self.board[row][col] == State.O_WIN.value):
                    count_Y +=1

            if count_X == 3:
                return State.X_WIN.value
            elif count_Y == 3:
                return State.O_WIN.value
            else:
                count_X = 0
                count_Y = 0
                
        # Check Vertical Columns
        for col in range(3):
            for row in range(3):
                if(self.board[row][col] == State.X_WIN.value):
                    count_X +=1
                if(self.board[row][col] == State.O_WIN.value):
                    count_Y +=1

            if count_X == 3:
                return State.X_WIN.value
            elif count_Y == 3:
                return State.O_WIN.value
            else:
                count_X = 0
                count_Y = 0
        
        
        # check descending lines  
        if self.__board[0][0] == self.__board[1][1] == self.__board[2][2]:
        
            if self.__board[0][0] == Symbols.X.value:
                return State.X_WIN.value

            elif self.__board[0][0] == Symbols.O.value:
                return State.O_WIN.value
            
        # check ascending lines  
        if self.__board[2][0] == self.__board[1][1] == self.__board[0][2]:
        
            if self.__board[2][0] == Symbols.X.value:
                return State.X_WIN.value

            elif self.__board[2][0] == Symbols.O.value:
                return State.O_WIN.value
            
        # check tie
        if "." not in self.__board:
            return State.TIE.value
                    
        # Game is not completed
        return State.IN_GOING.value
            
    # UI -Console- Main Game
    
    # Method to set players
    def __setPlayers(self): 
        """
        Method Set Players Name and Symbol Choice
        """
        self.player1 = input("Enter 1st Player Name: ")
        self.player2 = input("Enter 2nd Player Name: ")
        
        self.__player1Choice = ""

        while self.__player1Choice not in ["X", "O"]:
                self.__player1Choice = input(f"Enter {self.__player1} Choice X or O: ").upper()
                
        self.__player2Choice = "O" if self.__player1Choice == "X" else "X"
        
        # print(f"{self.__player1} Choice: {self.__player1Choice}, {self.__player2} Choice: {self.__player2Choice}")
        
        turn = input("Who Should Start? [Enter Player Name Only] ")
        if turn == self.player1 :
            self.__player1Turn = "1st"
            self.__player2Turn = "2nd"   
            
        else:
            self.__player1Turn = "2nd"
            self.__player2Turn = "1st"      
            
        self.__playerMap.update({
                                self.__player1 : (self.__player1Choice, self.__player1Turn), 
                                self.__player2 : (self.__player2Choice, self.__player2Turn)
                                })
            
    # Method to show players
    def __showPlayers(self):
        """
        Method show the players
        """
        for index, (player, (choice, turn)) in enumerate(self.__playerMap.items()):
            print(f"Player{index}: {player}, Choice: {choice}, Turn: {turn}")
    
    # Method to show the board
    def __showBoard(self):
        """
        Method Show Board
        """
        for row in range(len(self.__board)):
            for col in range(len(self.__board[row])):
                print(self.__board[row][col], end = " ") 
            print('\n')
        
        # print("\n")
            
    # Game Logic
    def game(self):
        """
        Applying The Game Logic
        """
        
        while 1 :
            
            header =    """
                            ### TicTacToe Game
                        """
            print(header)  
            
            
            self.__setPlayers()      
            self.__showPlayers()      
            self.__showBoard() # Show Initial Board
            
            # Game Starting
            for moves in range(3*3):
                
                
                # Set Players Turns
                if moves % 2 == 0:
                    
                    if self.__playerMap[self.__player1][1] == "1st":   
                        pos = tuple(map(int, input(f"{self.__player1}, Enter your next move! (x,y) ").split(",")))
                        self.__setBoard(self.__playerMap[self.__player1][0], pos)       
                            
                    else:
                        pos = tuple(map(int, input(f"{self.__player2}, Enter your next move! (x,y) ").split(",")))
                        self.__setBoard(self.__playerMap[self.__player2][0], pos) 
                        
                else:
                    
                    if self.__playerMap[self.__player1][1] == "2nd":   
                        pos = tuple(map(int, input(f"{self.__player1}, Enter your next move! (x,y) ").split(",")))
                        self.__setBoard(self.__playerMap[self.__player1][0], pos)       
                            
                    else:
                        pos = tuple(map(int, input(f"{self.__player2}, Enter your next move! (x,y) ").split(",")))
                        self.__setBoard(self.__playerMap[self.__player2][0], pos) 
                
                self.__showBoard() # Show Board After Each Move
                
                # Check Game Status
                status =  self.__is_completed() 
                
                if status == State.TIE.value:
                    print("Tie!!")
                    break
                
                elif status == State.O_WIN.value:
                    
                    if self.__player1Choice == State.O_WIN.value:
                            print(f"Congratulation, {self.__player1}!!")
                            
                    else:
                            print(f"Congratulation, {self.__player2}!!")
                            
                    break
                            
                elif status == State.X_WIN.value:
                    
                    if self.__player1Choice == State.X_WIN.value:
                            print(f"Congratulation, {self.__player1}!!")
                            
                    else:
                            print(f"Congratulation, {self.__player2}!!")
                    
                    break
                
            
            anotherGame = input("Wanna Play Another Game ? [y/n] ").upper()
            
            if anotherGame == "N":
                print("Exiting The Game .....")
                break
        
            self.__board = np.full((3, 3), Symbols.EMPTY_CELL.value)
# %%
if __name__ == '__main__':
    try:
        game = TicTacToe()
        game.game()
    except KeyboardInterrupt:
        pass

