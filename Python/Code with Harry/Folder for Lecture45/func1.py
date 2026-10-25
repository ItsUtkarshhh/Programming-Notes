def greet() : # Only defines the function!
    print("Good Morning")

print(__name__) # Will print "main" if this file runs directly! kyunki agar iss file ko run krenge toh main program ye file hai! and agar import kiya jaye iss file ko then in that case kyunki ye condition yahaa likhi hui hai isliye iss file ke __name__ variable me iss file ka name store hoga agar iss file ko kisi aur exernal file call ayega! its like, apni khud ki file run hui toh mai "main" (which refers as that this is the main program!) hoon! but agar kisi aur ne mujhe import kiya, toh mujhe ye identify krna padega na apne aap ko ki mai "func1" hoon
if __name__ == "__main__" : # Isse ye problem solve hojaati hai ki koi bahar ki file agar import kre iss file ko __name__ and __main__, match nhi krenge and hence iss condtion ke andar hum jo code likhenge vo ork nhi krega kisi aur file ke andar! This was the whole crucks!
    greet()