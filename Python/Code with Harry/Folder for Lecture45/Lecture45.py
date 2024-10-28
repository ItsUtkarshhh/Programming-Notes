import func1
func1.greet()

# Now lets see what happens :
# When main.py executes the line import func1, Python runs the func1.py script to load the module.
# Execution of func1.py : The print(__name__) statement in func1.py prints the value of __name__.
#                       : Since func1.py is being imported, the value of __name__ will be "func1". This value is the module’s name, not "__main__"
#                       : The if __name__ == "__main__": condition in func1.py will not be met because __name__ is "func1", not "__main__". Therefore, the greet() function inside this block will not execute.

# After importing func1, the line func1.greet() in main.py calls the greet() function from func1.py.
# This will print "Good Morning" to the console because greet() is a regular function call, unaffected by the if __name__ == "__main__": condition.

# What is __name__ and what is "__main__" :
# __name__: This is a special built-in variable in Python. It represents the name of the module (i.e., the file name without the .py extension) when the module is imported. When a module is executed directly, __name__ is set to "__main__".
# "__main__": This is a special string value used to identify the module that is being run directly. It is not the name of the file but a special marker indicating that the module is the main program being executed.

# Why use if __name__ == "__main__":
# Purpose: This construct is used to control code execution when a module is run directly versus when it is imported.
# Direct Execution: Code inside if __name__ == "__main__": block runs only when the script is executed directly. This is useful for including test code or example usage that shouldn’t run when the module is imported.
# Importing: When a module is imported, the code in the if __name__ == "__main__": block does not run, making it useful for defining functions and classes that can be used elsewhere without executing script-specific code.

# Can You Use a Different Name Instead of "__main__"?
# No, "__main__" is Special: "__main__" is a special constant in Python. You cannot use another name instead of "__main__" for this purpose. It is specifically used to determine if the module is being run as the main program.

# # In normal language :
# Jo file kisi ek file ko import kar rahi hai, vo ban jaati hai main program! Aur __name__ variable me uss file ka name nahi, balki __main__ store hota hai!
# Aur agar jo import wala module/file hai usko hi agar hum run kar de directly, tab vo wali file ab main program ban jayegi! Aur ab __name__ variable me "__main__" store hoga!
# This is the main thing, ab nextly...
# Agar hum jis file me dusri file import kar rahe hain (jaise yahaan par main.py me func1 import kar rahe hain), toh main.py wali file ab main program ban jayegi! Aur ab main.py me __name__ me "__main__" store hoga.
# Isliye, ab jab main.py ko execute karenge toh print(__name__) me "__main__" print hoga. Aur agar importing module/file func1 ko directly run kar denge, toh __name__ me "__main__" store hoga aur isko run karne par print(__name__) me "__main__" print hoga!
# Lekin, agar hum func1.py ko import karte hain (jaise main.py me import func1), toh func1.py me print(__name__) "func1" print karega, kyunki func1.py ko import kiya gaya hai, run nahi kiya directly.

# More Clear Summary (Final) :
# Addition to that, what I am understanding is, that ki jahaa pr ye condition likhi hui hai and agar uss hi file ko run krenge directly, then vo file bn jayegi main program! and __name__ me "__main__" store hojayega, jo iss baat ko refer krega ki ye main program hai!
# and agar kisi aur file me import krenge iss file ko, then uss case me kyunki ye condition uss file me likhi thi isliye __name__ me uss file ka nam store hojayega! and due to which ab, __name__ me uss file ka naam hai and ab main program ye current file hai! isliye, iss baar vo condition match nhi kregi and isliye program execute nhi hoga!

# Agar hum kisi file ko import kr rhe hai jisme hume shak hai ki kuch aise functions ho sakte hai jo sirf import krne execute hojayenge! toh in that case, we shoudl be careful with that! jaise yahaa pr ho rha tha, jaise greet() bahar likha tha uss condition ke toh vo sirf import krne pr hi execute ho jaa rha tha and same with print(__name__), toh isliye modules ko import dhyaan se krna chahiye! and jab khud module banao toh usme ye condition lagao taaki koi aur usko import kre toh vo safe rahe!
# kyunki maanlo tumhare kisi dost ne ek file/module banaya and kahaa tumko ki import kro, and uss file me aise kuch functions hai jo call ho rakhe hai already without this condition, and vo functions kuch aise functions hai jo tumhare computer ki files ko delete bhi kr sakte hai, toh in that case, it will create trouble for you! as python is capable of doing many things with your computer!

