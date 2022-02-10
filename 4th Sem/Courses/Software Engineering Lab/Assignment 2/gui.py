# Importing relevant modules
from tkinter import *
import matplotlib.pyplot as plt
from matplotlib.figure import Figure 
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg,  
NavigationToolbar2Tk)
from math import sin

# Kaushal Banthia
# 19CS10039

# Class for Graphing the Equation after taking its input
class Graph:

    # Constructor
    def __init__(self):

        # Creating a new window
        self.root = Toplevel(root)

        # Setting the title for the new window
        self.root.title("Plot")

        self.eq = None
        self.st = None
        self.en = None
        self.vals = None  
        self.canvas = None
        
        # Creating Labels and Entry Boxes for the new window
        self.mylabel_equation = Label(self.root, text = "Enter equation in x")
        self.equation = Entry(self.root, borderwidth = 10)
        self.mylabel_start = Label(self.root, text = "Enter start of the range for x")
        self.start = Entry(self.root, borderwidth = 10)
        self.mylabel_end = Label(self.root, text = "Enter end of the range for x")
        self.end = Entry(self.root, borderwidth = 10)

        # Creating button to create the Graph. Calls the get_values() function on being clicked
        self.button = Button(self.root, text = "CALCULATE", padx = 30, pady = 7, command = self.get_values)

        # Calling the pack function defined by me to pack all the widgers
        self.pack()

    # Pack Function to pack all the created widgets
    def pack(self):

        # Calling pack() function on all the widgets to place them in the new window
        self.mylabel_equation.pack()
        self.equation.pack()
        self.mylabel_start.pack()
        self.start.pack()
        self.mylabel_end.pack()
        self.end.pack()
        self.button.pack()

    # The get_values() function is defined to be called when the CALCULATE button is clicked
    def get_values(self):
        
        # If the canvas exists then we destroy it
        if self.canvas != None:
            if self.canvas.get_tk_widget().winfo_exists():
                self.canvas.get_tk_widget().destroy()

        # Gets the text in the first Entry Box 
        self.eq = self.equation.get()

        # Making some changes to make it compatible with the python eval() function
        self.eq = self.eq.replace('^', '**')
        self.eq = self.eq.replace('x', '(x)')

        # Gets the text in the second Entry Box and converts it to a number
        self.st = eval(self.start.get())

        # Gets the text in the third Entry Box and converts it to a number
        self.en = eval(self.end.get())

        # list that contains the value of the evaluated expression for a range of values of x
        self.vals = []

        # Loop that evaluates the value of the expression and then append it to vals
        for i in range((self.st), int(self.en) + 1, 1):
            new_eq = self.eq.replace('x', str(i))
            self.vals.append(eval(new_eq))

        # Creating a matplotlib Figure
        fig = Figure(figsize = (5, 5), dpi = 100) 

        # adding the subplot 
        plot1 = fig.add_subplot(111) 
    
        # plotting the graph 
        plot1.plot(range(int(self.st), int(self.en) + 1, 1), self.vals)
        plot1.grid()
        # creating the canvas containing the Matplotlib Figure 
        self.canvas = FigureCanvasTkAgg(fig, master = self.root)   
        self.canvas.draw()
    
        # placing it on the Tkinter window 
        self.canvas.get_tk_widget().pack()

# Function to quit the program. Called when the Exit button is clicked
def quit():
    root.quit()

# Main Function
if __name__ == "__main__":

    # Creates the Root
    root = Tk()

    # Creates the object of the class Graph and calls its constructir
    g = Graph()

    # Creating button to quit the program. Calls the quit() function on being clicked
    button = Button(root, text = 'EXIT', command = quit, width = 15, height = 3)

    # Packing the button
    button.pack(pady=10)
    
    # The mainloop that keeps the program running
    root.mainloop()