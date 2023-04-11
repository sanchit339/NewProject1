
Class Node:
    Def __init__(self,data,level,fval):
        “”” Initialize the node with the data, level of the node and the calculated fvalue “””
        Self.data = data
        Self.level = level
        Self.fval = fval

    Def generate_child(self):
        “”” Generate child nodes from the given node by moving the blank space
            Either in the four directions {up,down,left,right} “””
        X,y = self.find(self.data,’_’)
        “”” val_list contains position values for moving the blank space in either of
            The 4 directions [up,down,left,right] respectively. “””
        Val_list = [[x,y-1],[x,y+1],[x-1,y],[x+1,y]]
        Children = []
        For I in val_list:
            Child = self.shuffle(self.data,x,y,i[0],i[1])
            If child is not None:
                Child_node = Node(child,self.level+1,0)
                Children.append(child_node)
        Return children
        
    Def shuffle(self,puz,x1,y1,x2,y2):
        “”” Move the blank space in the given direction and if the position value are out
            Of limits the return None “””
        If x2 >= 0 and x2 < len(self.data) and y2 >= 0 and y2 < len(self.data):
            Temp_puz = []
            Temp_puz = self.copy(puz)
            Temp = temp_puz[x2][y2]
            Temp_puz[x2][y2] = temp_puz[x1][y1]
            Temp_puz[x1][y1] = temp
            Return temp_puz
        Else:
            Return None
            

    Def copy(self,root):
        “”” Copy function to create a similar matrix of the given node”””
        Temp = []
        For I in root:
            T = []
            For j in i:
                t.append(j)
            temp.append(t)
        return temp    
            
    def find(self,puz,x):
        “”” Specifically used to find the position of the blank space “””
        For I in range(0,len(self.data)):
            For j in range(0,len(self.data)):
                If puz[i][j] == x:
                    Return I,j


Class Puzzle:
    Def __init__(self,size):
        “”” Initialize the puzzle size by the specified size,open and closed lists to empty “””
        Self.n = size
        Self.open = []
        Self.closed = []

    Def accept(self):
        “”” Accepts the puzzle from the user “””
        Puz = []
        For I in range(0,self.n):
            Temp = input().split(“ “)
            Puz.append(temp)
        Return puz

    Def f(self,start,goal):
        “”” Heuristic Function to calculate hueristic value f(x) = h(x) + g(x) “””
        Return self.h(start.data,goal)+start.level

    Def h(self,start,goal):
        “”” Calculates the different between the given puzzles “””
        Temp = 0
        For I in range(0,self.n):
            For j in range(0,self.n):
                If start[i][j] != goal[i][j] and start[i][j] != ‘_’:
                    Temp += 1
        Return temp
        

    Def process(self):
        “”” Accept Start and Goal Puzzle state”””
        Print(“Enter the start state matrix \n”)
        Start = self.accept()
        Print(“Enter the goal state matrix \n”)        
        Goal = self.accept()

        Start = Node(start,0,0)
        Start.fval = self.f(start,goal)
        “”” Put the start node in the open list”””
        Self.open.append(start)
        Print(“\n\n”)
        While True:
            Cur = self.open[0]
            Print(“”)
            Print(“  | “)
            Print(“  | “)
            Print(“ \\\’/ \n”)
            For I in cur.data:
                For j in i:
                    Print(j,end=” “)
                Print(“”)
            “”” If the difference between current and goal node is 0 we have reached the goal node”””
            If(self.h(cur.data,goal) == 0):
                Break
            For I in cur.generate_child():
                i.fval = self.f(I,goal)
                self.open.append(i)
            self.closed.append(cur)
            del self.open[0]

            “”” sort the opne list based on f value “””
            Self.open.sort(key = lambda x:x.fval,reverse=False)


Puz = Puzzle(3)
Puz.process()
