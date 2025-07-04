class sadMan:
    def __init__(self, name):
        self.name = name
    
    def dont(self):
        print(f"{self.name} don't be sad.")
        
someone = sadMan("Newir")
someone.dont()