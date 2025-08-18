class vectors:
    def __init__ (self,x,y,z):
        self.x = x
        self.y = y
        self.z = z
    def __str__(self) :
        return f"{self.x}i + {self.y}j + {self.z}k"
    def __add__(self,v2):
        return vectors(self.x + v2.x, self.y + v2.y, self.z + v2.z)
    
v1 = vectors(2,3,4)
print(v1)

v2 = vectors(5,6,2)
print(v2)

v3 = v1 + v2
print(v3)